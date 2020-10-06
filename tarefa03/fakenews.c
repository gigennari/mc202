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

typedef struct Categoria{
    char nome[20]; 
    int n;
    char *termos;
}C;

Termo le_termos_teclado(int num_termos, int dias, Termo *termos){

}

void encontra_maximo(){

}

void encontra_minimo(){

}

void calcula_media(){

}


void calcula_desvio_padrao(){

}

/**
 * Calcula maximo, mínimo, média e desvio para cada termo
 * */
void calcular_dados(int num_termos, int dias, Termo *termos){

}

void imprime_dados(Termo *termos, int num_termos){
    
}

C inicializa_categorias(C categorias){

}

C aloca_termos_categorias(C todas, Termo *termos, int num_termos){

}

void imprime_categorias(){

}



int main(){
    int num_termos, dias;
    Termo *termos;
    C *categorias;

    scanf("%d %d", &num_termos, &dias);
    termos = malloc(num_termos * sizeof(Termo));
    le_termos_teclado(num_termos, dias, termos);

    calcular_dados(num_termos, dias, termos);
    imprime_dados(termos, num_termos);

    inicializa_categorias(*categorias);
    aloca_termos_categorias(*categorias, termos, num_termos);
    imprime_categorias(categorias);


    free(termos->relevancia_diaria);
    free(termos);
    return 0;
}