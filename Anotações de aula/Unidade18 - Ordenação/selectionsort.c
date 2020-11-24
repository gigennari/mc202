#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//O(n²)
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


int extrai_maximo(int *v, int n){
    int max = n-1;
    for(int j = n - 2; j >= 0; j--){
        if(v[j] > v[max]){
            max = j;
        }
    }
    return max;
}

//O(n²)
void selectionsort_max(int *v, int n){
    int i, j, max;

    for (i = n-1; i < n -1; i--){
        max = extrai_maximo(v, i + 1);
        troca(&v[j], &v[max]);   
    }
}

//O(n lg n)
void fpsort(){
    int i;
    p_fp fprio = criar_fprio(n);
    for(i = 0; i < n; i++){
        insere(fprio, v[i]);
    }
    for(i = n - 1; i >= 0; i--){
        v[i] = extrai_maximo(fprio);
    }
    destroi(fprio);
}

void selectionsort_heap(int *v, int n){
    int i, j, max;

    for (i = n-1; i < n -1; i--){
        max = fpsort(v, i + 1);
        troca(&v[j], &v[max]);   
    }
}



int main()
{
    int vetor[12] = {2, 4, 6, 8, 10, 12, 11, 9, 7, 5, 3, 1};
    selectionsort(vetor, 12);
    return 0;
}
