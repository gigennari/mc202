/*

    Bot: Média >= 60 e desvio-padrão > 15;
    Evento surpreendente: Média >= 60 e desvio-padrão <= 15;
    Evento normal: Média < 60, máximo >= 80 e mínimo > 20;
    Evento local: Média < 60, máximo >= 80 e mínimo <= 20;
    Evento irrelevante: Média < 60 e máximo < 80.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Termos
{
    char palavra[25];
    double *relevancia_diaria;
    double maximo, minimo, media, desvio_padrao;
} Termo;

typedef struct Categoria
{
    char nome[20];
    int n;
    Termo *termos;
} C;

void le_termos_teclado(int num_termos, int dias, Termo *termos)
{
    for (int i = 0; i < num_termos; i++)
    {
        scanf("%s", termos[i].palavra);
        for (int j = 0; j < dias; j++)
        {
            scanf("%lf", &termos[i].relevancia_diaria[j]);
        }
    }
}

void encontra_maximo(Termo *termo, int dias)
{
    int maximo = termo->relevancia_diaria[0];
    for (int i = 1; i < dias; i++){
        if (termo->relevancia_diaria[i] > maximo){
            maximo = termo->relevancia_diaria[i]; 
        }
    }
    termo->maximo = maximo; 
}

void encontra_minimo(Termo *termo, int dias)
{
    int minimo = termo->relevancia_diaria[0];
    for (int i = 1; i < dias; i++){
        if (termo->relevancia_diaria[i] < minimo){
            minimo = termo->relevancia_diaria[i]; 
        }
    }
    termo->minimo = minimo; 
}

void calcula_media(Termo *termo, int dias)
{
    double somatorio = 0;
    for (int i = 0; i < dias; i++){
        somatorio += termo->relevancia_diaria[i];
    }
    termo->media = somatorio / dias;
}

void calcula_desvio(Termo *termo, int dias){
    double somatorio = 0;
    for (int i = 0; i < dias; i++){
        somatorio += pow(termo->relevancia_diaria[i] - termo->media, 2); 
    }

    termo->desvio_padrao = sqrt(somatorio / dias);
}

/**
 * Calcula maximo, mínimo, média e desvio para cada termo
 * */
void calcular_dados(int num_termos, int dias, Termo *termos)
{
    for (int i = 0; i < num_termos; i++){
        encontra_maximo(&termos[i], dias);
        encontra_minimo(&termos[i], dias);
        calcula_media(&termos[i], dias);
        calcula_desvio(&termos[i], dias);
    }
}

void imprime_dados(Termo *termos, int num_termos)
{
    for(int i = 0; i < num_termos; i++){
        printf("%s", termos[i].palavra);

        printf("%lf %lf %lf %lf\n", termos[i].maximo, termos[i].minimo, termos[i].media, termos[i].desvio_padrao);
    }
}

C inicializa_categorias(C categorias, int n)
{
}

C aloca_termos_categorias(C todas, Termo *termos, int num_termos)
{
}

void imprime_categorias()
{
}

int main()
{
    int num_termos, dias;
    Termo *termos;
    C *categorias;
    int num_categorias = 5;


    /**
     * Aloca memória dinamicamente
     * */
    scanf("%d %d", &num_termos, &dias);
    termos = malloc(num_termos * sizeof(Termo));
    for (int i = 0; i < num_termos; i++)
    {
        termos[i].relevancia_diaria = malloc(dias * sizeof(double));
    }

    categorias = malloc(num_categorias * sizeof(C));
    for (int i = 0; i < num_termos; i++)
    {
        categorias[i].termos = malloc(num_termos * sizeof(Termo *t)); // como alocar ponteiro da struct?
    }



    le_termos_teclado(num_termos, dias, termos);

    calcular_dados(num_termos, dias, termos);
    imprime_dados(termos, num_termos);

    inicializa_categorias(*categorias, 5);
    aloca_termos_categorias(*categorias, termos, num_termos);
    imprime_categorias(categorias);

    
    

    /**
     * Libera memória
     * */
    
    free(categorias);

    for (int i = 0; i < num_termos; i++)
        free(termos[i].relevancia_diaria);
    free(termos);


    
    return 0;
}