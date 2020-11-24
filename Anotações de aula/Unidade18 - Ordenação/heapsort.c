#include <stdio.h>
#include <stdlib.h>

#define PAI(i) ((i - 1) / 2)
#define F_DIR(i) (2 * i + 2)
#define F_ESQ(i) (2 * i + 1)

typedef struct
{
    char nome[20];
    int chave;
} Item;

typedef struct
{
    Item *v;
    int n, capacidade;
} FP;

typedef FP *p_fp;

void troca(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void desce_no_heap(p_fp fprio, int k)
{
    int maior_filho;
    if (F_ESQ(k) < fprio->n)
    {
        maior_filho = F_ESQ(k);
        if (F_DIR(k) < fprio->n &&
            fprio->v[F_ESQ(k)].chave < fprio->v[F_DIR(k)].chave) // se o filho esq for menor q o dir
        {
            maior_filho = F_DIR(k);
        }
    }
    if (fprio->v[k].chave < fprio->v[maior_filho].chave)
    {
        troca(&fprio->v[k], &fprio->v[maior_filho]);
        desce_no_heap(fprio, maior_filho);
    }
}

void heapsort(int *v, int n){
    int k;
    for (k = n/2; k >= 0; k--){
        desce_no_heap(v, n, k);
    }
    while(n > 1){
        troca(&v[0], &v[n-1]);
        n--;
        desce_no_heap(v, n, 0);
    }
}

int main(){
    int vetor[] = {};
    heapsort(vetor, );

    return 0;
}