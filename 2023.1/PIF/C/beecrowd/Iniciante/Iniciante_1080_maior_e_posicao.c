#include <stdio.h>
 
int main(void) {
    int a, b;
    int posi = 1;
    
    scanf("%d", &a);
    
    for(int i=0; i<99; i++){
        scanf("%d", &b);
        
        if(a<b){
            a=b;
            posi = i+2;
        }
    }

    printf("%d\n", a);
    printf("%d\n", posi);
}