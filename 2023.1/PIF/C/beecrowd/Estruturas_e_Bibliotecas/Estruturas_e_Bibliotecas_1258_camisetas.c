#include <stdio.h>
#include <string.h>

struct lista{
    char nome[100];
    char cor[10];
    char tamanho;
};

int ordem(int nun, struct lista camisas[nun], char a);

int main(void){
    char nome_[100], cor_[10], tamanho_;
    char ch;
    int nun = 1;
    int i, k=0;


    scanf("%d", &nun);
    while(nun!=0){
        struct lista camisas[nun];


        for(i=0; i<nun; i++){
            scanf("\n");
            ch = getchar();

            while (ch != '\n'){
                nome_[k] = ch;
                k++;
                ch = getchar();
            }
            nome_[k] = '\0';
            
            scanf("%s %c", cor_, &tamanho_);

            strcpy(camisas[i].nome, nome_);
            strcpy(camisas[i].cor, cor_);
            camisas[i].tamanho = tamanho_;

            nome_[0] = '\0';
            cor_[0] = '\0';
            k = 0;
        }

        ordem(nun, camisas, 'b');
        ordem(nun, camisas, 'v');

        nun = 0;
        scanf("%d", &nun);

        if(nun!=0){
            printf("\n");
        }
    }
}

int ordem(int nun, struct lista camisas[nun], char a){
    char ch[] = "PMG";
    int i, j, k=0, z=0;
    char atual[100], menor[100];
    struct lista alfabetica_nomes[nun];
    struct lista ordem_tamanho[nun];


    for(i=0; i<nun; i++){
        strcpy(menor, "zzzzzzzzzzzzzzzzz");
        for(j=0; j<nun; j++){
            strcpy(atual, camisas[j].nome);
            
            if(strcmp(atual, menor)<0 && strcmp(atual, "1a")!=0){
                menor[0] = '\0';
                strcpy(menor, atual);

                alfabetica_nomes[i].nome[0] = '\0';
                alfabetica_nomes[i].cor[0] = '\0';
                
                strcpy(alfabetica_nomes[i].nome, camisas[j].nome);
                strcpy(alfabetica_nomes[i].cor, camisas[j].cor);
                alfabetica_nomes[i].tamanho = camisas[j].tamanho; 
            
                z=j;
            }
        }

        camisas[z].nome[0] = '\0';
        strcpy(camisas[z].nome, "1a");
        menor[0] = '\0';
    }

    for(i=0; i<3; i++){
        for(j=0; j<nun; j++){
            if(alfabetica_nomes[j].tamanho == ch[i]){
                strcpy(ordem_tamanho[k].nome, alfabetica_nomes[j].nome);
                strcpy(ordem_tamanho[k].cor, alfabetica_nomes[j].cor);
                ordem_tamanho[k].tamanho = alfabetica_nomes[j].tamanho;
                k++;
            }
        }
    }

    for(j=0; j<nun; j++){
        if(ordem_tamanho[j].cor[0] == a){
                    printf("%s %c %s\n", ordem_tamanho[j].cor, ordem_tamanho[j].tamanho, ordem_tamanho[j].nome);
        }
    }

    return 0;
}