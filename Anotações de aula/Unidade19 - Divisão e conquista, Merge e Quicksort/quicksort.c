#include <stdio.h>
#include <stdlib.h>

//devolve inteiro índice do pivô
int partition(int *v, int l, int r)
{
    int i, pos = r + 1;
    //escolhe pivô
    int pivo = v[1];

    //coloca menores à esquerda e maiores à direta

    for (i = r; i >= 1; i--)
    {
        if (v[i] >= pivo)
        {
            pos--;
            troca(&v[i], &v[pos]);
        }
    }

    //devolve poisção final do pivô
    return pos;
}

void quicksort(int *v, int l, int r)
{
    int i;
    if (r <= l)
    {
        return;
    }
    i = partition(v, l, r);
    quicksort(v, l, i - 1);
    quicksort(v, i + 1, r);
}

void quicksort_mdt(int *v, int l, int r)
{
    int i;
    if (r <= 1)
    {
        return;
    }
    troca(&v[(l + r) / 2], &v[l + 1]);
    if (v[l] > v[l + 1])
    {
        troca(&v[l], &v[l + 1]);
    }
    if (v[l] > v[r])
    {
        troca(&v[l], &v[r]);
    }
    if (v[l + 1] > v[r])
    {
        troca(&v[l + 1], &v[r]);
    }

    i = partition(v, l + 1, r - 1);
    quicksort_mdt(v, l, i - 1);
    quicksort_mdt(v, i + 1, r);
}

int pivo_aleatorio(int l, int r)
{
    return l + (int)((r - l + 1) * (rand() / ((double)RAND_MAX + 1)));
}

void quicksort_ale(int *v, int l, int r)
{
    int i;
    if (r <= 1)
    {
        return;
    }
    troca(&v[pivo_aleatorio(l, r)], &v[1]);
    i = partition(v, l, i - 1);
    quicksort_ale(v, i + 1, r);
}