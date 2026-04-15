/*
EXERCICIO 2)

Desenvolva um programa em linguagem C que aloque dinamicamente um vetor (v1) contendo N 
elementos do tipo inteiro, sendo N informado pelo usuário. 

Após o preenchimento do vetor v1, crie dinamicamente um segundo vetor (v2) que contenha 
apenas os valores pares presentes em v1. 

Ao final, o programa deverá: 
• Apresentar os elementos dos dois vetores  
• Exibir o endereço de memória de cada elemento  

Observações: 
• Ambos os vetores devem utilizar alocação dinâmica  
• O vetor v2 deve possuir tamanho compatível com a quantidade de números pares encontrado 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int n;

    printf("Quantos elementos deseja alocar em um vetor?\nR: ");
    scanf(" %d", &n);

    int *vet;
    vet=malloc(n*sizeof(int));
    if (vet == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return;
    }

    // ALOCAÇÃO MEMÓRIA + INSERÇÃO DE VALORES
    int par=0;
    
    for (int i=0; i<n; i++) {
        vet[i] = rand() % 100;
        if (vet[i] % 2 == 0)
            par++;
    }

    int *vet2;
    vet2=malloc(par*sizeof(int));
    if (vet2 == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return;
    }

    int j=0;
    for (int i=0; i<n; i++) {
        if (vet[i] % 2 == 0) {
            vet2[j] = vet[i];
            j++;
        }
    }

    // APRESENTANDO VALORES
    printf("\n---Vetor 1---\n");
    for (int i=0; i<n; i++) {
        printf("%d\n", *(vet+i));
    }
    
    printf("\n---Vetor 2---\n");
    for (int i=0; i<par; i++) {
        printf("%d\n", *(vet2+i));
    }

    free(vet);
    free(vet2);

    system("pause");
    return 0;
}