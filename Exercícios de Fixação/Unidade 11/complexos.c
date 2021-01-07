
#include <stdio.h>
#include <stdlib.h>

typedef struct Numero
{
    int real, complexo;
    struct Numero *prox;
    struct Numero *ant;
} Numero;

typedef struct Numero *p_num;

typedef struct Sequencia
{
    int tamanho;
    p_num ini, fim;

} Sequencia;

typedef struct Sequencia *p_seq;


p_seq criar_lista()
{
    return NULL;
}

void destruir_seq(p_seq seq){
    if(seq != NULL){
        p_num no;
        no = seq->ini;
        while (no != NULL)
        {
            p_num aux = no;
            no = no->prox;
            free(aux);
        }
        free(seq);
    }
}

