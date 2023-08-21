#include <stdio.h>

int num_calls = 0;
int result = 0;

int fib(int nun);

int main(void){
    int n;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);

        fib(x);

        printf("fib(%d) = %d calls = %d\n", x, num_calls-1, result);
        num_calls = 0;
        result = 0;
    }
}

int fib(int nun){
    num_calls++;

    if(nun == 0) return 0;

    if(nun == 1){
        result++;
        return 1;
    }

    return fib(nun-1)+fib(nun-2);
}