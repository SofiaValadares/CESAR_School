#include <stdio.h>
 
int main() {
    int g, a, m, c;
    int nun1, nun2, nun3, maior_ = -10000, count;
    int i, j, k;

    scanf("%d %d %d %d", &nun1, &a, &nun2, &nun3);

    if(nun1 <= 600){
        g = nun1;
    }
    if(nun2<=2000){
        m = nun2;
    }
    if(nun3<=100){
        c = nun3;
    }

    int ativ_curs[g][a];

    for(i=0; i<g; i++){
        for(j=0; j<a; j++){
            scanf("%d", &nun1);
            if(nun1<=10){
                ativ_curs[i][j] = nun1;
            }
        }
    }

    int mati_ativ[a][m];

    for(i=0; i<a; i++){
        for(j=0; j<m; j++){
            scanf("%d", &nun1);
            if(nun1<=10){
                mati_ativ[i][j] = nun1;
            }
        }
    }

    int bit[m][c];

    for(i=0; i<m; i++){
        for(j=0; j<c; j++){
            scanf("%d", &nun1);
            if(nun1<=100){
                bit[i][j] = nun1;
            }
        }
    }

    int calc1[g][m];

    for(i=0; i<g; i++){
        for(j=0; j<m; j++){
            calc1[i][j]=0;
            for(k=0; k<a; k++){
                calc1[i][j] += ativ_curs[i][k] * mati_ativ[k][j];
            }
        }
    }

    int rels[g][c];

    for(i=0; i<g; i++){
        for(j=0; j<c; j++){
            rels[i][j]=0;
            for(k=0; k<m; k++){
                rels[i][j] += calc1[i][k] * bit[k][j];
            }
        }
    }

    int maior[c], maior_count[c];

    for(j=0; j<c; j++){
        for(i=0; i<g; i++){
            if(rels[i][j] > maior_){
                maior_ = rels[i][j];
            }
        }
        maior[j] = maior_; 
        maior_ = 0;
    }

    for(j=0; j<c; j++){
        count = maior[j];
        maior_count[j]=0;
        while(count!=0){
            count/=10;
            maior_count[j] = maior_count[j]+1;
        }
    } 
    for(i=0; i<g; i++){
        for(j=0; j<c-1; j++){
            printf("%*d ", maior_count[j], rels[i][j]);
        }
        printf("%*d\n", maior_count[c-1], rels[i][c-1]);
    }

    return 0;

}