#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int quantidade;
    float preco;
    char tipo[20];
}Fruta;

int main() {
    int testes, disp, qnt_P;
    float total=0;
    scanf("%d", &testes);
    for(int i=0;i<testes;i++){
        scanf("%d", &disp);
        Fruta *produto = malloc(disp * sizeof(Fruta));
        for(int j=0;j<disp;j++){
          scanf("%s %f",produto[j].tipo, &produto[j].preco);
        }
        scanf("%d", &qnt_P);
        for(int j=0;j<qnt_P;j++){
          char alimento[qnt_P];
          int qnt;
          scanf("%s %d", alimento, &qnt);
          for(int z=0;z<disp;z++){
            if (strcmp(alimento, produto[z].tipo)==0){
              total += produto[z].preco * qnt;
            }
        }
      }
        printf("R$ %.2f", total);
        free(produto);
    }
    return 0;
}