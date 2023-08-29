#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h> 

int main(){

    pid_t pid, pid1;
    int i;

    pid1 = getpid();
    printf("start pid = %d\n", pid1);

    for(i = 0; i < 2; i++){//Com o for vão ser criados dois processos filhos
        pid = fork();//Quando eu tenho um fork o codigo todo com as variaveis, então o valor do i no primeiro filho é 1 e o do segundo filho é 2
                     //O primeiro filho vai execultar o for uma vez, ou seja o filho tem um filho 

        if(pid < 0){
            fprintf(stderr, "Fork failled");
            return 1;
        }
        else if(pid == 0){
            pid1 = getpid();
            printf("child: pid = %d\n", pid);
            printf("child: pid1 = %d\n", pid1);
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