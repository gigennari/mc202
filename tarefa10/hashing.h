#include <stdio.h>
#include <stdlib.h>

//Interface de um hashing de lista ligada

typedef struct {
    char chave[30];
    int dado;
    struct No *prox;

} No;

typedef struct No *p_no;

typedef struct {
    p_no v[MAX]; 

}Hash;

typedef struct Hash *p_hash;

