/*
EXERCICIO 6)

Desenvolva um programa em linguagem C que aloque dinamicamente uma matriz de inteiros com 
dimensões M x N, sendo M e N informados pelo usuário. 

Após a alocação, o programa deverá preencher a matriz com valores inteiros informados pelo usuário. 

Em seguida, calcule e apresente: 
• A soma dos elementos de cada linha  
• A soma total de todos os elementos da matriz  

Observações: 
• A matriz deve ser implementada utilizando ponteiro de ponteiro (int **)  
• Utilizar malloc ou calloc  
• Apresentar a matriz no formato estruturado (linhas e colunas)  
• Liberar toda a memória alocada ao final
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m;
    int n;

    printf("Quantas linhas quer na sua matriz?\nR: ");
    scanf(" %d", &m);
    printf("Quantas colunas quer na sua matriz?\nR: ");
    scanf(" %d", &n);

    int **mat = (int **) malloc(m*sizeof(int *));
    if (mat == NULL) {
        printf("Erro ao alocar memoria.\n");
        return -1;
    }
    for (int i=0; i<m; i++) {
        *(mat+i) = (int *) malloc(n*sizeof(int));

        if (*(mat+i) == NULL) {
            printf("Erro ao alocar memoria.\n");
            return -1;
        }
    }

    int tot[m];
    int totalSoma=0;
    printf("Atribuindo valores para a matriz:\n");
    for (int i=0; i<m; i++) {
        tot[i] = 0;
        for (int j=0; j<n; j++) {
            printf("%dx%d: ", i+1, j+1);
            scanf(" %d", (*(mat+i)+j));
            tot[i] += *(*(mat+i)+j);
            totalSoma += *(*(mat+i)+j);
        }
    }

    printf("\n");
    printf("--- {RESULTADOS OBTIDOS} ---\n\n");
    printf("Matriz %dx%d\n", m+1, n+1);
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++)
            printf(" %d ", *(*(mat+i)+j));
        printf("\n");
    }
    printf("\n");
    for (int i=0; i<m; i++)
        printf("Soma da linha %d = %d\n", i+1, tot[i]);
    printf("Soma total dos elementos da matriz = %d\n", totalSoma);

    for (int i=0; i<m; i++)
        free((mat+i));
    free(mat);
    
    system("pause");
    return 0;
}