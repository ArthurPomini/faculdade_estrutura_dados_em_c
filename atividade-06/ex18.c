// 18. Construa uma FILA contendo 20 valores aleatórios entre 1 e 100. 
// Posteriormente: 
// • remova os valores múltiplos de 5;  
// • apresente a fila final.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _no {
    int dado;
    struct _no *proximo;
} No;

No *inicio = NULL;
No *fim = NULL;

//-----------------------------------------------

void systemPause();
void pushVinteValoresAleatorios();
void popMultiplosCinco();
void imprimir();

//-----------------------------------------------

int main() {
    srand(time(NULL));
    pushVinteValoresAleatorios();
    popMultiplosCinco();
    imprimir();
}

//-----------------------------------------------

void systemPause() {
    printf("\nAperte ENTER para continuar...\n");
    getchar();
    getchar();
    system("cls");
}

void pushVinteValoresAleatorios() {
    for (int i=0; i<20; i++) {
        No *novo = malloc(sizeof(No));

        novo->dado = rand() % 100 + 1;
        novo->proximo = NULL;
        if (inicio == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->proximo = novo;
            fim = novo;
        }
    }
    printf("\n20 Valores Aleatorios Adicionados A Fila!\n");
    systemPause();
}

void popMultiplosCinco() {
    No *atual = inicio;
    No *anteriorNo = NULL;
    int i=0;
    while (atual != NULL) {
        if (atual->dado % 5 == 0 && atual == inicio) {
            No *proximoNo = atual->proximo;
            free(atual);
            atual = proximoNo;
            inicio = atual;
            i++;
        } else if (atual->dado % 5 == 0 && atual == fim) {
            No *proximoNo = atual->proximo;
            anteriorNo->proximo = atual->proximo;
            free(atual);
            atual = proximoNo;
            fim = anteriorNo;
            i++;
        } else if (atual->dado % 5 == 0) {
            No *proximoNo = atual->proximo;
            anteriorNo->proximo = atual->proximo;
            free(atual);
            atual = proximoNo;
            i++;
        } else {
            anteriorNo = atual;
            atual = atual->proximo;
        }
    }
    printf("\n%d valor(es) removido(s) da fila.\n", i);
    systemPause();
}

void imprimir() {
    No *temp = inicio;

    while (temp != NULL) {
        printf("[ %d ] -> ", temp->dado);
        temp = temp->proximo;
    }
    systemPause();
}