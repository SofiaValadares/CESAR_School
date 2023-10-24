#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/wait.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h> 
#include <libgen.h> 


const char * pathBin = "bin";
const char *stylePath = "bin/style.txt";

char *style;
int bg = 1;

void removerEspaco(char **token); 

int argsInterativo(char ****args, int ind_args);
void argsBarch(char ****args, char *nome_arquivo);

void styleTroca(char *arg);
int tamArryArgs(char **args);

void imprimirArgs(char **args);

void comands(char **args);

void historry(char ****args, int tam_args);

void criarBin();
void escreverStyleAquivo(char *escrita);
char *lerArquivoStyle();

int main(int argc, char *argv[]) { 
    criarBin();
    escreverStyleAquivo("seq");

    char ***args = NULL;
    int ind_args = 0;

    if (argc == 1) {
        // MODO INTERATIVO
        while (1) {
            style = lerArquivoStyle();

            printf("svc3 %s> ", style);

            if (argsInterativo(&args, ind_args)) {
                historry(&args, ind_args);

                comands(args[ind_args]);

                ind_args++;
            }
            
        }

            
    } else if (argc == 2) {
        // MODO BATCH
        argsBarch(&args, argv[1]);

        while (1) {
            style = lerArquivoStyle();

            printf("svc3 %s> ", style);
            imprimirArgs(args[ind_args]);

            historry(&args, ind_args);

            comands(args[ind_args]);

            ind_args++;
        }
    } else {
        fprintf(stderr, "Error - Número incorreto de argumentos passado. Finalizando programa.....\n");
        sleep(2);
        exit(1);
    }
    

    return 0;
}

void criarBin() {
    int status = mkdir(pathBin, 0777);

    if (status != 0) {
        return;
    }
}

char *binPath(char *nome_arquivo) {
    int tan_ = strlen(nome_arquivo) +5;

    char *arquivo = (char*)malloc(tan_*sizeof(char));
    snprintf(arquivo, tan_, "%s/%s", pathBin, nome_arquivo);

    return arquivo;
}

char *buscarPathArquivo(char *nome_arquivo) {
    char *arquivo = malloc(PATH_MAX + 1);

    if (arquivo != NULL) {
        if (realpath(nome_arquivo, arquivo) != NULL) {
            return arquivo;
        } 
    }

    return nome_arquivo;
}

void escreverStyleAquivo(char *escrita) {
    FILE *f = fopen(stylePath, "w");

    if (f == NULL) {
        perror("Erro ao abrir o arquivo, vc venceu, bugou meu style");
        exit(1);
    }

    fprintf(f, "%s", escrita);
    fclose(f);
}

char *lerArquivoStyle() {
    FILE *f = fopen(stylePath, "r");
    if (f == NULL) {
        fprintf(stderr, "Error: style - erro ao abrir arquivo style.txt\n");
        return "seq";
    }
    

    char *escrita = (char*)malloc(4*sizeof(char));

    if (fgets(escrita, 4, f) == NULL) {
        strcpy(escrita, "seq");
    }

    fclose(f);

    return escrita;
}

int tamArryArgs(char **args){
    int i = 0;

    while (args[i] != NULL) {
        i++;
    }

    return i;
}

void historry(char ****args, int ind){
    int i = 0;

    while ((*args)[ind][i] != NULL) {
        if (strcmp("!!", (*args)[ind][i]) == 0) {
            if (i == 0) {
                if (ind == 0) {
                    return;
                }
            
                int tam_array = tamArryArgs((*args)[ind-1]);
                int tam = strlen((*args)[ind-1][tam_array-1]) + 1;

                (*args)[ind][i] = (char*)realloc((*args)[ind][i], tam*sizeof(char));
                strcpy((*args)[ind][i], (*args)[ind-1][tam_array-1]);
            } else {
                int tam = strlen((*args)[ind][i-1]) + 1;
                (*args)[ind][i] = (char*)realloc((*args)[ind][i], tam*sizeof(char));
                strcpy((*args)[ind][i], (*args)[ind][i-1]);
            }
        }

        i++;
    }
}

char *linhaInterativo() {
    char *linha = NULL;
    int i = 0;
    int ch;

    while (1) {
        ch = getc(stdin);
        if (ch == EOF) {
            // Caso Ctrl+D
            if (i == 0) { 
                linha = (char*)malloc(4*sizeof(char));
                printf("exit\n");
                strcpy(linha, "exit");
            } else {
                removerEspaco(&linha);
                i = strlen(linha);
                
                if (linha[i-1] != ';') { 
                    linha = (char *)realloc(linha, (i+8)*sizeof(char));
                    printf("; exit\n");
                    strcat(linha, "; exit");
                } else {
                    linha = (char *)realloc(linha, (i+6)*sizeof(char));
                    printf("exit\n");
                    strcat(linha, "exit");
                }
            }
            break;
        } else if (ch == '\n') {
            if (linha == NULL) {
                return NULL;
            }

            linha[i] = '\0';
            break;
        } else {
            if (linha == NULL) {
                linha = (char*)malloc(sizeof(char));
            }

            linha[i] = (char)ch;
            i++;

            linha = (char *)realloc(linha, (i+1)*sizeof(char));

            /*if (i >= tamanho) {
                tamanho = 1; 
                linha = (char *)realloc(linha, tamanho * sizeof(char));
                if (linha == NULL) {
                    fprintf(stderr, "Erro de alocação de memória na linha\n");
                    return NULL;
                }
            }*/
        }
    }

    removerEspaco(&linha);

    if (linha[0] == '\0') {
        return NULL;
    }

    return linha;
}

void styleTroca(char *arg) {
    if (strcmp("style parallel", arg) == 0) {
        escreverStyleAquivo("par");
        free(style);

        style = lerArquivoStyle();
    } else if (strcmp("style sequential", arg) == 0) {
        escreverStyleAquivo("seq");
        free(style);

        style = lerArquivoStyle();     
    }
}

char *linhaBatch (FILE *f) {
    char *linha = (char*)malloc(251*sizeof(char));

    if (fgets(linha, 251, f) == NULL) {
        if (feof(f)) {
            strcpy(linha, "exit");
            return linha;
        } else {
            return NULL;
        }
        
    }

    int tam = strlen(linha);
    if (tam > 0 && linha[tam - 1] == '\n') {
        linha[tam - 1] = '\0';
    }

    return linha;
}

int lerBatch(char *nome_arquivo, char ***input) {
    int tam_input = 0;
    FILE *f = NULL;

    f = fopen(nome_arquivo, "r");

    if (f == NULL) {
        fprintf(stderr, "Error - Não foi possivel abrir o arquivo %s. Finalizando programa.....\n", nome_arquivo);
        exit(1);
    }

    char *linha;

    while ((linha = linhaBatch(f)) != NULL) {
        if (linha[0] != '\0') {
            if (*input == NULL) {
                tam_input++;
                *input = (char**)malloc(sizeof(char*));
            } else {
                tam_input++;
                *input = (char**)realloc(*input, tam_input * sizeof(char*));
            }

            (*input)[tam_input - 1] = strdup(linha);

            if (strstr(linha, "exit")) {
                break;
            }
        }
    }

    fclose(f);

    return tam_input;
}

void removerEspaco(char **token) {
    int len = strlen(*token);

    while (len > 0 && ((*token)[0] == ' ' || (*token)[0] == '\t')) {
        (*token)++;
        len--;
    }

    while (len > 0 && ((*token)[len-1] == ' ' || (*token)[len-1] == '\t')) {
        len--;
    }

    (*token)[len] = '\0';
}

int arrayArgs(char *linha, char ***args) {
    int i = 0;

    char *token = strtok(linha, ";");

    while (token != NULL && token[0] != '\0') {
        if (*args == NULL) {
            *args = (char**)malloc(sizeof(char*));
        } else {
            *args = (char**)realloc(*args, (i+1)*sizeof(char*));
        }

        removerEspaco(&token);
        (*args)[i] = strdup(token);
        (i)++;
        token = strtok(NULL, ";");
    }

    return i;
}

void liberarArgs(char **args, int tan_args) {
    for (int i = 0; i < tan_args; i++) {
        free(args[i]); 
    }
}

int argsInterativo(char ****args, int ind_args) {
    char *input = linhaInterativo();

    if (input != NULL) {
        if (*args == NULL) {
            *args = (char***)malloc(sizeof(char**));
        } else {
            *args = (char***)realloc((*args), (ind_args+1)*sizeof(char**));
        }

        char **args_linha = NULL;
        int tam_args = arrayArgs(input, &args_linha);

        (*args)[ind_args] = (char**)malloc((tam_args+1)*sizeof(char*));

        for (int i = 0; i < tam_args; i++) {
            (*args)[ind_args][i] = strdup(args_linha[i]);
        }

        (*args)[ind_args][tam_args] = NULL;

        free(input);
        liberarArgs(args_linha, tam_args);
        return 1;

    } else {
        return 0;
    }
}

void argsBarch(char ****args, char *nome_arquivo) {
    char **input = NULL;
    int tam_input = lerBatch(nome_arquivo, &input);

    (*args) = (char***)malloc(tam_input*sizeof(char**));

    for (int i = 0; i < tam_input; i++) {
        char **args_linha = NULL;
        int tam_args = arrayArgs(input[i], &args_linha);

        (*args)[i] = (char**)malloc((tam_args+1)*sizeof(char*));

        for (int j = 0; j < tam_args; j++) {
            (*args)[i][j] = strdup(args_linha[j]);
        }

        (*args)[i][tam_args] = NULL;
    } 
}

void imprimirArgs(char **args) {
    int i = 0;
    while (args[i+1] != NULL) {
        printf("%s; ", args[i]);
        i++;
    }

    if (args[i] != NULL){
        printf("%s\n", args[i]);
    }
}

void seqPadrao(char *arg) {
    pid_t pib;

    pib = fork();

    if (pib < 0) {
        fprintf(stderr, "Error - erro no fork pib");
        return;
    } else if (pib == 0) {
        //Processo filho
        char arg_path[2001];

        if (realpath(arg, arg_path) == NULL) {
            execl("/bin/sh", "sh", "-c", arg, NULL);
        } else {
            execl(arg_path, arg, NULL);
        }

        exit(0);
    } else {
        //Processo pai
        wait(NULL);
    }
}

void seqPipe(char *arg) {
    char *arg1 = strtok(arg, "|");
    char *arg2 = strtok(NULL, "|");

    removerEspaco(&arg1);
    removerEspaco(&arg2);

    int pipe_fd[2];

    if (pipe(pipe_fd) == -1) {
        fprintf(stderr, "Error - erro ao criar pipe no argumento %s\n", arg);
        return;
    }

    pid_t pid1, pid2;

    if ((pid1 = fork()) == -1) {
        fprintf(stderr, "Error - erro no fork pib1");
        return;
    }

    if (pid1 == 0) {
        close(pipe_fd[0]); 

        dup2(pipe_fd[1], STDOUT_FILENO); 
        close(pipe_fd[1]); 

        char arg1_path[2001];

        if (realpath(arg1, arg1_path) == NULL) {
            execl("/bin/sh", "sh", "-c", arg1, NULL);
        } else {
            execl(arg1_path, arg1, NULL);
        }

        exit(0);
    }

    if ((pid2 = fork()) == -1) {
        fprintf(stderr, "Error - erro no fork pib2");
        return;
    }

    if (pid2 == 0) {
        close(pipe_fd[1]); 

        dup2(pipe_fd[0], STDIN_FILENO); 
        close(pipe_fd[0]); 

        char arg2_path[2001];

        if (realpath(arg2, arg2_path) == NULL) {
            execl("/bin/sh", "sh", "-c", arg2, NULL);
        } else {
            execl(arg2_path, arg2, NULL);
        }

        exit(0);
    }

    close(pipe_fd[0]); 
    close(pipe_fd[1]); 

    wait(NULL); 
    wait(NULL); 
}

void seqRedirecinarSaida(char *arg, char *modo) {
    char *argumento = strtok(arg, modo);
    char *nome_arquivo = strtok(NULL, modo);

    removerEspaco(&argumento);
    removerEspaco(&nome_arquivo);

    char *arquivo = binPath(nome_arquivo);

    int saida_padrao = dup(STDOUT_FILENO);

    int f = 0;
    if (strstr(modo, ">>")) {
        f = open(arquivo, O_WRONLY | O_CREAT | O_APPEND, 0666);
    } else if (strstr(modo, ">")){
        f = open(arquivo, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    } 

    if (f == -1) {
        fprintf(stderr, "Error - erro ao abrir arquivo %s\n", arquivo);
        return;
    } 

    dup2(f, STDOUT_FILENO);

    close(f);

    seqPadrao(argumento);

    dup2(saida_padrao, STDOUT_FILENO);
}

void seqRedirecionarEntrada(char *arg) {
    char *argumento = strtok(arg, "<");
    char *nome_arquivo = strtok(NULL, "<");

    removerEspaco(&argumento);
    removerEspaco(&nome_arquivo);

    char *arquivo = buscarPathArquivo(nome_arquivo);

    int entrada_padrao = dup(STDIN_FILENO);

    int f = open(arquivo, O_RDONLY);

    if (f == -1) {
        fprintf(stderr, "Error - erro ao abrir arquivo %s\n", arquivo);
        return;
    } 

    dup2(f, STDIN_FILENO);

    close(f);

    seqPadrao(argumento);

    dup2(entrada_padrao, STDIN_FILENO);
}

void seqTrocaStyle(char *arg) {
    pid_t pib;

    pib = fork();

    if (pib < 0) {
        fprintf(stderr, "Error - erro no fork pib");
        return;
    } else if (pib == 0) {
        styleTroca(arg);

        exit(0);
    } else {
        wait(NULL);
    }
}

void seqBackgrund(char *arg_) {
    char *arg = strtok(arg_, "&");

    removerEspaco(&arg);

    pid_t pid;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Error - erro no fork pib");
        return;
    } else if (pid == 0) {
        char arg_path[2001];

        if (realpath(arg, arg_path) == NULL) {
            execl("/bin/sh", "sh", "-c", arg, NULL);
        } else {
            execl(arg_path, arg, NULL);
        }

        exit(0);
    } else {
        printf("svc3 %s> [%d] %d\n", style, bg, pid);
        bg++;
    }
}

void seqComands(char *arg) {
    if (strcmp("style parallel", arg) == 0 || strcmp("style sequential", arg) == 0) {
        seqTrocaStyle(arg);
        return;
    }

    if (strstr(arg, "|")) {
        seqPipe(arg);
        return;
    }

    if (strstr(arg, ">>")) {
        seqRedirecinarSaida(arg, ">>");
        return;
    } else if (strstr(arg, ">")) {
        seqRedirecinarSaida(arg, ">");
        return;
    } else if (strstr(arg, "<")) {
        seqRedirecionarEntrada(arg);
        return;
    } 

    if (strstr(arg, "&")) {
        seqBackgrund(arg);
        return;
    }

    if (strcmp(arg, "!!") == 0) {
        printf("No commands\n");
        return;
    }

    seqPadrao(arg);
}

int seqExit(char **args) {
    int fim = 0;
    
    while (args[fim] != NULL) {
        if (strcmp("exit", args[fim]) == 0) {
            break;
        }

        fim++;
    }

    return fim;
}

void seqStyle(char **args, int tam_args) {
    int fim = seqExit(args);

    pid_t pib;

    pib = fork();

    if (pib < 0) {
        fprintf(stderr, "Error - erro no fork pib");
    } else if (pib == 0) {
        for (int i = 0; i < fim; i++) {
            seqComands(args[i]);
        }
        
        exit(0);
    } else {
        wait(NULL);

        if (fim != tam_args) {
            exit(0);
        } 
    }
}

void parPadrao(char *arg) {
    int stderr_fd = open("/dev/null", O_WRONLY); 
    int stderr_original = dup(STDERR_FILENO);

    dup2(stderr_fd, STDERR_FILENO);
    close(stderr_fd);


    char arg_path[2001];
    int status;

    if (realpath(arg, arg_path) == NULL) {
        status = system(arg);
    } else {
        char command[2001];
        snprintf(command, sizeof(command), "\"%s\"", arg_path);

        status = system(arg);
    }

    dup2(stderr_original, STDERR_FILENO);
    close(stderr_original);

    if (status != 0) {
        fprintf(stderr, "Erro: %s - erro ao execultar argumento\n", arg);
    }
}

void parPipe(char *arg) {
    char *arg1 = strtok(arg, "|");
    char *arg2 = strtok(NULL, "|");

    removerEspaco(&arg1);
    removerEspaco(&arg2);

    int pipe_fd[2];

    if (pipe(pipe_fd) == -1) {
        fprintf(stderr, "Erro: %s - erro na criaçao do pipe\n", arg);
        return;
    }

    int saida_padrao = dup(STDOUT_FILENO);
    dup2(pipe_fd[1], STDOUT_FILENO);
    close(pipe_fd[1]);

    parPadrao(arg1);

    dup2(saida_padrao, STDOUT_FILENO);

    int entrada_padrao = dup(STDIN_FILENO);
    dup2(pipe_fd[0], STDIN_FILENO);
    close(pipe_fd[0]);

    parPadrao(arg2);

    dup2(entrada_padrao, STDIN_FILENO);

}

void parRedirecinarSaida1(char *arg) {
    char *argumento = strtok(arg, ">>");
    char *nome_arquivo = strtok(NULL, ">>");

    removerEspaco(&argumento);
    removerEspaco(&nome_arquivo);

    char *arquivo = binPath(nome_arquivo);

    int saida_padrao = dup(STDOUT_FILENO);

    int f = open(arquivo, O_WRONLY | O_CREAT | O_APPEND, 0666);

    if (f == -1) {
        fprintf(stderr, "Error: %s - erro ao abrir arquivo %s\n", arg, arquivo);
        return;
    } 

    dup2(f, STDOUT_FILENO);

    close(f);

    parPadrao(argumento);

    dup2(saida_padrao, STDOUT_FILENO);
}

void parRedirecinarSaida2(char *arg) {
    char *argumento = strtok(arg, ">");
    char *nome_arquivo = strtok(NULL, ">");

    removerEspaco(&argumento);
    removerEspaco(&nome_arquivo);

    char *arquivo = binPath(nome_arquivo);

    int saida_padrao = dup(STDOUT_FILENO);

    int f = open(arquivo, O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (f == -1) {
        fprintf(stderr, "Error: %s - erro ao abrir arquivo %s\n", arg, arquivo);
        return;
    } 

    dup2(f, STDOUT_FILENO);

    close(f);

    parPadrao(argumento);

    dup2(saida_padrao, STDOUT_FILENO);
}

void parRedirecionarEntrada(char *arg) {
    char *argumento = strtok(arg, "<");
    char *nome_arquivo = strtok(NULL, "<");

    removerEspaco(&argumento);
    removerEspaco(&nome_arquivo);

    char *arquivo = buscarPathArquivo(nome_arquivo);

    int entrada_padrao = dup(STDIN_FILENO);

    int f = open(arquivo, O_RDONLY);

    if (f == -1) {
        fprintf(stderr, "Error: %s - erro ao abrir arquivo %s\n", arg, arquivo);
        return;
    } 

    dup2(f, STDIN_FILENO);

    close(f);

    parPadrao(argumento);

    dup2(entrada_padrao, STDIN_FILENO);
}

void parComands(char **args, int nun_args) {
    pthread_t *threads = (pthread_t*)malloc(nun_args*sizeof(pthread_t));

    for (int i = 0; i < nun_args; i++) {
        if (strcmp("style parallel", args[i]) == 0 || strcmp("style sequential", args[i]) == 0) {
            int thread_id = pthread_create(&threads[i], NULL, (void*) styleTroca, (char*) args[i]);

            if (thread_id) {
                fprintf(stderr, "Error: %s - erro ao execultar thread\n", args[i]);
            }
        } else if (strstr(args[i], "||")) {
            int thread_id = pthread_create(&threads[i], NULL, (void*) parPipe, (char*) args[i]);

            if (thread_id) {
                fprintf(stderr, "Error: %s - erro ao execultar thread\n", args[i]);
            }
        } else if (strstr(args[i], ">>")) {
            int thread_id = pthread_create(&threads[i], NULL, (void*) parRedirecinarSaida1, (char*) args[i]);

            if (thread_id) {
                fprintf(stderr, "Error: %s - erro ao execultar thread\n", args[i]);
            }
        } else if (strstr(args[i], ">")) {
            int thread_id = pthread_create(&threads[i], NULL, (void*) parRedirecinarSaida2, (char*) args[i]);

            if (thread_id) {
                fprintf(stderr, "Error: %s - erro ao execultar thread\n", args[i]);
            }
        } else if (strstr(args[i], "<")) {
            int thread_id = pthread_create(&threads[i], NULL, (void*) parRedirecionarEntrada, (char*) args[i]);

            if (thread_id) {
                fprintf(stderr, "Error: %s - erro ao execultar thread\n", args[i]);
            }
        } else {
            int thread_id = pthread_create(&threads[i], NULL, (void*) parPadrao, (char*) args[i]);

            if (thread_id) {
                fprintf(stderr, "Error: %s - erro ao execultar thread\n", args[i]);
            }
        }  
        
    }

    // Espera as threads acabarem
    for (int i = 0; i < nun_args; i++) {
        pthread_join(threads[i], NULL);
    }
}

int parExit(char **args, char ***args_, int tam_args) {
    int ind_ = 0;

    for (int i = 0; i < tam_args; i++) {
        if (strcmp("exit", args[i]) != 0) {
            if (*args_ == NULL) {
                *args_ = (char**)malloc(sizeof(char*));
            } else {
                *args_ = (char**)realloc(*args_, (ind_+1)*sizeof(char*));
            }

            (*args_)[ind_] = strdup(args[i]);
            ind_++;
        }
    }

    return ind_;
    
}

void parStyle(char **args, int tam_args) {
    char **args_ = NULL;
    int ind_ = parExit(args, &args_, tam_args);


    if (ind_ != tam_args) {
        if (args_ != NULL) {
            parComands(args_, ind_);
        }

        exit(0);
    } else {
        parComands(args, tam_args);
    }
    
}

void comands(char **args){
    int tam_args = tamArryArgs(args);

    if (strcmp(style, "seq") == 0) {
        seqStyle(args, tam_args);
    } else if (strcmp(style, "par") == 0) {
        parStyle(args, tam_args);
    }
}