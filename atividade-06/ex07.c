// 7. Desenvolva  um  programa  em  C  que  simule  uma  PILHA  com  20  valores 
// aleatorios  entre  10  e  125.  Posteriormente,  remova  todos  os  elementos 
// ímpares da pilha e apresente a pilha final ao usuário. Não esqueça de liberar 
// a pilha toda ao encerrar o programa.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct apelido_no {
    int valor;
    struct apelido_no *proximo;
} no;

no *top = NULL;

//-----------------------------------------------

int isEmpty(no *ex);
void systemPause();
void imprimir();
void pushVinteValores();
void popImpares();
void limpaPilha();

//-----------------------------------------------

int main() {
    srand(time(NULL));

    int opcao;
    do {
        printf("\n--------PILHAS--------\n");
        printf("1 - Empilhar 20 valores aleatorios\n");
        printf("2 - Desempilhar valores impares\n");
        printf("3 - Imprimir Pilha\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
    
        switch (opcao) {
        case 1:
            pushVinteValores();
            break;
        case 2:
            popImpares();
            break;
        case 3:
            imprimir();
            break;
        case 4:
            printf("\nSaindo do sistema...\n");
            limpaPilha();
            break;
        default:
            printf("Opcao inexistente\n");
            break;
        }
    } while (opcao != 4);

    return 0;
}

//-----------------------------------------------

int isEmpty(no *ex) {
    if (ex == NULL) {
        printf("\nA pilha esta vazia.\n");
        return 1;
    } else {
        return 0;
    }
}

void systemPause() {
    printf("\nAperte ENTER para continuar...\n");
    getchar();
    getchar();
    system("cls");
}

void imprimir() {
    if (isEmpty(top) == 1) {
        systemPause();
        return;
    }

    no *temp;
    temp = top;
    printf("\nImprimindo pilha...\n\n");
    while (temp != NULL) {
        printf("[ %d ]\n", temp->valor);
        temp = temp->proximo;
    }

    systemPause();
}

//-----------------------------------------------

void pushVinteValores() {

    // faz isso 20 vezes
    for (int i=0; i<20; i++) {
        no *novo = malloc(sizeof(no)); // cria um nó novo
    
        if (novo == NULL) {
            printf("\nErro ao empilhar.\n");
            systemPause();
            return;
        }
        
        novo->valor = (rand() % 116) + 10; // Valor dentro do nó recebe valor um aleatório
        novo->proximo = top; // O ponteiro para o próximo nó agora aponta para o topo da pilha
        top = novo; // O novo nó agora é o topo da pilha
    }

    printf("\n20 valores empilhados com sucesso!\n");
    
    systemPause();
}

//-----------------------------------------------

void popImpares() {
    if (isEmpty(top) == 1) {
        systemPause();
        return;
    }

    no *atual = top;
    no *anterior = NULL;

    while (atual != NULL) {
        if (atual->valor % 2 != 0) {
            no *proximoNo = atual->proximo;

            if (atual == top) {
                top = proximoNo;
            } else {
                anterior->proximo = proximoNo;
            }

            printf("[ %d ] -> Valor impar identificado e neutralizado\n", atual->valor);
            free(atual);
            atual = proximoNo;
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }

    systemPause();
}

void limpaPilha() {
    no *temp = top;
    while (temp != NULL) {
        no *proximoNo = temp->proximo;
        free(temp);
        temp = proximoNo;
    }
}