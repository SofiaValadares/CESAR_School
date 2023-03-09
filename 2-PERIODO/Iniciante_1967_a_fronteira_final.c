#include <stdio.h>

int main(){
    int g, a, m, c;
    int nun1, nun2, nun3;
    int i, j, k;

    scanf("%d %d %d %d", &nun1, &a, &nun2, &nun3);

    if(nun1<=600){
        g = nun1;
    }
    if(nun2<=2000){
        m = nun2;
    }
    if(nun3<=100){
        c = nun3;
    }
    
    printf("\n");

    int ativ_ano[g][a], mati_ativ[a][m], bit[m][c], multi[g][m], reslt[g][c];

    for(i=0; i<g; i++){
        for(j=0; j<a; j++){
            ativ_ano[i][j] = 0;
            scanf("%d ", &nun1);
            if(nun1>10){
                ativ_ano[i][j] = nun1;
            }
        }
    }
    printf("\n");

    for(i=0; i<a; i++){
        for(j=0; j<m; j++){
            mati_ativ[i][j] = 0;
            scanf("%d ", &nun1);
            if(nun1>10){
                mati_ativ[i][j] = nun1;
            }
        }
    }
    printf("\n");

    for(i=0; i<m; i++){
        for(j=0; j<c; j++){
            scanf("%d ", &nun1);
            bit[i][j] = 0;
            if(nun1>100){
                bit[i][j] = nun1;
            }
        }
    }
    printf("\n");

    for(i=0; i<g; i++){
        for(j=0; j<m; j++){
            multi[i][j]=0;
            for(k=0; k<a; k++){
                multi[i][j]+=ativ_ano[k][j]+mati_ativ[i][k];
            }
        }
    }

    for(i=0; i<g; i++){
        for(j=0; j<c; j++){
            reslt[i][j]=0;
            for(k=0; k<m; k++){
                reslt[i][j]+=multi[k][j]+bit[i][k];
            }
            printf("%d ", reslt[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}