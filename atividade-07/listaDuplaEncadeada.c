// Revisão de Lista Duplamente Encadeada para prova

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _no {
    int dado;
    struct _no *proximo;
    struct _no *anterior;
} No;

//------------------------------------------------------------------------------------------

bool estaVazia(No *lista);
void inserirInicio(No **topo, int num);
void inserirMeio(No *topo, int num, int ref);
void inserirFim(No **topo, int num);
void imprimirCimaBaixo(No *topo);
void imprimirBaixoCima(No *topo);
void remover(No **lista, int num);
void limpaLista(No *topo);

//------------------------------------------------------------------------------------------

int main() {
    No *lista = NULL;
    int opcao, valor;
    do {
        system("cls");
        printf("===LISTA DUPLAMENTE ENCADEADA===\n");
        printf("1 - Inserir no Inicio\n");
        printf("2 - Inserir no Meio\n");
        printf("3 - Inserir no Fim\n");
        printf("4 - Imprimir (Cima para Baixo) [TESTAR PONTEIRO PROXIMO]\n");
        printf("5 - Imprimir (Baixo para Cima) [TESTAR PONTEIRO ANTERIOR]\n");
        printf("6 - Remover Valor da Lista\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf(" %d", &opcao);
        switch (opcao) {
        case 0:
            printf("Saindo do sistema...\n");
            limpaLista(lista);
            return 0;
        case 1:
            printf("Digite um valor para adicionar ao inicio da lista: ");
            scanf(" %d", &valor);
            inserirInicio(&lista, valor);
            break;
        case 2:
            int ref;
            printf("Digite um valor para adicionar ao meio da lista: ");
            scanf(" %d", &valor);
            printf("Digite um valor de referencia: ");
            scanf(" %d", &ref);
            inserirMeio(lista, valor, ref);
            break;
        case 3:
            printf("Digite um valor para adicionar ao fim da lista: ");
            scanf(" %d", &valor);
            inserirFim(&lista, valor);
            break;
        case 4:
            imprimirCimaBaixo(lista);
            break;
        case 5:
            imprimirBaixoCima(lista);
            break;
        case 6:
            printf("Digite o valor que quer remover da lista: ");
            scanf(" %d", &valor);
            remover(&lista, valor);
            break;
        default:
            printf("Opcao invalida, digite novamente.\n");
            break;
        }
    } while (opcao != 0);
}

//------------------------------------------------------------------------------------------

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
    novo->anterior = NULL;
    novo->proximo = *topo;
    // SE a lista NÃO estiver vazia, então conserta o ponteiro anterior do topo da lista
    if (!estaVazia(*topo)) {
        (*topo)->anterior = novo;
    }
    *topo = novo;
    printf("[ %d ] adicionado ao inicio da lista com sucesso!\n", num);
    system("pause");
}

void inserirMeio(No *topo, int num, int ref) {
    if (estaVazia(topo)) {
        printf("\nA lista esta vazia. Valor de referencia nao encontrado.\n");
        system("pause");
        return;
    }
    No *aux = topo;
    while (aux != NULL && aux->dado != ref) {
        aux = aux->proximo;
    }
    if (aux == NULL) {
        printf("Valor de referencia nao encontrado.\n");
        system("pause");
        return;
    }
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("\nErro ao alocar memoria para novo no.\n");
        system("pause");
        return;
    }
    novo->dado = num;
    novo->proximo = aux->proximo; // atualiza ponteiro novo para apontar para o proximo
    novo->anterior = aux; // ponteiro anterior passa a apontar para a referencia
    if (aux->proximo != NULL) { // SE o proximo elemento NÃO for NULO, então, o ponteiro anterior do proximo passa a apontar para novo
        aux->proximo->anterior = novo;
    }
    aux->proximo = novo; // proximo passa a apontar para novo
    printf("[ %d ] adicionado ao meio da lista com sucesso!\n", num);
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
        novo->anterior = NULL;
        novo->proximo = NULL;
        *topo = novo;
        printf("[ %d ] adicionado a lista com sucesso!\n", num);
    } else {
        No *aux = *topo;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        novo->anterior = aux;
        printf("[ %d ] adicionado ao fim da lista com sucesso!\n", num);
    }
    system("pause");
}

void imprimirCimaBaixo(No *topo) {
    if (estaVazia(topo)) {
        printf("\nA lista esta vazia.\n");
        system("pause");
        return;
    }
    No *aux = topo;
    printf("Imprimindo de Cima para Baixo...\n");
    while (aux != NULL) {
        printf("[ %d ]\n", aux->dado);
        aux = aux->proximo;
    }
    system("pause");
}

void imprimirBaixoCima(No *topo) {
    if (estaVazia(topo)) {
        printf("\nA lista esta vazia.\n");
        system("pause");
        return;
    }
    No *aux = topo;
    printf("Imprimindo de Baixo para Cima...\n");
    while (aux->proximo != NULL) {
        aux = aux->proximo;
    }
    while (aux != NULL) {
        printf("[ %d ]\n", aux->dado);
        aux = aux->anterior;
    }
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
        if (atual->proximo != NULL) {
            atual->proximo->anterior = atual->anterior;
        }
        *lista = atual->proximo;
    } else {
        while (atual != NULL && atual->dado != num) {
            atual = atual->proximo;
        }
        if (atual == NULL) {
            printf("\nValor nao encontrado na lista.\n");
            system("pause");
            return;
        }
        atual->anterior->proximo = atual->proximo;
        if (atual->proximo != NULL) {
            atual->proximo->anterior = atual->anterior;
        }
    }
    printf("\n%d removido da lista.\n", num);
    free(atual);
    system("pause");
}

//------------------------------------------------------------------------------------------

void limpaLista(No *topo) {
    if (estaVazia(topo)) {
        return;
    }
    No *aux = topo;
    while (aux != NULL) {
        No *proximoNo = aux->proximo;
        free(aux);
        aux = proximoNo;
    }
    printf("\nLista limpa com sucesso.\n");
    system("pause");
}