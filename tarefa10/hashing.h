#include <stdio.h>
#include <stdlib.h>
#define M 8627 

//Interface de um hashing de lista ligada

typedef struct No {
    char *palavra; //como não haverá remoção, não precisamos de uma flag
    struct No *prox;

} No;

typedef struct No *p_no;

typedef struct Hash {
    p_no *v; 

}Hash;

typedef struct Hash *p_hash;

p_hash criar_hash();
p_hash inserir(p_hash t, char *chave);
p_no buscar(p_hash t, char *chave);
void destruir_hash(p_hash t);