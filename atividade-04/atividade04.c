/*
2) Construa um código em linguagem C que gere randomicamente 10 
valores aleatórios (não repetidos) para um vetor de inteiros. 
Posteriormente, apresente os valores utilizando aritmética de ponteiro. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int qtd=10;
    int *vet = (int *) malloc(qtd*sizeof(int));

    printf("Vetor com valores aleatorios:\n\n");
    for (int i=0; i<qtd; i++) {
        vet[i] = rand() % 100;
        for (int j=0; j<i; j++) {
            if (vet[j] == vet[i]) {
                while (vet[j] == vet[i]) {
                    vet[i] = rand() % 100;
                }
                break;
            }
        }
        printf("%d\n", vet[i]);
    }

    system("pause");
    return 0;
}