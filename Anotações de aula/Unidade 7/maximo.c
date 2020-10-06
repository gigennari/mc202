#include <stdio.h>


/**
 * Devolve o valor máximo dentre as n 
 * primeiras posições do vetor v
 * */
int maximo(int *v, int n){
    if (n == 1){
        return v[0];
    }
    else {
        int m = n - 1;
        int max_subvetor;
        max_subvetor = maximo(v, m);
        if (max_subvetor > v[n-1]){
            return max_subvetor;
        }
        else{
            return v[n -1];
        }
    }
}
