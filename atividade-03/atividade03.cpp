#include <stdio.h>
#include <stdlib.h>

int main() {
    char nome[] = "Moreno";
    char *p;
    char **pp;
    
    p = nome;
    pp = &p;

    int idade = 45;
    int *i;
    int **ii;

    i = &idade;
    ii = &i;

    printf("Variavel nome: %s\n", nome);
    printf("Usando ponteiro: %s\n", p);
    printf("Usando ponteiro de ponteiro: %s\n\n", *pp);

    // nome == *pp;
    // nome[1] == (*pp)[1] ---> deve-se usar parenteses para o pp conseguir acessar o conteúdo, caso contrário
    // o [1] possui precedência.
    printf("2o. caractere usando pp com []: %c\n", (*pp)[1]);
    printf("3o. caractere usando aritmetica de pp: %c\n", *(*pp+2));
    printf("Variavel idade: %d\n", idade);
    printf("Usando ponteiro: %d\n", *i);
    printf("Usando ponteiro de ponteiro: %d\n\n", **ii);

    printf("End. de nome : %p\n", nome);
    printf("End. ponteiro de nome: %p\n", &p);
    printf("End. ponteiro de ponteiro de nome: %p\n\n", &pp);
    
    printf("End. de idade: %p\n", &idade);
    printf("End. ponteiro de idade: %p\n", &i);
    printf("End. ponteiro de ponteiro de idade: %p\n\n", &ii);

    printf("End. onde ponteiro de nome aponta: %p\n", &*p);
    printf("End. ponteiro de ponteiro de nome aponta: %p\n", &**pp);

    system("pause");
    return 0;
}