#include <stdio.h>

int main(void){
    int nun;
    int i, j, k, z, d;

    
    scanf("%d", &nun);

    while (nun>0){
        int matriz[nun][nun];

        for(i=0; i<nun;i++){
            for(j=0; j<nun; j++){
                matriz[i][j] = 1;
            }
        }
        
        z=0;

        for(i=0; i<nun;i++){
            k=z;
            d = -1;
            for(j=0; j<nun; j++){
                if(j==z){
                    k++;
                    d=1;
                }else{
                    matriz[i][j] += k;
                    k+= d;
                }
            }
            z++;
        }

        for(i=0; i<nun; i++){
            for(j=0; j<nun-1; j++){
                printf("%3d ", matriz[i][j]);
            }
            printf("%3d\n", matriz[i][nun-1]);
        }
        printf("\n");

        scanf("%d", &nun);
    }
    
}