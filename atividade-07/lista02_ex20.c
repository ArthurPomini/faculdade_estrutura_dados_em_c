#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAXALUNOS 10

//------------------------------------------------------------------------------

typedef struct {
    char nome[40];
    char ra[10];
    bool pizzaRetirada;
} Aluno;

typedef struct {
    int qtd;
    char sabor[20];
} Pizza;

//------------------------------------------------------------------------------

typedef struct no_pilha {
    Pizza infos;
    struct no_pilha *proximo;
} No_P;

typedef struct no_fila {
    Aluno infos;
    struct no_fila *proximo;
} No_F;

typedef struct no_lista {
    Aluno infos;
    struct no_lista *proximo;
    struct no_lista *anterior;
} No_L;

//------------------------------------------------------------------------------

void push(No_P **topo, Pizza pizza);
void pop(No_P **topo);
void imprimirPilha(No_P *topo);
void limpaPilha(No_P *topo);

//------------------------------------------------------------------------------

Aluno buscaAluno(char nome[], No_L *lista);
void enqueue(No_F **inicio, No_F **fim, Aluno aluno);
void dequeue(No_F **inicio);
void imprimirFila(No_F *inicio);
void limpaFila(No_F *inicio);

//------------------------------------------------------------------------------

void inserirInicio(No_L **topo, Aluno aluno);
void inserirMeio(No_L *lista, Aluno aluno, char anterior[]);
void inserirFim(No_L **lista, Aluno aluno);
void imprimirLista(No_L *lista);
void limpaLista(No_L *lista);

//------------------------------------------------------------------------------

bool listaEstaVazia(No_L *lista);
bool filaEstaVazia(No_F *fila);
bool pilhaEstaVazia(No_P *pilha);
int menuSorteados();
int menuInserir();
int menuRetirada();
Aluno cadastrarAluno();
int menuPizzas();
void atualizaRetirada(No_F *inicio, No_L **lista);

//------------------------------------------------------------------------------

int main() {
    No_P *topoPilha = NULL;
    No_F *inicioFila = NULL;
    No_F *fimFila = NULL;
    No_L *lista = NULL;
    int opcao;
    int i=0;
    do {
        system("cls");
        printf("=== Sistema dos Formandos de TI ===\n");
        printf("| 1 - Gerenciar Sorteados          |\n");
        printf("| 2 - Gerenciar Pizzas             |\n");
        printf("| 3 - Fila P/ Retirada da Pizza    |\n");
        printf("| 0 - Sair                         |\n");
        printf("===================================\n");
        printf(" Opcao: ");
        scanf(" %d", &opcao);
        switch (opcao) {
        case 0:
            printf("Saindo do sistema...\n");
            limpaLista(lista);
            limpaFila(inicioFila);
            limpaPilha(topoPilha);
            return 0;
            break;
        case 1:             // GERENCIAR SORTEADOS
            int n;
            do {
                n = menuSorteados();
                switch (n) {
                case 0:
                    break;
                case 1:
                    if (i == MAXALUNOS) {
                        printf("\nNumero maximo de alunos sorteados cadastrados.\n");
                        system("pause");
                        break;
                    }
                    Aluno aluno;
                    aluno = cadastrarAluno();
                    int m;
                    m = menuInserir();
                    do {
                        switch (m) {
                        case 1:
                            inserirInicio(&lista, aluno);
                            break;
                        case 2:
                            char anterior[40];
                            do {
                                printf("Deseja colocar depois de quem?\n");
                                scanf(" %s", anterior);
                                if (strlen(aluno.nome) > 40) {
                                    printf("Nome muito extenso. Escreva um nome menor, por favor.\n");
                                    system("pause");
                                }
                            } while (strlen(anterior) > 40);
                            inserirMeio(lista, aluno, anterior);
                            break;
                        case 3:
                            inserirFim(&lista, aluno);
                            break;
                        default:
                            printf("\nOpcao Invalida. Digite Novamente.\n");
                            break;
                        }
                    } while (m != 1 && m != 2 && m != 3);
                    i++;
                    break;
                case 2:
                    imprimirLista(lista);
                    break;
                default:
                    printf("\nOpcao Invalida. Digite Novamente.\n");
                    break;
                }
            } while (n != 0);
            break;
        case 2:             // GERENCIAR PIZZAS
            int j;
            do {
                j = menuPizzas();
                switch (j) {
                case 0:
                    break;
                case 1:
                    Pizza pizza;
                    do {
                        printf("\nQual o sabor da pizza?\n");
                        scanf(" %s", pizza.sabor);
                        if (strlen(pizza.sabor) > 20) {
                            printf("\nNome muito extenso, digite um nome mais basico.\n");
                        }
                    } while (strlen(pizza.sabor) > 20);
                    do {
                        printf("Quantas?\n");
                        scanf(" %d", &pizza.qtd);
                        if (pizza.qtd > 5) {
                            printf("\nValor muito grande, digite um valor menor.\n");
                        }
                    } while (pizza.qtd > 5);
                    push(&topoPilha, pizza);
                    break;
                case 2:
                    pop(&topoPilha);
                    break;
                case 3:
                    imprimirPilha(topoPilha);
                    break;
                default:
                    printf("\nOpcao Invalida. Digite Novamente.\n");
                    break;
                }
            } while (j != 0);
            break;
        case 3:             // FILA PARA RETIRADA
            int k;
            do {
                k = menuRetirada();
                switch (k) {
                case 0:
                    break;
                case 1:
                    if (filaEstaVazia(inicioFila)) {
                        printf("\nA fila esta vazia.\n");
                        system("pause");
                    } else {
                        Aluno entra;
                        char name[40];
                        do {
                            printf("\nDigite o nome do aluno que deseja inserir na fila: ");
                            scanf(" %s", name);
                            entra = buscaAluno(name, lista);
                            if (strcmp(entra.nome, "ERROR") == 0) {
                                printf("\nNome nao encontrado na lista. Digite um nome valido.\n");
                            } else {
                                enqueue(&inicioFila, &fimFila, entra);
                            }
                        } while (strcmp(entra.nome, "ERROR") == 0);
                    }
                    break;
                case 2: // REALIZAR ENTREGA
                    if (filaEstaVazia(inicioFila)) {
                        printf("\nA fila esta vazia.\n");
                        system("pause");
                    } else {
                        atualizaRetirada(inicioFila, &lista); // ATUALIZA STATUS PIZZARETIRADA
                        pop(&topoPilha); // REMOVE A PIZZA DA PILHA
                        dequeue(&inicioFila); // REMOVE O ALUNO DA FILA
                    }
                    break;
                case 3:
                    imprimirFila(inicioFila);
                    break;
                default:
                    printf("\nOpcao Invalida. Digite Novamente.\n");
                    break;
                }
            } while (k != 0);
            break;
        default:
            printf("\nOpcao Invalida. Digite Novamente.\n");
            break;
        }
    } while (opcao != 0);
}

//------------------------------------------------------------------------------

bool listaEstaVazia(No_L *lista) {
    if (lista == NULL) {
        return true;
    } else {
        return false;
    }
}

bool filaEstaVazia(No_F *fila) {
    if (fila == NULL) {
        return true;
    } else {
        return false;
    }
}

bool pilhaEstaVazia(No_P *pilha) {
    if (pilha == NULL) {
        return true;
    } else {
        return false;
    }
}

int menuSorteados() {
    int op;
    system("cls");
    printf("-------{ Menu Sorteados }-------\n");
    printf("| 1 - Cadastrar Aluno Sorteado |\n");
    printf("| 2 - Lista de Alunos Sorteados|\n");
    printf("| 0 - Voltar                   |\n");
    printf("--------------------------------\n");
    printf(" Opcao: ");
    scanf(" %d", &op);
    return op;
}

int menuInserir() {
    int op;
    printf("Onde deseja inserir o aluno?\n");
    printf("1 - Inicio da Lista\n");
    printf("2 - Meio da Lista\n");
    printf("3 - Fim da Lista\n");
    printf("Opcao: ");
    scanf(" %d", &op);
    return op;
}

Aluno cadastrarAluno() {
    Aluno aluno;
    do {
        printf("Nome: ");
        scanf(" %s", aluno.nome);
        if (strlen(aluno.nome) > 40) {
            printf("Nome muito extenso. Escreva um nome menor, por favor.\n");
            system("pause");
        }
    } while (strlen(aluno.nome) > 40);
    do {
        printf("RA (com traco): ");
        scanf(" %s", aluno.ra);
        if (strlen(aluno.ra) != 10) {
            printf("RA Invalido. Digite novamente.\n");
            system("pause");
        }
    } while (strlen(aluno.ra) != 10);
    aluno.pizzaRetirada = false;
    return aluno;
}

int menuPizzas() {
    system("cls");
    int op;
    printf("----{ Gerenciamento das Pizzas }----\n");
    printf("| 1 - Adicionar Pizzas              |\n");
    printf("| 2 - Remover Pizzas                |\n");
    printf("| 3 - Visualizar Pilha de Pizzas    |\n");
    printf("| 0 - Voltar                        |\n");
    printf("-------------------------------------\n");
    printf(" Opcao: ");
    scanf(" %d", &op);
    return op;
}

int menuRetirada() {
    int op;
    system("cls");
    printf("-----{ Retirada da Pizza }----\n");
    printf("| 1 - Adicionar Aluno a Fila |\n");
    printf("| 2 - Realizar Entrega       |\n");
    printf("| 3 - Visualizar Fila        |\n");
    printf("| 0 - Voltar                 |\n");
    printf("------------------------------\n");
    printf(" Opcao: ");
    scanf(" %d", &op);
    return op;
}

void atualizaRetirada(No_F *inicio, No_L **lista) {
    if (filaEstaVazia(inicio)) {
        printf("\nA fila esta vazia. Impossivel realizar entrega.\n");
        system("pause");
        return;
    }
    No_F *aux = inicio;
    No_L *temp = *lista;
    while (temp != NULL && strcmp(aux->infos.nome, temp->infos.nome) != 0) {
        temp = temp->proximo;
    }
    temp->infos.pizzaRetirada = true;
    printf("\n%s retirou uma pizza.\n", aux->infos.nome);
    system("pause");
}

//------------------------------------------------------------------------------

void push(No_P **topo, Pizza pizza) {
    for (int i=0; i<pizza.qtd; i++) {
        No_P *novo = malloc(sizeof(No_P));
        if (novo == NULL) {
            printf("\nErro ao alocar memoria para novo no da pilha.\n");
            system("pause");
            return;
        }
        novo->infos = pizza;
        novo->proximo = *topo;
        *topo = novo;
    }
    printf("\n%d pizza(s) de %s adicionado a pilha.\n", pizza.qtd, pizza.sabor);
    system("pause");
}

void pop(No_P **topo) {
    if (pilhaEstaVazia(*topo)) {
        printf("\nA pilha esta vazia.\n");
        system("pause");
        return;
    }
    No_P *aux = *topo;
    *topo = (*topo)->proximo;
    printf("\nPizza de %s removida da pilha.\n", aux->infos.sabor);
    system("pause");
    free(aux);
}

void imprimirPilha(No_P *topo) {
    if (pilhaEstaVazia(topo)) {
        printf("\nA pilha esta vazia.\n");
        system("pause");
        return;
    }
    No_P *aux = topo;
    printf("Imprimindo Pilha...\n");
    while (aux != NULL) {
        printf("[ PIZZA DE %s ]\n", strupr(aux->infos.sabor));
        aux = aux->proximo;
    }
    system("pause");
}

void limpaPilha(No_P *topo) {
    if (pilhaEstaVazia(topo)) {
        return;
    }
    No_P *aux = topo;
    while (aux != NULL) {
        No_P *proximoNo = aux->proximo;
        free(aux);
        aux = proximoNo;
    }
    printf("\nPilha limpa.\n");
    system("pause");
}

//------------------------------------------------------------------------------

Aluno buscaAluno(char nome[], No_L *lista) {
    No_L *aux = lista;
    while (aux != NULL && strcmp(aux->infos.nome, nome)) {
        aux = aux->proximo;
    }
    if (aux == NULL) {
        Aluno erro;
        strcpy(erro.nome, "ERROR");
        return erro;
    }
    return aux->infos;
}

void enqueue(No_F **inicio, No_F **fim, Aluno aluno) {
    No_F *novo = malloc(sizeof(No_F));
    if (novo == NULL) {
        printf("\nErro ao alocar memoria para novo no da fila.\n");
        system("pause");
        return;
    }
    novo->infos = aluno;
    novo->proximo = NULL;
    if (filaEstaVazia(*inicio)) {
        *inicio = novo;
        *fim = novo;
    } else {
        (*fim)->proximo = novo;
        *fim = novo;
    }
    printf("\n%s adicionado a fila.\n", aluno.nome);
    system("pause");
}

void dequeue(No_F **inicio) {
    if (filaEstaVazia(*inicio)) {
        printf("\nA fila esta vazia.\n");
        system("pause");
        return;
    }
    No_F *aux = *inicio;
    *inicio = (*inicio)->proximo;
    printf("\n%s removido da fila.\n", aux->infos.nome);
    free(aux);
    system("pause");
}

void imprimirFila(No_F *inicio) {
    if (filaEstaVazia(inicio)) {
        printf("\nA fila esta vazia.\n");
        system("pause");
        return;
    }
    No_F *aux = inicio;
    system("cls");
    printf("Imprimindo Fila...\n");
    while (aux != NULL) {
        printf("[ %s ] -> ", strupr(aux->infos.nome));
        aux = aux->proximo;
    }
    system("pause");
}

void limpaFila(No_F *inicio) {
    if (filaEstaVazia(inicio)) {
        return;
    }
    No_F *aux = inicio;
    while (aux != NULL) {
        No_F *proximoNo = aux->proximo;
        free(aux);
        aux = proximoNo;
    }
    printf("\nFila limpa.\n");
    system("pause");
}

//------------------------------------------------------------------------------

void inserirInicio(No_L **topo, Aluno aluno) {
    No_L *novo = malloc(sizeof(No_L));
    if (novo == NULL) {
        printf("\nErro ao alocar memoria para novo no da lista.\n");
        system("pause");
        return;
    }
    novo->infos = aluno;
    if (listaEstaVazia(*topo)) {
        novo->anterior = NULL;
        novo->proximo = *topo;
        *topo = novo;
    } else {
        novo->anterior = (*topo)->anterior;
        novo->proximo = *topo;
        (*topo)->anterior = novo;
        *topo = novo;
    }
    printf("\n%s adicionado ao inicio da lista.\n", aluno.nome);
    system("pause");
}

void inserirMeio(No_L *lista, Aluno aluno, char anterior[]) {
    if (listaEstaVazia(lista)) {
        printf("\nA lista esta vazia. Aluno nao pode ser adicionado.\n");
    } else {
        No_L *aux = lista;
        while (aux != NULL && strcmp(aux->infos.nome, anterior) != 0) {
            aux = aux->proximo;
        }
        if (aux == NULL) {
            printf("\nAluno nao encontrado na lista.\n");
            system("pause");
            return;
        }
        No_L *novo = malloc(sizeof(No_L));
        if (novo == NULL) {
        printf("\nErro ao alocar memoria para novo no da lista.\n");
        system("pause");
        return;
        }
        novo->infos = aluno;
        novo->anterior = aux;
        novo->proximo = aux->proximo;
        if (aux->proximo != NULL) {
            aux->proximo->anterior = novo;
        }
        aux->proximo = novo;
        printf("\n%s adicionado ao depois de %s na lista.\n", aluno.nome, anterior);
    }
    system("pause");
}

void inserirFim(No_L **lista, Aluno aluno) {
    No_L *novo = malloc(sizeof(No_L));
    if (novo == NULL) {
        printf("\nErro ao alocar memoria para novo no da lista.\n");
        system("pause");
        return;
    }
    novo->infos = aluno;
    if (listaEstaVazia(*lista)) {
        novo->anterior = NULL;
        novo->proximo = NULL;
        *lista = novo;
    } else {
        No_L *aux = *lista;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        novo->anterior = aux;
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
    printf("\n%s adicionado ao fim da lista.\n", aluno.nome);
    system("pause");
}

void imprimirLista(No_L *lista) {
    if (listaEstaVazia(lista)) {
        printf("\nA lista esta vazia.\n");
    } else {
        No_L *aux = lista;
        system("cls");
        printf("Imprimindo Lista...\n");
        printf("NOME | PIZZA RETIRADA?\n");
        while (aux != NULL) {
            printf("[ %s ---", aux->infos.nome);
            if (aux->infos.pizzaRetirada == true) {
                printf(" Sim ]\n");
            } else {
                printf(" Nao ]\n");
            }
            aux = aux->proximo;
        }
    }
    system("pause");
}

void limpaLista(No_L *lista) {
    if (listaEstaVazia(lista)) {
        return;
    }
    No_L *aux = lista;
    while (aux != NULL) {
        No_L *proximoNo = aux->proximo;
        free(aux);
        aux = proximoNo;
    }
    printf("\nLista esvaziada e limpa.\n");
    system("pause");
}

//------------------------------------------------------------------------------