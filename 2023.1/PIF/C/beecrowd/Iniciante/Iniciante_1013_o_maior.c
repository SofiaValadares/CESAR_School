#include <stdio.h>
 
int main() {
    int a, b, c, d, maior;

    scanf("%d %d %d", &a, &b, &c);

    d = (a + b + abs(a-b))/2;
    maior = (d + c + abs(d-c))/2;

    printf("%d eh o maior\n", maior);
    return 0;
}