// 19. Utilizando PILHA, desenvolva um programa que verifique se uma palavra é 
// palíndromo. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _no {
    char letra;
    struct _no *proximo;
} No;

No *top = NULL;

void systemPause();
void push(char let);
char pop();
void imprimir();

int main() {
    char palavra[256];
    printf("Digite uma palavra: ");
    scanf(" %s", palavra);
    int tam = strlen(palavra);
    for (int i=0; i<tam; i++) {
        push(palavra[i]);
    }
    char palavraPop[tam];
    for (int i=0; i<tam; i++) {
        palavraPop[i] = pop();
    }
    palavraPop[tam] = '\0';
    printf("Palavra Invertida: %s", palavraPop);
    if (strcmp(palavra, palavraPop) == 0) {
        printf("\nEh um palindromo!\n");
    } else {
        printf("\nNao eh um palindromo.\n");
    }


    return 0;
}

void systemPause() {
    printf("\nAperte ENTER para continuar...\n");
    getchar();
    getchar();
}

void push(char let) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para novo no.\n");
        systemPause();
        return;
    }
    novo->letra = let;
    novo->proximo = top;
    top = novo;
}

char pop() {
    No *temp = top;
    top = temp->proximo;
    return temp->letra;
}