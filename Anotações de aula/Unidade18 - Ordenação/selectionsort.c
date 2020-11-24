#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void selectionsort(int *v, int n){
    int i, j, min;
    int comparacoes = 0, trocas = 0;
    for (i = 0; i < n -1; i++){
        min = i;
        for(j = i+1; j < n; j++){
            comparacoes++;
            if(v[j] < v[min]){
                min = j;
            }
        }
        troca(&v[i], &v[min]);
        trocas++;
    }
    printf("Comparações = %d\n", comparacoes);
    printf("Trocas = %d\n", trocas);
}


int main()
{
    int vetor[12] = {2, 4, 6, 8, 10, 12, 11, 9, 7, 5, 3, 1};
    selectionsort(vetor, 12);
    return 0;
}
