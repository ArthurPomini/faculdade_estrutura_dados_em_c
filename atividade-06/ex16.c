// 16. Construa um programa em linguagem C que implemente uma PILHA através 
// de 10 elementos (entre 10 e 100) gerados randomicamente (não repetidos). 
// Posteriormente, apresente o conteúdo da pilha.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _no {
    int dado;
    struct _no *proximo;
} No;

No *top = NULL;

//------------------------------------------------

void systemPause();
void push();
void imprimir();

//------------------------------------------------

int main() {
    srand(time(NULL));
    push();
    imprimir();
    systemPause();
    return 0;
}

//------------------------------------------------

void systemPause() {
    printf("\nAperte ENTER para continuar...\n");
    getchar();
    getchar();
    system("cls");
}

void push() {
    for (int i=0; i<10; i++) {
        No *novo = malloc(sizeof(No));

        if (novo == NULL) {
            printf("Erro ao alocar memoria para novo no.\n");
            systemPause();
            return;
        }

        novo->dado = rand() % 91 + 10;
        No *temp = top;
        while (temp != NULL && i > 0) {
            while (novo->dado == temp->dado) {
                novo->dado = rand() % 91 + 10;
            }
            temp = temp->proximo;
        }
        novo->proximo = top;
        top = novo;
    }
}

void imprimir() {
    No *temp = top;
    printf("PILHA\n");
    while (temp != NULL) {
        printf("[ %d ]\n", temp->dado);
        temp = temp->proximo;
    }
}