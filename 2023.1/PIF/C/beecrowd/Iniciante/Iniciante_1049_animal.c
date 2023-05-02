#include <stdio.h>
#include <string.h>

int main(void){
    char tipo[20], classe[20], alimentacao[20], animal[20];
    int i;

    char mapeamento_animal[8][4][20] = {
        {"aguia", "ave", "carnivoro", "vertebrado"},
        {"pomba", "ave", "onivoro", "vertebrado"},
        {"homem", "mamifero", "onivoro", "vertebrado"},
        {"vaca", "mamifero", "herbivoro", "vertebrado"},
        {"pulga", "inseto", "hematofago", "invertebrado"},
        {"lagarta", "inseto", "herbivoro", "invertebrado"},
        {"sanguessuga", "anelideo", "hematofago", "invertebrado"},
        {"minhoca", "anelideo", "onivoro", "invertebrado"}
    };

    scanf("%s", tipo);
    scanf("%s", classe);
    scanf("%s", alimentacao);

    for (i = 0; i < 8; i++) {
        if (strcmp(classe, mapeamento_animal[i][1]) == 0 && strcmp(alimentacao, mapeamento_animal[i][2]) == 0 && strcmp(tipo, mapeamento_animal[i][3]) == 0){
            strcpy(animal, mapeamento_animal[i][0]);
            break;
        }
    }
    
    printf("%s\n", animal);
}
