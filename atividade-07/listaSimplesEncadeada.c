// Revisão de Lista Simples Encadeada para prova

#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
    int dado;
    struct _no *proximo;
} No;

void inserirInicio(No **topo, int num);
void inserirMeio(No *topo, int num, int ref);
void inserirFim(No **topo, int num);
void remover(No **lista, int num);
void imprimir(No *lista);

int main() {
    No *lista = NULL;
    int opcao, valor;
    do {
        system("cls");
        printf("\nLISTA SIMPLESMENTE ENCADEADA===\n");
        printf("1 - Inserir no Inicio\n");
        printf("2 - Inserir no Meio\n");
        printf("3 - Inserir no Fim\n");
        printf("4 - Remover Valor da Lista\n");
        printf("5 - Imprimir\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf(" %d", &opcao);
        switch (opcao){
        case 0:
            printf("\nSaindo do sistema...\n");
            return 0;
            break;
        case 1:
            printf("Digite o valor que deseja inserir: ");
            scanf(" %d", &valor);
            inserirInicio(&lista, valor);
            break;
        case 2:
            int ref;
            printf("Digite o valor que deseja inserir: ");
            scanf(" %d", &valor);
            printf("Digite o valor de referencia: ");
            scanf(" %d", &ref);
            inserirMeio(lista, valor, ref);
            break;
        case 3:
            printf("Digite o valor que deseja inserir: ");
            scanf(" %d", &valor);
            inserirFim(&lista, valor);
            break;
        case 4:
            printf("Digite o valor que deseja remover da lista: ");
            scanf(" %d", &valor);
            remover(&lista, valor);
            break;
        case 5:
            imprimir(lista);
            break;
        default:
            printf("Opcao Invalida, digite novamente.\n");
            break;
        }
    } while (opcao != 0);
}

// É basicamente uma pilha
void inserirInicio(No **topo, int num) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para novo no.\n");
        system("pause");
        return;
    }
    novo->dado = num;
    novo->proximo = *topo;
    *topo = novo;
    printf("\nNovo no criado no comeco da lista com sucesso!\n");
    system("pause");
}

void inserirMeio(No *topo, int num, int ref) {
    No *aux = topo;
    while (aux != NULL && aux->dado != ref) {
        aux = aux->proximo;
    }
    if (aux == NULL) {
        printf("Valor %d passado como referencia nao encontrado.\n", aux->dado);
        system("pause");
        return;
    }
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para novo no.\n");
        system("pause");
        return;
    }
    novo->dado = num;
    novo->proximo = aux->proximo;
    aux->proximo = novo;
    printf("\nNovo no criado no meio da lista com sucesso!\n");
    system("pause");
}

void inserirFim(No **topo, int num) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memoria para novo no.\n");
        system("pause");
        return;
    }
    novo->dado = num;
    novo->proximo = NULL;
    // SE a lista estiver vazia, então ela recebe novo e retorna
    if (*topo == NULL) {
        *topo = novo;
        return;
    }
    // Cria-se um ponteiro para navegar pela lista até chegar no último elemento, que aponta para NULL
    No *aux = *topo;
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    // Último da lista passa a apontar para novo;
    aux->proximo = novo;
    printf("\nNovo no criado no fim da lista com sucesso!\n");
    system("pause");
}

void remover(No **lista, int num) {
    No *atual = *lista;
    if (atual->dado == num) {
        printf("%d removido da lista.\n", num);
        *lista = atual->proximo;
        free(atual);
        system("pause");
        return;
    }
    No *anterior = NULL;
    while (atual != NULL && atual->dado != num) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) {
        printf("Valor nao encontrado na lista.\n");
        system("pause");
        return;
    }
    anterior->proximo = atual->proximo;
    free(atual);
    printf("%d removido da lista.\n", num);
    system("pause");
}

void imprimir(No *lista) {
    No *temp = lista;
    printf("Lista Simplesmente Encadeada:\n");
    while (temp != NULL) {
        printf("[ %d ]\n", temp->dado);
        temp = temp->proximo;
    }
    system("pause");
}   