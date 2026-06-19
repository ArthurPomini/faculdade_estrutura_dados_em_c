// 15. Utilizando linguagem C, construa um programa que possua um menu (inserir, 
// remover, imprimir e sair) e contemple uma FILA contendo nome e idade. O 
// nome não poderá ter tamanho fixo, ou seja, deverá ser alocado 
// dinamicamente. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int idade;
    char *nome;
} Pessoa;

typedef struct _no {
    Pessoa infos;
    struct _no *proximo;
} No;

No *frente = NULL;
No *fim = NULL;

//-----------------------------------------------------

void systemPause();
void inserir(int idade, char nome[]);
void remover();
void mostrar();

//-----------------------------------------------------

int main() {
    int opcao;

    do {
        printf("\n--- MENU FILA ---\n");
        printf("1. Inserir (Enqueue)\n");
        printf("2. Remover (Dequeue)\n");
        printf("3. Mostrar Fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                printf("Encerrando o programa...\n");
                systemPause();
                return 0;
                break;
            case 1:
                int id;
                char no[256];
                printf("Digite a idade: ");
                scanf(" %d", &id);
                printf("Digite o nome: ");
                scanf(" %s", no);
                inserir(id, no);
                break;
            case 2:
                remover();
                break;
            case 3:
                mostrar();
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);
}

//-----------------------------------------------------

void systemPause() {
    printf("\nAperte ENTER para continuar...\n");
    getchar();
    getchar();
    system("cls");
}

void inserir(int idade, char nome[]) {
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("\nErro ao alocar memoria para um novo no.\n");
        systemPause();
        return;
    }

    novo->infos.idade = idade;
    int tam = strlen(nome);
    novo->infos.nome = malloc((tam + 1) * sizeof(char));
    if (novo->infos.nome == NULL) {
        printf("\nErro ao alocar memoria para nome.\n");
        return;
    }
    strcpy(novo->infos.nome, nome);
    novo->infos.nome[tam] = '\0';
    novo->proximo = NULL;

    if (frente == NULL) {
        frente = novo;
        fim = novo;
    } else {
        fim->proximo = novo;
        fim = novo;
    }

    for (int i=0; i<tam; i++) {
        novo->infos.nome[i] = toupper(novo->infos.nome[i]);
    }

    printf("\n%s de %d anos adicionado a fila.\n", novo->infos.nome, novo->infos.idade);
    systemPause();
}

void remover() {
    if (frente == NULL) {
        printf("\nA fila esta vazia.\n");
        systemPause();
        return;
    }

    No *temp = frente;
    frente = temp->proximo;
    if (frente == fim) {
        fim = NULL;
    }
    printf("\n%s removido da fila.\n", temp->infos.nome);
    free(temp);
    systemPause();
}

void mostrar() {
    if (frente == NULL) {
        printf("\nA fila esta vazia.\n");
        systemPause();
        return;
    }

    No *temp = frente;
    printf("FILA\n\n");
    while (temp != NULL) {
        printf("[ %s | %d ] -> ", temp->infos.nome, temp->infos.idade);
        temp = temp->proximo;
    }

    systemPause();
}