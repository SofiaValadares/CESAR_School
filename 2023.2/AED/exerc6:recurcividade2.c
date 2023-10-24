#include <stdio.h>

int countArray(int tan, int array[]);

int main() {
    int array[6] = {5, 2, 72, 4, 6, 27};

    int soma = countArray(5, array);

    printf("Soma numeros: %d\n", soma);
    return 0;
}

int countArray(int tan, int array[]) {
    if (tan < 0) {
        return 0;
    } else {
        return array[tan] + countArray(tan-1, array);
    }
}