#include <stdio.h>

int main(void){
    int n, f, c;
    int k=1, z=1;
    
    scanf("%d %d %d", &n, &f, &c);

    int matriz[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matriz[i][j] = k;
            k++;
        }
    }
}