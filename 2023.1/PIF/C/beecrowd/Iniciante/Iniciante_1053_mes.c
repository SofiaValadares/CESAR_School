#include <stdio.h>

char* trasforma(int nun);

int main(void){
    int nun;
    char meses[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int i = 0;

    scanf("%d", &nun);

    while(meses[nun-1][i] != '\0'){
        printf("%c", meses[nun-1][i]);
        i++;
    }
    printf("\n");
}