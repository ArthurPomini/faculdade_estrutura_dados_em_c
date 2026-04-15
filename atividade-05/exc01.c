/*
EXERCICIO 1)

Desenvolva um programa em linguagem C que aloque dinamicamente um vetor de 10 elementos
do tipo inteiro.

Preencha o vetor com valores aleatórios.

Em seguida, apresente todos os elementos utilizando aritmética de ponteiros (sem o uso de
notação de índice).

Observação:  A alocação de memória deve ser realizada utilizando malloc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 10

int main()
{
    srand(time(NULL));

    int *vet;
    vet = malloc(tam * sizeof(int));

    if (vet)
    {
        printf("Elementos do Vetor:\n\n");
        for (int i = 0; i < tam; i++)
        {
            vet[i] = rand() % 100;
            printf("%d\n", *(vet + i));
        }

        free(vet);
    }
    else
        printf("Erro na alocacao de memoria.\n");

    system("pause");
    return 0;
}