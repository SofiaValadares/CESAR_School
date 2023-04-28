#include <stdio.h>
#include <stdlib.h>


int main(void){
    int linhas, colunas;
    int i, j, k = -1;
    int **matriz = NULL;
    int nun = 0;

    while((scanf("%d %d", &linhas, &colunas)) == 2){


        matriz = (int**)malloc(linhas*sizeof(int*));

        for(i=0; i<linhas;i++){
            matriz[i] = (int*)malloc(colunas*sizeof(int));

            for(j=0; j<colunas; j++){
                scanf("%d", &matriz[i][j]);
            }
        }

        for(i=0; i<linhas; i++){
            for(j=0; j<colunas; j++){
                if(matriz[i][j]==1){
                    matriz[i][j]= 9;
                }
            }
        }
        for(i=0; i<linhas; i++){
            for(j=0; j<colunas; j++){
                if(matriz[i][j]==0){
                    while(k<2){
                        if((i>0 && k<0) || (i<linhas-1 && k>0)){
                            if(matriz[i+k][j]==9){
                                nun++;
                            }
                        }

                        if((j>0 && k<0) || (j<colunas-1 && k>0)){
                            if(matriz[i][j+k]==9){
                                nun++;
                            }
                        }

                        k+=2;
                    }
                    k=-1;

                    matriz[i][j] = nun;
                    nun = 0;
                }
            }
        }

        for(i=0; i<linhas; i++){
            for(j=0; j<colunas; j++){
                if(j<colunas-1){
                    printf("%d", matriz[i][j]);
                }
                else{
                    printf("%d\n", matriz[i][j]);
                }
            }
        }
        free(matriz);
    }
}