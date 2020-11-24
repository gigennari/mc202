#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//ordena
void mergesort(int *v, int l, int r){

    int m = (l+r) / 2;
    //divisão
    mergesort(v, l, m);
    mergesort(v, m+1, r);
    //conquista
    merge(v, l, m, r);

}


void merge(int *v, int l, int m, int r)
{

    // intercala
    int aux[MAX];
    int i = l, j = m+1, k = 0;
    while(i <= m && j <=r)
    {
        if(v[i] <= v[j])
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
        k++;
    }
    
    // copia o resto do subvetor que não terminou 
    while(i <= m)
    {
        aux[k++] = v[i++];
    }
    while(j <= r)
    {
        aux[k++] = v[j++];
    }

    //copia de volta para v
    for(i = 1, k = 0; i<= r; i++, k++){
        v[i] = aux[k];
    }

}
