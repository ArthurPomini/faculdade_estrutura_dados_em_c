#include <stdlib.h>
#include <stdio.h>

typedef struct apelido_no{
    int dado;
    struct apelido_no *proximo;
}no;

no *top=NULL;

//-------------------------------------------------------------

int entrada_dados(){
    int valor;
    printf("\nvalor a empilhar: ");
    scanf("%d",&valor);
    return valor;
}

void push(int item){
    no *novo=malloc(sizeof(no));
    //verificar se há memoria
    novo->dado=item;
    novo->proximo=top;
    top=novo;
    system("pause");
}

void pop(){
    if (top==NULL)
        printf("A pilha esta vazia\n");
    else{
        no *temp;
        temp=top;
        top=top->proximo;
        free(temp);
    }
    system("pause");
}

void sair() {
    if (top == NULL) {
        printf("A pilha esta vazia\n");
    } else {
        no *temp = top;
        while (temp != NULL) {
            no *proximoNo = temp->proximo;
            free(temp);
            temp = proximoNo;
        }
        printf("A pilha foi limpa.\n");
    }
    system("pause");
}

//-------------------------------------------------------------
int main(){
    int n,opcao;
    do{
        system("cls");
        printf("\nMenu\n1. Empilha");
        printf("\n2. Desempilha\n3. Sair");
        printf("\nopcao (0-3):");
        scanf("%d",&opcao);
        switch (opcao){
            case 1:
                n=entrada_dados();
                push(n); //empilhar
                break;
            case 2:
                pop(); //desempilhar
                break;
            case 3:
                sair();
                break;
        }
    }while (opcao!=3);
    system("pause");
    return 0;
}