#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    /*
    1. Entrada de dados e validação (0,2 pontos)
    Solicite ao usuário a quantidade de linhas e colunas de uma matriz de números inteiros, respeitando os seguintes limites:
    •	Linhas: mínimo de 3 e máximo de 6
    •	Colunas: mínimo de 4 e máximo de 8
    Valide os valores informados, garantindo que estejam dentro dos intervalos especificados.
    */
    
    int l;
    int c;
    do {
        printf("Digite a quantidade de linhas que a matriz tera (min 3 max 6): ");
        scanf(" %d", &l);
    } while (l < 3 || l > 6);

    do {
        printf("Digite a quantidade de colunas que a matriz tera (min 4 max 8): ");
        scanf(" %d", &c);
    } while (c < 4 || c > 8);
    
    /*
    2. Alocação dinâmica da matriz (0,3 pontos)
    Aloque dinamicamente uma matriz de inteiros de acordo com as dimensões informadas pelo usuário.
    */

    int **mat = (int **) malloc(l * sizeof(int *));
    if (mat == NULL) {
        printf("Erro ao alocar memoria.\n");
        return -1;
    }
    for (int i=0; i<l; i++) {
        mat[i] = (int *) malloc(c * sizeof(int));
        if (mat[i] == NULL) {
            printf("Erro ao alocar memoria.\n");
            return -1;
        }
    }

    /*
    3. Preenchimento da matriz (0,2 pontos)
    Preencha a matriz com valores inteiros aleatórios no intervalo de 10 a 100.

    4. Exibição da matriz (0,2 pontos)
    Apresente a matriz na tela de forma organizada, exibindo seus elementos em formato de linhas e colunas.
    */

    printf("\n");
    printf("Matriz preenchida!\n\n");
    printf("Matrix %dx%d\n", l, c);
    for (int i=0; i<l; i++) {
        for (int j=0; j<c; j++) {
            mat[i][j] = (rand() % 91) + 10;
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }

    /*
    5. Vetor dinâmico com dados da matriz (0,2 pontos)
    Aloque dinamicamente um vetor e copie todos os elementos da matriz para esse vetor.
    */

    int *vet = (int *) malloc((l*c) * sizeof(int));

    if (vet == NULL) {
        printf("Erro ao alocar memoria.\n");
        return -1;
    }

    int x=0;
    for (int i=0; i<l; i++) {
        for (int j=0; j<c; j++) {
            vet[x] = mat[i][j];
            x++;
        }
    }

    /*
    6. Ordenação do vetor (0,2 pontos)
    Ordene o vetor em ordem crescente, utilizando um algoritmo de ordenação de sua escolha (por exemplo: Bubble Sort, Selection Sort, entre outros).
    */

    // VETOR ORDENADA COM BUBBLE SORT
    int temp;
    for (int i=0; i<(l*c)-1; i++) {
        for (int j=0; j<(l*c)-i-1; j++) {
            if (vet[j] > vet[j+1]) {
                temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
    }

    printf("\n");
    printf("Vetor com os dados da matriz:\n");
    for (int i=0; i<(l*c); i++) {
        printf("%d\n", vet[i]);
    }
    printf("\n");

    /*
    7. Menor e maior valor (0,1 ponto)
    Apresente o menor e o maior valor armazenados na matriz.
    */

    int maior = vet[0];
    int menor = vet[0];
    for (int i=0; i<(l*c); i++) {
        if (vet[i] > maior)
            maior = vet[i];
        if (vet[i] < menor)
            menor = vet[i];
    }
    printf("Maior valor da matriz: %d\n", maior);
    printf("Menor valor da matriz: %d\n", menor);
    printf("\n");

    /*
    8. Liberação de memória (0,1 ponto)
    Libere corretamente toda a memória alocada dinamicamente ao final do programa.
    */

    for (int i=0; i<l; i++)
        free(mat[i]);
    free(mat);
    free(vet);

    /*
    Observações Importantes
    •	Utilize funções da biblioteca <stdlib.h> para alocação dinâmica (malloc, calloc, realloc), free para liberação da memória e rand()para geração de nos aleatórios.
    •	Recomenda-se utilizar srand(time(NULL)) (biblioteca <time.h>) para inicializar a geração de números aleatórios.
    •	A organização, clareza e funcionamento correto do programa serão considerados na avaliação
    */

    system("pause");
    return 0;
}