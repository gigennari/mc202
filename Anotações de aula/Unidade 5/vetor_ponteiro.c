/*
Alocar um vetor com n doubles zerado
*/

#include <stdio.h>
#include <stdlib.h>

//correto
double * aloca_e_zera(int n)
{
    double *v;
    v = malloc(sizeof(double) * n);
    if (v == NULL)
    {
        printf("Não tenho memória\n");
        exit(1);
    }
    for(int i = 0; i < n; i++){
        v[i] = 0;   // faz casting automaticamente
    }
    return v;
}

//incorreto 
double * aloca_e_zera2(int n){
    double v[n] = {0};
    return v;
}

int main(){
    int n;
    double *p, *q;
    scanf("%d ", &n);
    p = aloca_e_zera(n);
    q = aloca_e_zera2(n);
}