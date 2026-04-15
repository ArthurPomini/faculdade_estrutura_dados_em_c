/*
EXERCICIO 7)

Desenvolva um programa em linguagem C que aloque dinamicamente um vetor de N elementos 
do tipo inteiro, sendo N informado pelo usuário. 

Após o preenchimento do vetor, o programa deverá remover todos os elementos ímpares, mantendo 
apenas os valores pares. Para isso, o vetor deve ser redimensionado dinamicamente utilizando 
realloc, de modo que sua capacidade final corresponda exatamente à quantidade de elementos 
pares. 

Ao final, o programa deverá: 
• Apresentar o vetor original  
• Apresentar o vetor resultante contendo apenas números pares  
• Informar o tamanho inicial e o tamanho final do vetor  

Observações: 
• Utilizar malloc para alocação inicial  
• Utilizar obrigatoriamente realloc para redimensionamento  
• Garantir que não haja perda de dados  
• Liberar a memória ao final do programa 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int n;
    printf("Digite quantos elementos seu vetor tera: ");
    scanf(" %d", &n);

    int *vetOriginal = (int *) malloc(n * sizeof(int));
    if (vetOriginal == NULL) {
        printf("Erro ao alocar memoria.\n");
        return -1;
    }

    int *vetResultante = (int *) malloc(n * sizeof(int));
    if (vetResultante == NULL) {
        printf("Erro ao alocar memoria.\n");
        return -1;
    }

    int par=0;
    int j=0;
    for (int i=0; i<n; i++) {
        vetOriginal[i] = (rand() % 100) + 10;
        if (vetOriginal[i] % 2 == 0) {
            par++;
            vetResultante[j] = vetOriginal[i];
            j++;
        }
    }

    int *temp = realloc(vetResultante, par * sizeof(int));
    vetResultante = temp;

    printf("\n");
    printf("---RESULTADOS OBTIDOS---\n");
    printf("Vetor Original:\n");
    for (int i=0; i<n; i++)
        printf("%do: %d\n", i+1, vetOriginal[i]);
    printf("Vetor Resultante (somente pares):\n");
    for (int i=0; i<par; i++)
        printf("%do: %d\n", i+1, vetResultante[i]);
    printf("Tamanho inicial do vetor: %d\n", n);
    printf("Tamanho final do vetor: %d\n", par);

    system("pause");
    return 0;
}