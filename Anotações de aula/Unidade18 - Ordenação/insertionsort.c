#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void insertionsort(int *v, int n)
{
    int comparacoes = 0, trocas = 0;
    int i, j;
    for (i = 1; i < n; i++)
    {
        for (j = i; j > 0; j--)
        {
            comparacoes++;
            if (v[j] < v[j - 1])
            {
                troca(&v[j], &v[j - 1]);
                trocas++;
            }
        }
    }
    printf("Comparações = %d\n", comparacoes);
    printf("Trocas = %d\n", trocas);
}

void insertionsort_2(int *v, int n)
{
    int i, j, t;
    for (i = 1; i < n; i++)
    {
        t = v[i];
        for (j = i; j > 0 && t < v[j-1]; j--)
        {
            v[j] = v[j-1];
        }
        v[j] = t;
    }
    
}

int main()
{
    int vetor[10] = {89, 79, 32, 38, 46, 26, 43, 38, 32, 79};
    insertionsort(vetor, 10);
    return 0;
}
