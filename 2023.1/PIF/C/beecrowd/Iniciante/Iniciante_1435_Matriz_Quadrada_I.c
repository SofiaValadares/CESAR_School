#include <stdio.h>
 
int main() {
    int n, n_teste;
    int i, j, k=1;

    while(1){
        scanf("%d", &n);
        
        if(n==0){
            break;
        }
        n_teste = n;

        int matriz[n][n];

        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                matriz[i][j] = 1;
            }
        }

        while (n_teste>2){
            for(i=k; i<n-k; i++){
                for(j=k; j<n-k; j++){
                    matriz[i][j] = matriz[i][j] + 1;
                }
            }
            k++;
            n_teste-=2;
        }
        
        n_teste = 0;
        k = 1;

        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                printf("%3d", matriz[i][j]);
                if(j!=n-1){
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}