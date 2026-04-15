#include <stdio.h>
#include <stdlib.h>

int main() {
    int x=10, y=20, z=100, N=24;
    int *ptr1, *ptr2, *ptr3, *ptrN;

    ptr1 = &x;
    ptr2 = &y;
    ptr3 = &z;
    ptrN = &N;

    char tc='c';
    char *ptr4;

    ptr4 = &tc;

    printf("valor x = %d\n", x);
    printf("valor y = %d\n", y);
    printf("valor z = %d\n", z);
    printf("valor N = %d\n", N);
    printf("valor tc = %c\n\n", tc);

    printf("End. Mem. x = %p\n", &x);
    printf("End. Mem. y = %p\n", &y);
    printf("End. Mem. z = %p\n", &z);
    printf("End. Mem. N = %p\n", &N);
    printf("End. Mem. tc = %p\n\n", &tc);

    printf("End. Mem. ptr1 = %p\n", &ptr1);
    printf("End. Mem. ptr2 = %p\n", &ptr2);
    printf("End. Mem. ptr3 = %p\n", &ptr3);
    printf("End. Mem. ptr4 = %p\n", &ptr4);
    printf("End. Mem. ptrN = %p\n\n", &ptrN);

    printf("Valor ptr1 = %p\n", ptr1);
    printf("Valor ptr2 = %p\n", ptr2);
    printf("Valor ptr3 = %p\n", ptr3);
    printf("Valor ptr4 = %p\n", ptr4);
    printf("Valor ptrN = %p\n\n", ptrN);

    printf("Vlr. onde ptr1 aponta = %d\n", *ptr1);
    printf("Vlr. onde ptr2 aponta = %d\n", *ptr2);
    printf("Vlr. onde ptr3 aponta = %d\n", *ptr3);
    printf("Vlr. onde ptr4 aponta = %c\n", *ptr4);
    printf("Vlr. onde ptrN aponta = %d\n\n", *ptrN);

    printf("End. Mem. onde ptr1 aponta = %p\n", ptr1);
    printf("End. Mem. onde ptr2 aponta = %p\n", ptr2);
    printf("End. Mem. onde ptr3 aponta = %p\n", ptr3);
    printf("End. Mem. onde ptr4 aponta = %p\n", ptr4);
    printf("End. Mem. onde ptrN aponta = %p\n", ptrN);

    return 0;
}