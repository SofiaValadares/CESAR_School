#include <stdio.h>
 
int main() {
    char nome[25];
    float salario, vendas;
    double ganho;

    scanf("%s", &nome);
    scanf("%f", &salario);
    scanf("%f", &vendas);

    ganho = salario + vendas*0.15;

    printf("TOTAL = R$ %.2f\n", ganho);
    return 0;
}