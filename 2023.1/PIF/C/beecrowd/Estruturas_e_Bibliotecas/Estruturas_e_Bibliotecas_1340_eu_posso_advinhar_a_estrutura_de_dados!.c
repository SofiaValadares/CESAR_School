#include <stdio.h>

int indice(int k, int lista[k], int valor);
int indice2(int k, int lista[k], int valor);
int maior_nun(int k, int lista[k]);
void printlist(int k, int lista[k]);

int main(void){
    int nun;
    int opcao, valor;
    int comp = 0;
    int ind, ind2;
    int st=0, qu=0, pq=0;
    int maior;

    while(scanf("%d", &nun) == 1){
        int lista[nun], k=0, z=0;
        
        for(int i = 0; i<nun; i++){
            scanf("%d %d", &opcao, &valor);

            if(opcao == 1){
                lista[k] = 0;
                lista[k] = valor;
                k++;
            }else{
                ind = 0;
                ind2 = 0;
                ind += indice(k, lista, valor);
                ind2 += indice2(k, lista, valor);

                if(ind != -1){
                    
                    if(ind == 0){
                        qu++;
                    }
                    if(ind2==k-1){
                        st++;
                    }
                    
                    maior = 0;
                    maior = maior_nun(k, lista);
                    if(lista[ind] == maior){
                        pq++;
                    }
                    

                    z++;

                    for(int j=ind; j <k-1; j++){
                        lista[j] = lista[j+1];
                    }
                    k-=1;
                }
                else{
                    z-= 999999;
                }
            }
        }

        if(qu==z){
            comp++;
        }
        if(st==z){
            comp+=2;
        }
        if(pq==z){
            comp+=4;
        }
        if(z<0){
            comp=0;
        }
        
        if(comp == 1){
            printf("queue\n");
        }else if(comp == 2){
            printf("stack\n");
        }else if(comp == 4){
            printf("priority queue\n");
        }else if(comp == 0){
            printf("impossible\n");
        }else{
            printf("not sure\n");
        }

        st = 0;
        qu = 0;
        pq = 0;
        comp = 0;
    }
}

int indice(int k, int lista[k], int valor){
    int ind = -1;

    for(int i=0; i<k; i++){
        if(lista[i] == valor){
            ind = i;
            break;
        }
    }

    return ind;
}

int indice2(int k, int lista[k], int valor){
    int ind = -1;

    for(int i=0; i<k; i++){
        if(lista[i] == valor){
            ind = i;
        }
    }

    return ind;
}

int maior_nun(int k, int lista[k]){
    int maior = -99999;

    for(int i=0; i<k; i++){
        if(lista[i]>maior){
            maior = lista[i];
        }
    }

    return maior;
}

void printlist(int k, int lista[k]){
    printf("Lista: ");

    for(int i=0; i<k; i++){
        printf("%d, ", lista[i]);
    }

    printf("\n");
}