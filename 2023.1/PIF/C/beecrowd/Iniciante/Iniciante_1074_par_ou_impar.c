#include <stdio.h>

int main(void){
    int N, nun;

    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d", &nun);

        if(nun%2==0 && nun!=0){
            printf("EVEN ");
        }else if(nun%2!=0){
            printf("ODD ");
        }

        if(nun<0){
            printf("NEGATIVE\n");
        }else if(nun>0){
            printf("POSITIVE\n");
        }else{
            printf("NULL\n");
        }
    }
}