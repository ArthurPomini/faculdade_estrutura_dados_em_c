#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int idade;
    char nome[30];
} Pessoa;

typedef struct _no {
    Pessoa infos;
    struct _no *proximo;
} No;

No *top = NULL;

//-----------------------------------------

void systemPause();
void push(Pessoa ex);
void pop();
void imprimir();
void limpaPilha();

//-----------------------------------------

int main() {
    int opcao;
    do {
        printf("=== PILHA1 ===\n");
        printf("1 - Push\n");
        printf("2 - Pop\n");
        printf("3 - Imprimir\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf(" %d", &opcao);
        switch (opcao) {
        case 1:
            Pessoa infos;
            printf("Digite a idade: ");
            scanf(" %d", &infos.idade);
            printf("Digite o nome: ");
            scanf(" %s", infos.nome);
            push(infos);
            break;
        case 2:
            pop();
            break;
        case 3:
            imprimir();
            break;
        case 4:
            printf("\nSaindo do sistema...\n");
            break;
        default:
            printf("Opcao Inexistente.\n");
            break;
        }
    } while (opcao != 4);

    limpaPilha();
    return 0;
}

//-----------------------------------------

void systemPause() {
    printf("\nAperte ENTER para continuar...\n");
    getchar();
    getchar();
    system("cls");
}

void push(Pessoa ex) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    novo->infos = ex;
    novo->proximo = top;
    top = novo;
    
    systemPause();
}

void pop() {
    No *temp = top;
    if (top == NULL) {
        printf("A pilha esta vazia.\n");
        systemPause();
        return;
    }
    top = temp->proximo;
    printf("%s removido da pilha.\n", temp->infos.nome);
    free(temp);

    systemPause();
}

void imprimir() {
    No *temp = top;
    if (top == NULL) {
        printf("A pilha esta vazia.\n");
        systemPause();
        return;
    }
    while (temp != NULL) {
        printf("%s - %d anos.\n", temp->infos.nome, temp->infos.idade);
        temp = temp->proximo;
    }

    systemPause();
}

void limpaPilha() {
    if (top == NULL) {
        systemPause();
        return;
    }

    No *temp = top;
    while (temp != NULL) {
        No *proximoNo = temp->proximo;
        free(temp);
        temp = proximoNo;
    }
    printf("Pilha limpa com sucesso.\n");
    systemPause();
}