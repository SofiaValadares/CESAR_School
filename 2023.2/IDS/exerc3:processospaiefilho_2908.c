#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdlib.h>

int main(){

    pid_t pid, pid1;
    int i;

    pid1 = getpid();
    printf("start pid = %d\n", pid1);

    for(i = 0; i < 2; i++){
        pid = fork();

        if(pid < 0){
            fprintf(stderr, "Fork failled");
            return 1;
        }
        else if(pid == 0){
            pid1 = getpid();
            printf("child: pid = %d\n", pid);
            printf("child: pid1 = %d\n", pid1);
            exit(0); //Vai impedir que o processo filho crie mais um processo
            
        }
        else{
            pid1 = getpid();
            printf("parent: pid1 = %d\n", pid);
            printf("parent: pid1 = %d\n", pid1);
            wait(NULL);
        }
    }
    
    return 0;
}