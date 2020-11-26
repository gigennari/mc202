#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "max_heap.h"


p_fp aloca_fprio(int capacidade){
    p_fp fprio = malloc(sizeof(FP));
    fprio->capacidade = capacidade;
    fprio->n = 0;
    fprio->v = malloc(capacidade * sizeof(Cliente));
    return fprio;
}