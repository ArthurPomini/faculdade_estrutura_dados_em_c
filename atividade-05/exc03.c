/*
EXERCICIO 3)

Construa um programa em linguagem C que aloque dinamicamente uma matriz de dimensão 5x7 
do tipo inteiro. 
Preencha a matriz com valores aleatórios no intervalo de 10 a 500. 
Em seguida, apresente todos os elementos da matriz em formato estruturado (linhas e colunas). 

Observação: 
A matriz deve ser implementada utilizando alocação dinâmica (ponteiro de ponteiro).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // ISSO DAQUI
    int **mat=(int **)malloc(5*sizeof(int *));
    // É A MESMA COISA DISSO DAQUI
    // int **mat;
    // mat=malloc(5*sizeof(int *));
    if (mat == NULL){
        printf("Erro ao alocar memoria.\n");
        return -1;
    }

    // ALOCA DINAMICAMENTE A MATRIZ 5x7 + RECEBE VALORES ALEATÓRIOS DE 0 A 99
    for (int i=0; i<5; i++) {
        int j=0;
        mat[i]=(int *)malloc(7*sizeof(int));
        do {
            mat[i][j] = rand() % 100;
            j++;
        } while (j < 7);
        if (mat[i] == NULL) {
            printf("Erro ao alocar memoria das colunas.\n");
            return -1;
        }
    }

    // APRESENTA MATRIZ
    printf("\n---MATRIZ 5x7---\n");
    for (int i=0; i<5; i++) {
        for (int j=0; j<7; j++) {
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }

    // LIBERA MEMÓRIA ALOCADA
    for (int i=0; i<5; i++) {
        free(mat[i]);
    }
    free(mat);
    
    system("pause");
    return 0;
}