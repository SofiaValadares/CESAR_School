#include <stdio.h>
#include <unistd.h> //Guarda o pib do processo
#include <sys/wait.h> //Ter a função wait no processo pai para esperar o processo filho

int main(){

    pid_t pid, pid1;//Variavel pid não é o pid do processo
    pid = fork();//O fork está criando dois processos, o processo pai e o processo filho
                 //Tem agora dois processos, o pid para o processo pai tem um numero (id) do processo filho, e no filho essa variavel tem valor de 0

    
    if(pid < 0){/*FORK FAILED*/
        //Caso o pid seja um valor negativo, significa que a execulção do processo fork deu um erro        
        fprintf(stderr, "Fork failed\n");//O fprintf redireciona o erro para o arquivo que esta escrito
                                         //stderr é a sauda padão de erro
        return 1;
    }
    else if(pid == 0){ /*CHILD PROCESS*/
        //Se pid for igual a o significa que eu estou no processo filho
        pid1 = getpid(); //O processo filho esta pegando seu propio pid
        printf("child: pid = %d\n", pid);//Imprime valor da variavel pid no processo filho = 0
        printf("child: pid1 = %d\n", pid1);//Imprime valor da variavel pid no processo filho = pid filho

    }
    else{/*PARENT PROCESS*/
        //Quando o pid for diferente de 0 e positivo significa que estou no processo pai
        pid1 = getpid();//O processo pai esta pegando seu propio pid
        printf("parent: pid = %d\n", pid);//Imprime valor da variavel pid no processo pai = pid filho
        printf("parent: pid1 = %d\n", pid1);//Imprime valor da variavel pid no processo pai = pid pai
        wait(NULL);//Vai esperar o processo filho
    }
    return 0;
}