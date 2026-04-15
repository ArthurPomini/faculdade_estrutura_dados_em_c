/*
EXERCICIO 5)

Desenvolva um programa em linguagem C que aloque dinamicamente um vetor de N elementos 
do tipo float, sendo N informado pelo usuário. 

O programa deverá preencher o vetor com valores reais informados pelo usuário. Em seguida, 
utilizando aritmética de ponteiros (sem uso de índice), calcule e apresente: 
• A média dos valores  
• O maior valor armazenado  
• O menor valor armazenado  

Observações: 
• Utilizar malloc ou calloc para alocação  
• Não utilizar notação de índice (v[i]) para percorrer o vetor  
• Liberar a memória ao final do programa 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Quantos elementos deseja alocar em um vetor?\nR: ");
    scanf(" %d", &n);

    float *vet = (float *) malloc(n * sizeof(float));

    float media=0;
    float maior;
    float menor;
    printf("Atribuindo valores:\n");
    for (int i=0; i<n; i++) {
        printf("%do: ", i+1);
        scanf(" %f", (vet+i));

        media += *(vet+i);
    }
    media /= n;

    maior = *(vet+0);
    menor = *(vet+0);
    for (int i=0; i<n; i++) {
        if (*(vet+i) > maior)
            maior = *(vet+i);
        if (*(vet+i) < menor)
            menor = *(vet+i);
    }

    printf("\n");
    printf("Valores recebidos:\n");
    for (int i=0; i<n; i++) {
        printf("%do = %.1f\n", i+1, *(vet+i));
    }
    printf("\n");
    printf("Media dos valores registrados: %.1f\n", media);
    printf("Maior valor registrado: %.1f\n", maior);
    printf("Menor valor registrado: %.1f\n", menor);

    free(vet);
    system("pause");
    return 0;
}