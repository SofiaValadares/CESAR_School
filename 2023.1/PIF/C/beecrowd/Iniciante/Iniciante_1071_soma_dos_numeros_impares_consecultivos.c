#include <stdio.h>
 
int main() {
    int x, y, i, sun = 0;

    scanf("%d", &x);
    scanf("%d", &y);
    
    if(x<y){
       for(i=x+1; i<y; i++){
            if(i%2!=0){
                sun = sun + i;
            }
        } 
    }
    else{
        for(i=y+1; i<x; i++){
            if(i%2!=0){
                sun = sun + i;
            }
        }
    }

    
    printf("%d\n", sun);
    return 0;
}