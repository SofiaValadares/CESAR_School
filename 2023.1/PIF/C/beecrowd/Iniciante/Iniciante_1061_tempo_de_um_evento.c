#include <stdio.h>

int ler();
int conrt(int a, int b, int c, int d);

int main(void) {
    int time1, time2, dif, rest;

    time1 = ler();
    time2 = ler();
    

    dif = time2 - time1;

    printf("%d dia(s)\n", dif / 86400);
    rest = dif % 86400;

    printf("%d hora(s)\n", rest / 3600);
    rest = rest % 3600;

    printf("%d minuto(s)\n", rest / 60);
    rest = rest % 60;

    printf("%d segundo(s)\n", rest);

    return 0;
}

int conrt(int a, int b, int c, int d) {
    int time = 0;

    time = a * 24;
    time += b;
    time = time * 60;
    time += c;
    time = time * 60;
    time += d;

    return time;
}

int ler(){
    int dia, hora, min, seg;
    int temp;

    scanf("Dia %d", &dia);
    scanf("%d : %d : %d\n", &hora, &min, &seg);

    temp = conrt(dia, hora, min, seg);

    return temp;
}
