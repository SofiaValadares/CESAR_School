#include <stdio.h>

void hanoi_jogadas(int num, int discs, int move, int extra);
int temp(int segs, int tipo);
int jogadas = 0;
int _temp = 0;

int main(){
    int nun;
    int horas, min, segs, rest;
    scanf("%d", &nun);

    hanoi_jogadas(nun, 1, 3, 2);
    printf("%d\n", jogadas);

    rest = temp(jogadas, 3600);
    horas = _temp;
    _temp = 0;

    segs = temp(rest, 60);
    min = _temp;
    
    printf("%d:%d:%d\n", horas, min, segs);
}

void hanoi_jogadas(int num, int discs, int move, int extra){
    if(num == 1){
        jogadas++;
        return;
    }
    
    hanoi_jogadas(num - 1, discs, extra, move);
    jogadas++;
    hanoi_jogadas(num - 1, extra, move, discs);
}

int temp(int segs, int tipo){
    if(segs < tipo){
        return segs;
    }

    _temp++;
    return temp((segs-tipo), tipo);
}
