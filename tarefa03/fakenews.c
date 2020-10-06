/*

    Bot: Média >= 60 e desvio-padrão > 15;
    Evento surpreendente: Média >= 60 e desvio-padrão <= 15;
    Evento normal: Média < 60, máximo >= 80 e mínimo > 20;
    Evento local: Média < 60, máximo >= 80 e mínimo <= 20;
    Evento irrelevante: Média < 60 e máximo < 80.

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Termos{
    char palavra[25];
    double *relevancia_diaria;
    double maximo;
    double minimo;
    double media;
    double desvio_padrao;
}Termo;

typedef struct Cada_Categoria{
    int n;
    char *termos;
}C;

typedef struct Todas_Categorias{
    C Bot;
    C Surpreendente;
    C Normal;
    C Local;
    C Irrelevante;

}Categorias;



int main(){
    int num_termos, dias;
    Termo *termos;
    scanf("%d %d", &num_termos, &dias);
    termos = malloc(num_termos * sizeof(Termo));



    free(termos);
    return 0;
    
}