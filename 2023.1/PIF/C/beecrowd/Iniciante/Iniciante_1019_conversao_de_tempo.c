#include <stdio.h>
 
int main() {
    int tempo;
    int segundos = 0;
    int minutos = 0;
    int horas = 0;

    scanf("%d", &tempo);

    horas = tempo/3600;
    minutos = (tempo%3600)/60;
    segundos = (tempo%3600)%60;

    printf("%d:%d:%d\n", horas, minutos, segundos);
    return 0;
}