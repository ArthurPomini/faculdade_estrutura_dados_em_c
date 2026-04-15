/*
EXERCÍCIO 4)

Desenvolva um programa em linguagem C que aloque dinamicamente um vetor de números 
inteiros, inicialmente com capacidade para armazenar 5 elementos. 

O programa deverá solicitar ao usuário a inserção de valores inteiros, armazenando-os no vetor. 

Sempre que a capacidade máxima for atingida, o vetor deverá ser redimensionado 
dinamicamente, dobrando seu tamanho por meio da função realloc. 

A inserção de dados deverá continuar até que o usuário informe um valor negativo, que indicará o 
encerramento da entrada de dados. 

Ao final, o programa deverá: 
• Apresentar todos os elementos armazenados  
• Informar a quantidade total de elementos inseridos  
• Informar o tamanho final do vetor alocado  
• Informar se houve mudança de endereçamento na realocação. 

Observações: 
• A alocação inicial deve ser realizada com malloc  
• O redimensionamento deve utilizar obrigatoriamente realloc  
• O programa deve garantir que não haja perda de dados durante a realocação  
• Recomenda-se o uso de uma variável auxiliar ao utilizar realloc 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int tam=5;

    int *vet=(int *) malloc(tam*sizeof(int));
    if (vet == NULL) {
        printf("Erro ao alocar memoria.\n");
        return -1;
    }

    int i=-1;
    int x=0;
    int valor;
    printf("Adicionando valores:\n");
    do {
        i++;

        printf("%do: ", i+1);
        scanf(" %d", &valor);

        // AUMENTA TAMANHO DO VETOR SE PRECISAR DE MAIS
        if (i == tam && valor >= 0) {
            int *ptr = vet;
            tam *= 2;
            int *temp=(int *) realloc(vet, tam*sizeof(int));
            if (temp == NULL) {
                printf("Erro ao aumentar memoria do vetor.\n");
                return -1;
            }
            
            // COMPARA ENDERECO ANTIGO COM O NOVO PARA DESCOBRIR SE HOUVE MUDANCA
            vet = temp;
            if (ptr != vet)
                x++;
            printf("Vetor aumentado para %d espacos!\n", tam);
        }

        vet[i] = valor;
    } while (vet[i] >= 0);

    printf("\n---Apresentando valores---\n");
    for (int j=0; j<tam; j++) {
        printf("%do = %d\n", j+1, vet[j]);
    }
    printf("\n");
    printf("\nElementos Inseridos: %d\n", i);
    printf("Tamanho final do vetor: %d\n", tam);
    printf("Houve mudanca no enderecamento do vetor: ");
    if (x > 0)
        printf("sim.\n");
    else
        printf("nao.\n");

    free(vet);
    printf("\n");
    printf("Memoria liberada!\n");
    printf("Fechando sistema...\n");

    system("pause");
    return 0;
}