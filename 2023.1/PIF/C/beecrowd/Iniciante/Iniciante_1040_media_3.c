#include <stdio.h>
 
int main() {
    double n1, n2, n3, n4, media, exame, media_exame;

    scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
    media = (n1*2 + n2*3 + n3*4 + n4)/10;

    printf("Media: %.1lf\n", media);

    if(media >= 7){
        printf("Aluno aprovado.\n");
    }
    else if(media < 5){
        printf("Aluno reprovado.\n");
    }
    else{
        printf("Aluno em exame.\n");

        scanf("%lf", &exame);
        printf("Nota do exame: %.1lf\n", exame);

        media_exame = (media + exame)/2;

        if(media_exame>=5){
            printf("Aluno aprovado.\n");
        }
        else{
             printf("Aluno reprovado.\n");
        }

        printf("Media final: %.1lf\n", media_exame);
    }

    return 0;
}