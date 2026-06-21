#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _no {
    char caracter;
    struct _no *proximo;
} No;

No *top = NULL;

//----------------------------------------

void systemPause();
void push(char c);
char pop();
void limpaPilha();

//----------------------------------------

int main() {
    char expres[256];
    printf("Digite uma expressao matematica: ");
    scanf(" %s", expres);
    int tam = strlen(expres);
    for (int i=0; i<tam; i++) {
        push(expres[i]);
    }
    int j=0;
    for (int i=0; i<tam; i++) {
        char c = pop();
        if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}') {
            j++;
        }
    }
    if (j % 2 == 0) {
        printf("Sua expressao esta balanceada corretamente.\n");
    } else {
        printf("A expressao digitada nao esta balanceada.\n");
    }
    limpaPilha();
    return 0;
}

void systemPause() {
    printf("\nAperte ENTER para continuar...\n");
    getchar();
    getchar();
}

void push(char c) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("\nErro ao alocar memoria.\n");
        systemPause();
        return;
    }
    novo->caracter = c;
    novo->proximo = top;
    top = novo;
}

char pop() {
    No *temp = top;
    top = temp->proximo;
    return temp->caracter;
}

void limpaPilha() {
    No *temp = top;
    while (temp != NULL) {
        No *proximoNo = temp->proximo;
        free(temp);
        temp = proximoNo;
    }
    printf("Pilha esvaziada.\n");
    systemPause();
}