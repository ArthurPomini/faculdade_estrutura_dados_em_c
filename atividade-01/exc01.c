#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tot 5

typedef struct {
    char nome[20];
    int idade;
    int telefone;    
} Dados;

Dados vet[tot];

void menu() {
    printf("--- MENU ---\n\n");
    printf("1 - Preencher Dados\n");
    printf("2 - Classificar Vetor (Nome)\n");
    printf("3 - Classificar Vetor (Idade)\n");
    printf("4 - Apresentar Dados\n");
    printf("5 - Sair do sistema\n");
    printf("Opcao: ");
}

void entradaDados() {
    for (int i=0; i<tot; i++) {
        printf("Estrutura Vetor %d\n", i+1);
        printf("Nome: ");
        scanf(" %s", vet[i].nome);
        printf("Idade: ");
        scanf(" %d", &vet[i].idade);
        printf("Telefone: ");
        scanf(" %d", &vet[i].telefone);
        printf("\n\n");
    }
}

void saidaDados() {
    printf("VETORES APRESENTADOS:\n");
    for (int i=0; i<tot; i++) {
        printf("Nome: %s\n", vet[i].nome);
        printf("Idade: %d\n", vet[i].idade);
        printf("Telefone: %d\n", vet[i].telefone);
        printf("\n");
    }
}

void classificaVetorNome() {
    Dados aux;
    for (int i = 0; i < tot - 1; i++) {
        for (int j = i + 1; j < tot; j++) {
            if (strcmp(vet[i].nome, vet[j].nome) > 0) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void classificaVetorIdade() {
    Dados aux;
    for (int i = 0; i < tot - 1; i++) {
        for (int j = i + 1; j < tot; j++) {
            if (vet[i].idade < vet[j].idade) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void classificaVetorFone() {
    Dados aux;
    for (int i = 0; i < tot - 1; i++) {
        for (int j = i + 1; j < tot; j++) {
            if (vet[i].telefone > vet[j].telefone) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

int main() {
    int op;

    do {
        menu();
        scanf(" %d", &op);
        switch(op) {
            case 1:
                entradaDados();
                break;
            case 2:
                classificaVetorNome();
                break;
            case 3:
                classificaVetorIdade();
                break;
            case 4:
                classificaVetorFone();
                break;
            case 5:
                saidaDados();
                break;
            case 6:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao inexistente.\n");
        }
    } while (op != 5);

    return 0;
}