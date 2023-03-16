#include <stdio.h>

char primeira(char str[1000], int k);
char terceira(char str2[1000], int k);

int main(void){
    int n;

    scanf("%d\n", &n);

    while (n!=0){
        char str[1000], str2[1000], ch;
        int i;
        int i;
        int k = 0;
        int y;

        ch = getchar();

        while (ch != '\n'){
            str[k] = ch;
            k++;
            ch = getchar();
        }

        str[k] = '\0';

        for(i=0; i<k; i++){
            str[i] = primeira(str, i);
        }

        for(i=1; i<k+1; i++){
            str2[i-1] = str[k-i];
        }

        y = k/2;
        
        for(i=y; i<k; i++){
            str2[i] = terceira(str2, i);
        }

        for(i=0; i<k; i++){
            printf("%c", str2[i]);
        }
        printf("\n");

        str[0] = '\0';
        str2[0] = '\0';        
        n -= 1;
    }
    
}

char primeira(char str[1000], int k){
    char ch;
    int ascii;

    ascii = str[k];

    if((ascii>64 && ascii<90) || (ascii>96 && ascii<123)){
        ascii += 3;
    }

    ch = ascii;
    return ch; 
}

char terceira(char str2[1000], int k){
    char ch;
    int ascii;

    ascii = str2[k];
    ascii -= 1;

    ch = ascii;
    return ch;
}