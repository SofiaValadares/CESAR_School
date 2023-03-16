#include <stdio.h>

char imprimir(char str[50]);

int main(){
    char ch;
    char str[50];
    int k;

    while((ch = getchar()) != EOF){
        k = 0;

        while(ch != '\n'){
            str[k] = ch;
            k++;
            ch = getchar();
        }

        str[k] = '\0';

        imprimir(str);
    }
}

char imprimir(char str[50]){
    char ch;
    int i = 0;
    int a = 0, b = 0;

    while (str[i] != '\0'){
        ch = str[i];
        if(ch == '_'){
            if(a == 0){
                printf("<i>");
                a++;
            }
            else{
                printf("</i>");
                a -= 1;
            }
        }
        else if(ch == '*'){
            if(b == 0){
                printf("<b>");
                b++;
            }
            else{
                printf("</b>");
                b -= 1;
            }
        }
        else{
            printf("%c", ch);
        }

        i++;
    }
    printf("\n");
    return 0;
    
}