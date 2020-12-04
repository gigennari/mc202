#include <stdio.h>
#include <stdlib.h>
#define M 1735

//Interface de um hashing de lista ligada

typedef struct No {
    char palavra[30]; //como não haverá remoção, não precisamos de uma flag
    struct No *prox;

} No;

typedef struct No *p_no;

typedef struct Hash {
    p_no v[M]; 

}Hash;

typedef struct Hash *p_hash;

