// 12. Construa  um  programa  em  linguagem c  que  monte  uma  pilha de  15 
// elementos com valores aleatórios (não repetidos) entre 10 e 100.
// Posteriormente, monte duas pilhas (pares e ímpares), distribuindo e 
// esfaziando a pilha original.

// 14. Com  base  no  exercício  12  (PILHA  ORIGINAL),  construa  uma  função  que 
// retorne a quantidade de elementos maiores que 50 na pilha. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _no {
    int valor;
    struct _no *proximo;
} No;

No *top = NULL;
No *topPar = NULL;
No *topImpar = NULL;

//-------------------------------------------------------

void systemPause();
void push15ValoresAleatoriosNaoRepetidos();
void imprimir();
void mostraElementosMaior50();
void dividirPilha();
void imprimirPilhasParImpar();
void limpaPilha();

//-------------------------------------------------------

int main() {
    srand(time(NULL));

    int opcao;
    do {
        printf("=== SIMULACAO DE PILHA ===\n");
        printf("1 - Empilhar 15 Valores Aleatorios (Nao Repetidos)\n");
        printf("2 - Imprimir\n");
        printf("3 - Dividir Pilha em Impares e Pares\n");
        printf("4 - Imprimir Pilhas Par e Impar\n");
        printf("5 - Mostrar Elementos Maiores Que 50 (Pilha Original)\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf(" %d", &opcao);
        switch (opcao) {
        case 0:
            printf("Saindo do sistema...\n");
            limpaPilha();
            return 0;
        case 1:
            push15ValoresAleatoriosNaoRepetidos();
            break;
        case 2:
            imprimir();
            break;
        case 3:
            dividirPilha();
            break;
        case 4:
            imprimirPilhasParImpar();
            break;
        case 5:
            mostraElementosMaior50();
            break;
        default:
            printf("Opcao Inexistente.\n");
            systemPause();
            break;
        }
    } while (opcao != 0);
}

//-------------------------------------------------------

void systemPause() {
    printf("Aperte ENTER para continuar...\n");
    getchar();
    getchar();
    system("cls");
}

void push15ValoresAleatoriosNaoRepetidos() {
    for (int i=0; i<15; i++) {
        No *novo = malloc(sizeof(No));

        if (novo == NULL) {
            printf("Erro ao alocar memoria para um novo no.\n");
            systemPause();
            return;
        }

        novo->valor = rand() % 91 + 10;
        No *temp = top;
        while (temp != NULL) { // laço para percorrer a pilha verificando valor igual
            while (novo->valor == temp->valor) { // laço para atribuir um valor novo diferente do igual
                novo->valor = rand() % 91 + 10;
            }
            temp = temp->proximo; // proximo no do laço
        }
        novo->proximo = top;
        top = novo;
    }

    printf("\n15 valores aleatorios nao repetidos adicionados a pilha.\n");
    systemPause();
}

void imprimir() {
    if (top == NULL) {
        printf("\nA pilha esta vazia.\n");
        systemPause();
        return;
    }

    No *temp = top;
    while (temp != NULL) {
        printf("[ %d ]\n", temp->valor);
        temp = temp->proximo;
    }

    systemPause();
}

void mostraElementosMaior50() {
    if (top == NULL) {
        printf("\nA pilha esta vazia.\n");
        systemPause();
        return;
    }

    No *temp = top;
    int elem = 0;
    while (temp != NULL) {
        if (temp->valor > 50)
            elem++;
        temp = temp->proximo;
    }
    printf("A pilha possui %d elementos maiores que 50.\n", elem);
    systemPause();
}

void imprimirPilhasParImpar() {
    if (topPar == NULL && topImpar == NULL) {
        printf("\nA pilha nao foi dividida ainda.\n");
        systemPause();
        return;
    }

    No *tempPar = topPar;
    No *tempImpar = topImpar;
    printf("===PILHA===\n");
    printf("PAR - IMPAR\n");
    while (tempPar != NULL || tempImpar != NULL) {
        if (tempPar == NULL) {
            printf("         [ %d ]\n", tempImpar->valor);
            tempImpar = tempImpar->proximo;
        } else if (tempImpar == NULL) {
            printf("[ %d ]\n", tempPar->valor);
            tempPar = tempPar->proximo;
        } else {
            printf("[ %d ] - [ %d ]\n", tempPar->valor, tempImpar->valor);
            tempPar = tempPar->proximo;
            tempImpar = tempImpar->proximo;
        }
    }

    systemPause();
}

void dividirPilha() {
    if (top == NULL) {
        printf("\nA pilha esta vazia.\n");
        systemPause();
        return;
    }

    No *temp = top;
    while (temp != NULL) {
        No *novo = malloc(sizeof(No));
        
        if (novo == NULL) {
            printf("Erro ao alocar memoria para novo no.\n");
            systemPause();
            return;
        }

        novo->valor = temp->valor;
        if (temp->valor % 2 == 0) {
            novo->proximo = topPar;
            topPar = novo;    
        } else {
            novo->proximo = topImpar;
            topImpar = novo;  
        }

        No *proximoNo = temp->proximo;
        free(temp);
        temp = proximoNo;
    }
    top = NULL;

    printf("Pilha dividida.\n");
    systemPause();
}

void limpaPilha() {
    No *temp = top;
    while (temp != NULL) {
        No *proximoNo = temp->proximo;
        free(temp);
        temp = proximoNo;
    }

    printf("\nPilha limpa.\n");
    systemPause();
}