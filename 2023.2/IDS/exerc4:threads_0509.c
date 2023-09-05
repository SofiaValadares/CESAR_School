// Linha de argumento para rodar sistema:
//     gcc 2023.2/IDS/exerc4:threads_0509.c
//     ./a.out 1 2 3 4 5 6

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // Biblioteca que permite o uso de threads 

//Função que sera execultada pela thread, toda thread tem que ter uma função associada para dizer 
//o que essa thread ira fazer. Essa função é passado pra thread no thread criate por ponteiro 

void *avg_func(void *str); //Criar uma funçao como ponteiro pode facilitar o processo
void *min_func(void *str);
void *max_func(void *str);

//Para receber os valores vamos usar variaveis globais, porem também podemos fazer um tratamento de retorno com variavies locais ou inprimir a variavel na funçao da thread
double avg;
int min;
int max;

//agumentos que vão ser passados para o pthread create
typedef struct 
{
    int size;
    int * values;
}datastruct;


int main(int argc, char *argv[]){

    if(argc <= 1)//Se você não tiver passado um array de inteiros 
    {
        printf("Incorrect input. No arguments entered\n");
        exit(0); //Argumanto 0 no exit sai do sistema com sucesso, se tivesse outro argumento poderiamos ter um tratamento de erro;
    }


    int copy[argc-1]; //Array que irar receber os numeros do argumentos e transforma de caractere para inteiro;
    for(int i = 0; i < (argc-1); i++)
    {
        copy[i] = atoi(argv[i+1]); //atoi = converte caractere para inteiro
    }

    datastruct ds = {argc-1, copy}; //Cria uma struct que recebe o tamano do array e o array de inteiros. Ele passa os valores na orem na criaçao
    pthread_t thread1, thread2, thread3; //Define as variaveis do tipo pthread_t
    int t1, t2, t3; //Toda vez que criarmos uma thread ele retorna um inteiro, se retornar 1 a thread foi criada com sucesso, se retornar 0 ouve um erro na criaçao da thread

    t1 = pthread_create(&thread1, NULL, (void*) avg_func, (void*) &ds); //Primeiro argumento: ponteiro que aponta para a thread
                                                                        //Segundo argumento: Pode mudar as configurações da thread, no caso NULL não muda
                                                                        //Terceiro argumento: recebe um ponteiro da função
                                                                        //Quarto argumento: argumentos da funçao que vai ser passa para o pthread (quarto arguemnto);
                                                                        //Por definiçao pthread so rerebe um argumento como argumento da funçao, caso você precise mais de um podemos criar uma struct

    if(t1) //Vericica se ouve erro na criação da thread, caso aja erro retorna o tipo de erro
    {
        fprintf(stderr, "Error - pthread create() return code %d\n", t1);
        exit(EXIT_FAILURE);
    }

    t2 = pthread_create(&thread2, NULL, (void*) min_func, (void*) &ds);
    if(t2) 
    {
        fprintf(stderr, "Error - pthread create() return code %d\n", t2);
        exit(EXIT_FAILURE);
    }

    t3 = pthread_create(&thread3, NULL, (void*) max_func, (void*) &ds);
    if(t3) 
    {
        fprintf(stderr, "Error - pthread create() return code %d\n", t3);
        exit(EXIT_FAILURE);
    }

    
    pthread_join(thread1, NULL); //Trava o programa ate o fim da thread, mas não impede o funcionamento das outras threads
                                 //Primeiro argumento: a thread que estamos esperando;
                                 //Segundo argumento: recebe o retorno em um retorno no tipo void, onde temos que fazer um tratamento do retorno. Caso não receber retorno recebe NULL
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("The average: %g\n", avg); //Tipo g é para o tipo double
    printf("The minimum: %d\n", min);
    printf("The maximum: %d\n", max);

    exit(EXIT_SUCCESS);

    return 0;
}

//Função que calcula a media do array
void *avg_func(void *ptr){
    datastruct *ds;
    ds = (datastruct*) ptr; //Casting do ponteiro void

    avg = 0; //Variavel global;

    for(int i = 0; i < ds->size; i++)
    {
        avg += (ds->values[i]);
    }

    avg = (avg/ds->size);
    return NULL;
}

//Função 
void *min_func(void *ptr){
    datastruct *ds;
    ds = (datastruct*) ptr;

    min = 0;

    for(int i = 0; i < ds->size; i++)
    {
        if(ds->values[i] < min || i == 0){
            min = ds->values[i];
        }
    }

    return NULL;
}

void *max_func(void *ptr){
    datastruct *ds;
    ds = (datastruct*) ptr;

    max = 0;

    for(int i = 0; i < ds->size; i++)
    {
        if(ds->values[i] > max || i == 0){
            max = ds->values[i];
            
        }
    }

    return NULL;   
}