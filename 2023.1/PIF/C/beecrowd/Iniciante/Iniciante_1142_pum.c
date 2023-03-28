#include <stdio.h>

int main(){
    int linhas;
    int nun = 0;
    int i;
    int j;

    scanf("%d", &linhas);

    for(i=0; i<linhas; i++){
        for(j=0; j<3; j++){
            nun++;
            printf("%d ", nun);
        }
        nun++;
        printf("PUM\n");
    }
}