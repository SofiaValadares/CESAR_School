#include <stdio.h>
#include <string.h>
#include <ctype.h>

int maior_repeticao(char str[200], int k);
int valores_repetidos(char ch_, char str[200], char str2[200], int k, int z, int maior);
char exibir(char str2[200], int z);

int main(void){
    int n, i, j, k=0, z=0;
    int assi;

    scanf("%d\n", &n);

    for(i=0; i<n; i++){
        char str[200], str2[200]; 
        char ch_;
        int maior_freq, ch_repitidos;

        ch_ = getchar();
        ch_ = tolower(ch_);
        assi = ch_;

        while (ch_!= '\n'){
            if(assi>96 && assi <123){
                str[k] = ch_;
                k++;
            }
            ch_ = getchar();
            ch_ = tolower(ch_);
            assi = ch_;
        }
        str[k] = '\0'; 

        maior_freq = maior_repeticao(str, k);

        for(j=0; j<k; j++){
            ch_ = str[j];
            ch_repitidos = valores_repetidos(ch_, str, str2, k, z, maior_freq);
            if(ch_repitidos == 0){
                str2[z] = ch_;
                z++;
            }
        }

        exibir(str2, z);

        k = 0;
        z = 0;
        str2[0] = '\0';
    } 

    return 0;
}

int maior_repeticao(char str[200], int k){
    char ch_;
    int count = 0;
    int i, j, maior = 0;

    for(i=0; i<k; i++){
        ch_ = str[i];

        for(j=0; j<k; j++){
            if(str[j] == ch_){
                count++;
            }
        }

        if(count>maior){
            maior = count;
        }

        count = 0;
    }

    return maior;
}

int valores_repetidos(char ch_, char str[200], char str2[200], int k, int z, int maior){
    int count = 0;
    int j;
    int y = 0;

    for(j=0; j<k; j++){
        if(str[j] == ch_){
                count++;
            }
    }

    if(count==maior){
        for(j=0; j<z; j++){
            if(ch_ == str2[j]){
                y++;
            }
        }
    }
    else{
        y = 1;
    }

    return y;
}

char exibir(char str2[200], int z){
    char ch_;
    int ascii, ascii_anterior = 0, menor = 200;
    int i, j;

    for(i=0; i<z; i++){
        ch_ = str2[0];

        for(j=0; j<z; j++){
            ascii = str2[j];

            if(ascii<menor && ascii>ascii_anterior){
                ch_ = str2[j];
                menor = ch_;
            }
        }
        printf("%c", ch_);
        ascii_anterior = menor;
        menor = 200;
    }

    printf("\n");
    return 0;
}