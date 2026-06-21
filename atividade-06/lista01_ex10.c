// 10. Construma um progama em linguagem C que implemente uma FILA 
// contendo o nome e idade de 10 pessoas fornecidas pelo usuário. 
// Posteriormente,  monte  mais  duas  filas  (FILA2  e  FILA3)  onde  a  primeira 
// deverá conter as pessoas até 30 anos e a segunda acima de 30. Apresente 
// as  duas  novas  filas  ao  usuário  e  posteriormente  encerre  o  programa, 
// liberando a memória das três filas. Obs. A fila inicial deverá ser esvaziada ao 
// final do processo.

#include <stdio.h>
#include <stdlib.h>
#define PES 3

typedef struct {
    int idade;
    char nome[20];
} Pessoa;

typedef struct _no {
    Pessoa infos;
    struct _no *proximo;
} No;

No *frente1 = NULL;
No *fim1 = NULL;

No *frente2 = NULL;
No *fim2 = NULL;

No *frente3 = NULL;
No *fim3 = NULL;

//--------------------------------------------

void systemPause();
void enqueue();
void dividirFilas();
void imprimir();
void limpar();

//--------------------------------------------

int main() {
    int opcao;
    do {
        printf("--- ESTUDO DE FILAS ---\n");
        printf("1 - Enqueue\n");
        printf("2 - Dividir Filas\n");
        printf("3 - Imprimir\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf(" %d", &opcao);
        switch (opcao) {
        case 1:
            enqueue();
            break;
        case 2:
            dividirFilas();
            break;
        case 3:
            imprimir();
            break;
        case 4:
            printf("Saindo do sistema...\n");
            limpar();
            break;
        default:
            printf("\nOpcao inexistente.\n");
            break;
        }
    } while (opcao != 4);
}

//--------------------------------------------

void systemPause() {
    printf("\nAperte ENTER para continuar...\n");
    getchar();
    getchar();
    system("cls");
}

void enqueue() {
    for (int i=0; i<PES; i++) {
        No *novo = malloc(sizeof(No));

        if (novo == NULL) {
            printf("Erro ao alocar memoria.\n");
            return;
        }

        printf("Digite o nome da pessoa %d: ", i+1);
        scanf(" %s", novo->infos.nome);

        printf("Digite a idade da pessoa %d: ", i+1);
        scanf(" %d", &novo->infos.idade);

        if (fim1 == NULL) {
            frente1 = novo;
            fim1 = novo;
        } else {
            fim1->proximo = novo;
            fim1 = novo;
        }
    }

    systemPause();
}

void dividirFilas() {
    if (frente1 == NULL) {
        printf("A fila esta vazia.\n");
        systemPause();
        return;
    }

    No *temp = frente1;
    No *proximoNo;

    for (int i=0; i<PES; i++) {
        proximoNo = temp->proximo;

        No *novo = malloc(sizeof(No));

        if (novo == NULL) {
            printf("Erro ao alocar memoria.\n");
            return;
        }

        novo->infos = temp->infos;
        novo->proximo = NULL;

        if (temp->infos.idade <= 30) {
            if (fim2 == NULL) {
                frente2 = novo;
                fim2 = novo;
            } else {
                fim2->proximo = novo;
                fim2 = novo;
            }
        } else {
            if (fim3 == NULL) {
                frente3 = novo;
                fim3 = novo;
            } else {
                fim3->proximo = novo;
                fim3 = novo;
            }
        }

        free(temp);
        temp = proximoNo;
    }

    frente1 = NULL;
    fim1 = NULL;
    systemPause();
}

void imprimir() {
    if (frente1 == NULL) {
        printf("Fila 1 vazia.\n");
    } else {
        No *temp = frente1;
        printf("\n===Fila 1===\n");
        for (int i=0; i<PES; i++) {
            printf("Pessoa %d:\n", i+1);
            printf("\tNome: %s\n", temp->infos.nome);
            printf("\tIdade: %d\n", temp->infos.idade);
            temp = temp->proximo;
        }
        printf("\n");
    }

    //---------------------------------------------------
    if (frente2 == NULL) {
        printf("Fila 2 vazia.\n");
    } else {
        No *temp = frente2;
        int i=0;
        printf("\n===Fila 2===\n");
        while (temp != NULL) {
            printf("Pessoa %d:\n", ++i);
            printf("\tNome: %s\n", temp->infos.nome);
            printf("\tIdade: %d\n", temp->infos.idade);
            temp = temp->proximo;
        }
        printf("\n");
    }


    //---------------------------------------------------
    if (frente3 == NULL) {
        printf("Fila 3 vazia.\n");
    } else {
        No *temp = frente3;
        int i=0;
        printf("\n===Fila 3===\n");
        while (temp != NULL) {
            printf("Pessoa %d:\n", ++i);
            printf("\tNome: %s\n", temp->infos.nome);
            printf("\tIdade: %d\n", temp->infos.idade);
            temp = temp->proximo;
        }
        printf("\n");
    }

    systemPause();
}

void limpar() {
    No *temp = frente1;
    while (temp != NULL) {
        No *proximoNo = temp->proximo;
        free(temp);
        temp = proximoNo;
    }
    frente1 = NULL;
    fim1 = NULL;
    printf("Fila 1 limpa.\n");

    temp = frente2;
    while (temp != NULL) {
        No *proximoNo = temp->proximo;
        free(temp);
        temp = proximoNo;
    }
    frente2 = NULL;
    fim2 = NULL;
    printf("Fila 2 limpa.\n");

    temp = frente3;
    while (temp != NULL) {
        No *proximoNo = temp->proximo;
        free(temp);
        temp = proximoNo;
    }
    frente3 = NULL;
    fim3 = NULL;
    printf("Fila 3 limpa.\n");

    systemPause();
}