#include <stdio.h>
#include <math.h>
 
int main() {
    int n;
    int a = 0;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        a++;
        
        printf("%d %d %d\n", a, a*a, a*a*a);
    }
 
    return 0;
}