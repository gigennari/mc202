#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *esq, *dir, *pai;
} No;

typedef No *p_no;

