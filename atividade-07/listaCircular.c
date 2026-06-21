#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _no {
    int dado;
    struct _no *anterior;
    struct _no *proximo;
} No;

//---------------------------------------------------------

bool estaVazia(No *lista);
void inserirInicio(No **topo, int num);
void inserirMeio(No *topo, int num, int ref);
void inserirFim(No **topo, int num);
void imprimir(No *lista);
void remover(No **lista, int num);
void limpaLista(No *lista);

//---------------------------------------------------------

int main() {
    No *lista = NULL;
    int opcao, valor;
    do {
        system("cls");
        printf("=====LISTA CIRCULAR=====\n");
        printf("1 - Inserir no Inicio\n");
        printf("2 - Inserir no Meio\n");
        printf("3 - Inserir no Fim\n");
        printf("4 - Imprimir\n");
        printf("5 - Remover Valor da Lista\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf(" %d", &opcao);
        switch (opcao) {
        case 0:
            printf("Saindo...\n");
            limpaLista(lista);
            return 0;
        case 1:
            printf("Digite o valor para adicionar ao comeco da lista: ");
            scanf(" %d", &valor);
            inserirInicio(&lista, valor);
            break;
        case 2:
            int ref;
            printf("Digite o valor para adicionar ao meio da lista: ");
            scanf(" %d", &valor);
            printf("Digite o valor de referencia: ");
            scanf(" %d", &ref);
            inserirMeio(lista, valor, ref);
            break;
        case 3:
            printf("Digite o valor para adicionar ao fim da lista: ");
            scanf(" %d", &valor);
            inserirFim(&lista, valor);
            break;
        case 4:
            imprimir(lista);
            break;
        case 5:
            if (estaVazia(lista)) {
                printf("\nA lista esta vazia.\n");
            } else {
                printf("Digite o valor que voce deseja remover da lista: ");
                scanf(" %d", &valor);
                remover(&lista, valor);
            }
            break;
        default:
            printf("\nValor indefinido, digite novamente.\n");
            break;
        }
    } while (opcao != 0);
}

//---------------------------------------------------------

bool estaVazia(No *lista) {
    if (lista == NULL) {
        return true;
    } else {
        return false;
    }
}

void inserirInicio(No **topo, int num) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("\nErro ao alocar memoria para novo no.\n");
        system("pause");
        return;
    }
    novo->dado = num;
    if (estaVazia(*topo)) {
        novo->proximo = novo;
        novo->anterior = novo;
        *topo = novo;
    } else {
        No *ultimo = (*topo)->anterior; // salva ultimo nó
        novo->proximo = *topo; // ponteiro proximo do novo nó passa a apontar para o topo da lista
        novo->anterior = ultimo; // ponteiro anterior do novo nó passa a apontar para o ultimo valor da lista
        (*topo)->anterior = novo; // ponteiro anterior do topo agora passa a apontar para o novo nó
        ultimo->proximo = novo; // ponteiro proximo do ultimo no passa a apontar para o novo nó
        *topo = novo; // novo nó adicionado ao topo da lista
    }
    printf("\n[ %d ] adicionado ao inicio da lista.\n", num);
    system("pause");
}

void inserirMeio(No *topo, int num, int ref) {
    if (estaVazia(topo)) {
        printf("\nA lista esta vazia. Valor de referencia nao encontrado.\n");
        system("pause");
        return;
    }
    No *temp = topo;
    bool valorEncontrado = false;
    do {
        if (temp->dado == ref) {
            valorEncontrado = true;
            break;
        }
        temp = temp->proximo;
    } while (temp != topo);
    if (valorEncontrado) {
        No *novo = malloc(sizeof(No));
        if (novo == NULL) {
            printf("\nErro ao alocar memoria para novo no.\n");
            system("pause");
            return;
        }
        novo->dado = num; // add dado para o novo nó
        novo->proximo = temp->proximo; // ponteiro próximo passa a apontar para o próximo que temp aponta
        novo->anterior = temp; // ponteiro anterior aponta para temp
        novo->proximo->anterior = novo; // ponteiro anterior do proximo nó passa apontar para novo
        temp->proximo = novo; // próximo de temp aponta para o novo nó

        printf("[ %d ] adicionado ao meio da lista.\n", num);
    } else {
        printf("\nValor de referencia nao encontrado na lista.\n");
    }
    system("pause");
}

void inserirFim(No **topo, int num) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("\nErro ao alocar memoria para novo no.\n");
        system("pause");
        return;
    }
    novo->dado = num;
    if (estaVazia(*topo)) {
        novo->proximo = novo;
        novo->anterior = novo;
        *topo = novo;
    } else {
        No *ultimo = (*topo)->anterior;
        novo->proximo = *topo; // proximo de novo passa a ser o topo da lista
        novo->anterior = ultimo; // anterior de novo passa a ser o ultimo no
        ultimo->proximo = novo; // proximo do ultimo passa a ser o novo nó
        (*topo)->anterior = novo; // ultimo nó da lista passa a ser o novo nó
    }
    printf("\n[ %d ] adicionado ao fim da lista.\n", num);
    system("pause");
}

void remover(No **lista, int num) {
    if (estaVazia(*lista)) {
        printf("\nA lista esta vazia.\n");
        system("pause");
        return;
    }
    No *atual = *lista;
    if (atual->dado == num) {
        atual->anterior->proximo = atual->proximo;
        atual->proximo->anterior = atual->anterior;
        *lista = atual->proximo;
        if (atual->proximo == atual) {
            free(atual);
            *lista = NULL;
            printf("\n[ %d ] removido da lista com sucesso.\n", num);
            system("pause");
            return;
        }
    } else {
        bool valorEncontrado = false;
        do {
            if (atual->dado == num) {
                valorEncontrado = true;
                break;
            }
            atual = atual->proximo;
        } while (atual != *lista);
        if (valorEncontrado) {
            atual->anterior->proximo = atual->proximo; // ponteiro 'proximo' do nó anterior aponta para o próximo nó (do que está sendo removido)
            atual->proximo->anterior = atual->anterior; // ponteiro 'anterior' do próximo nó aponta para o nó anteiror (do nó que está sendo removido)
        } else {
            printf("\nValor passado para remover nao encontrado na lista.\n");
            system("pause");
            return;
        }
    }
    free(atual);
    printf("\n[ %d ] removido da lista com sucesso.\n", num);
    system("pause");
}

void imprimir(No *lista) {
    if (estaVazia(lista)) {
        printf("\nA lista esta vazia.\n");
        system("pause");
        return;
    }
    No *temp = lista;
    printf("\nLISTA CIRCULAR\n");
    do {
        printf("[ %d ]\n", temp->dado);
        temp = temp->proximo;
    } while (temp != lista);
    system("pause");
}

void limpaLista(No *lista) {
    if (estaVazia(lista)) {
        return;
    }
    No *temp = lista;
    do {
        No *proximoNo = temp->proximo;
        free(temp);
        temp = proximoNo;
    } while (temp != lista);
    printf("\nLista limpa com sucesso!\n");
    system("pause");
}