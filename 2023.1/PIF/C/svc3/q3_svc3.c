#include <stdio.h>
#include <string.h>

char imprimir(char str[20]);

int main(){
    int nun1, nun2;
    int y = 0;
    char str[20], str2[20];

    scanf("%d\n", &nun1);

    while (nun1 != 0){
        scanf("%d\n", &nun2);

        while (nun2 != 0){
            
            str2[0] = '\0';
            strcpy(str2, str);
            str[0] = '\0';

            scanf("%s", str);


            if(y != 0){
                if(strcmp(str, str2) != 0){
                    str[0] = '\0';
                    strcpy(str, "ingles");
                }
            }
            else{
                y++;
            }

            nun2 -= 1;
        }

        imprimir(str);
        
        nun2 = 0;
        y = 0;

        nun1 -= 1;
    }
    
}

char imprimir(char str[20]){
    int i;

    for(i=0; str[i] != '\0'; i++){
        putchar(str[i]);
    }
    printf("\n");

    return 0;
}