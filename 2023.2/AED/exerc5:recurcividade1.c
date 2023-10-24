#include <stdio.h>

int tabelaMulti(int N);

int main() {
    int N;

    printf("Insira um numero inteiro positivo: ");
    scanf("%d", &N);

    int soma = tabelaMulti(N);

    printf("Soma das multiplicações: %d\n", soma);
}

int tabelaMulti(int N) {
   if (N == 0) {
        return 0;
   } else {
        return (N*2) + tabelaMulti(N-1);
   }
}