#include <stdio.h>
#include <stdlib.h>

void f(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}


void g(int **c, int n){
    *c = malloc(sizeof(int) * n);
}

void h(int *h){
    *h = 100;
}

int main(){
    int a = 1;
    int b = 2; 
    int c = 3;
    int **d;

    /**
     * Aloca memória dinamicamente
     * */
    d = malloc (sizeof(int*));
    if (d == NULL){
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }


    f(&a, &b); 
    g(d, 1); 
    h(*d);

    printf("%d %d %d", a, c, d[0][0]);

    
    free(d[0]);
    free(d);
    return 0;
}