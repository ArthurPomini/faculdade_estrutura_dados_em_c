// 8. Com base no exercício anterior, faça o mesmo para uma FILA. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct apelido_no {
    int dado;
    struct apelido_no *proximo;
} no;

no *frente = NULL;
no *fim = NULL;

//------------------------------------------------

int isEmpty(no *ex);
void systemPause();
void enqueueVinteElemAleat();
void dequeueImpares();
void imprimir();

//------------------------------------------------

int main() {
    srand(time(NULL));

    int opcao;
    do {
        printf("\n===FILAS===\n");
        printf("1 - Enfileirar 20 Valores Aleatorios\n");
        printf("2 - Desenfileirar Valores Impares\n");
        printf("3 - Imprimir Fila\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf(" %d", &opcao);
        switch (opcao) {
        case 1:
            enqueueVinteElemAleat();
            break;
        case 2:
            dequeueImpares();
            break;
        case 3:
            imprimir();
            break;
        case 4:
            printf("\nSaindo do sistema...");
            break;
        default:
            printf("\nOpcao Invalida\n");
            break;
        }
    } while (opcao != 4);

    return 0;
}

//------------------------------------------------

void systemPause() {
    printf("\nAperte ENTER para continuar...\n");
    getchar();
    getchar();
    system("cls");
}

int isEmpty(no *ex) {
    if (ex == NULL) {
        printf("\nA fila esta vazia.\n");
        systemPause();
        return 1;
    } else {
        return 0;
    }
}

void enqueueVinteElemAleat() {
    for (int i=0; i<20; i++) {
        no *novo = malloc(sizeof(no));
    
        if (novo == NULL) {
            printf("\nErro ao alocar memoria.\n");
            return;
        }
    
        novo->dado = rand() % 116 + 10;
        novo->proximo = NULL;
        if (fim == NULL) {
            frente = novo;
            fim = novo;
        } else {
            fim->proximo = novo;
            fim = novo;
        }
    }

    printf("\n20 Valores Aleatorios Adicionados a fila.\n");
    systemPause();
}

void dequeueImpares() {
    if (isEmpty(frente) == 1) {
        return;
    }

    no *itemFila = frente;
    no *anterior = NULL;
    while (itemFila != NULL) {
        no *proximoNo = itemFila->proximo;
        
        //------------------------------------------

        if (frente == itemFila && itemFila->dado % 2 != 0) {
            frente = proximoNo;
            printf("[ %d ] Valor impar removido da fila.\n", itemFila->dado);
            free(itemFila);
        } else if (itemFila->dado % 2 != 0) {
            anterior->proximo = proximoNo;
            printf("[ %d ] Valor impar removido da fila.\n", itemFila->dado);
            free(itemFila);
        } else {
            anterior = itemFila;
        }

        //------------------------------------------

        itemFila = proximoNo;
    }
    
    if (frente == NULL) {
        fim = NULL;
    } else {
        fim = anterior;
        fim->proximo = NULL;
    }
    systemPause();
}

void imprimir() {
    if (isEmpty(frente) == 1) {
        return;
    }

    no *temp = frente;
    while (temp != NULL) {
        printf("[ %d ] -> ", temp->dado);
        temp = temp->proximo;
    }

    systemPause();
}