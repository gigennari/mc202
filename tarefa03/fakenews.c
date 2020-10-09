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
#define NUM_CATEGORIAS 5
#define TAM_TERMO 25

typedef struct Termos
{
    char *palavra;
    double *relevancia_diaria;
    double maximo, minimo, media, desvio_padrao;
    int categoria;
} Termo;

typedef struct Categoria
{
    int bot, surpreendente, normal, local, irrelevante;
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
    for (int i = 1; i < dias; i++)
    {
        if (termo->relevancia_diaria[i] > maximo)
        {
            maximo = termo->relevancia_diaria[i];
        }
    }
    termo->maximo = maximo;
}

void encontra_minimo(Termo *termo, int dias)
{
    int minimo = termo->relevancia_diaria[0];
    for (int i = 1; i < dias; i++)
    {
        if (termo->relevancia_diaria[i] < minimo)
        {
            minimo = termo->relevancia_diaria[i];
        }
    }
    termo->minimo = minimo;
}

void calcula_media(Termo *termo, int dias)
{
    double somatorio = 0;
    for (int i = 0; i < dias; i++)
    {
        somatorio += termo->relevancia_diaria[i];
    }
    termo->media = somatorio / dias;
}

void calcula_desvio(Termo *termo, int dias)
{
    double somatorio = 0;
    for (int i = 0; i < dias; i++)
    {
        somatorio += pow(termo->relevancia_diaria[i] - termo->media, 2);
    }

    termo->desvio_padrao = sqrt(somatorio / dias);
}

/**
 * Calcula maximo, mínimo, média e desvio para cada termo
 * */
int calcular_dados(int num_termos, int dias, Termo *termos)
{
    for (int i = 0; i < num_termos; i++)
    {
        encontra_maximo(&termos[i], dias);
        encontra_minimo(&termos[i], dias);
        calcula_media(&termos[i], dias);
        calcula_desvio(&termos[i], dias);
    }
}

int imprime_dados(Termo *termos, int num_termos)
{
    for (int i = 0; i < num_termos; i++)
    {
        printf("%s", termos[i].palavra);

        printf("%lf %lf %lf %lf\n", termos[i].maximo, termos[i].minimo, termos[i].media, termos[i].desvio_padrao);
    }
}

int inicializa_categorias(C *categorias)
{
    categorias->bot = 0;
    categorias->surpreendente = 0;
    categorias->normal = 0;
    categorias->local = 0;
    categorias->irrelevante = 0;
}

C aloca_termos_categorias(Termo *termos, int num_termos, C *categorias)
{
    for (int i = 0; i < num_termos; i++)
    {
        if (termos[i].media >= 60 && termos[i].desvio_padrao > 15)
        {
            termos[i].categoria = 0;
            categorias->bot += 1;
        }
        if (termos[i].media >= 60 && termos[i].desvio_padrao <= 15)
        {
            termos[i].categoria = 1;
            categorias->surpreendente += 1;
        }
        if (termos[i].media < 60 && termos[i].maximo >= 80 && termos[i].minimo > 20)
        {
            termos[i].categoria = 2;
            categorias->normal += 1;
        }
        if (termos[i].media < 60 && termos[i].maximo >= 80 && termos[i].minimo <= 20)
        {
            termos[i].categoria = 3;
            categorias->local += 1;
        }
        if (termos[i].media < 60 && termos[i].maximo < 80)
        {
            termos[i].categoria = 4;
            categorias->irrelevante += 1;
        }
    }
}

void eh_da_categoria(int num_termos, Termo *termos, int num_categoria){
    for (int j = 0; j < num_termos; j++){
        if (termos[j].categoria == num_categoria){
            printf(" %s", termos[j].palavra);
        }
    }

}

void imprime_categorias(C *categorias, Termo *termos, int n)
{
    printf("RESULTADO:\n"); 
    for (int i = 0; i < n - 1; i++)
    {
        if (i == 0)
            printf("Bot (%d):", categorias->bot);
        if (i == 1)
            printf("Surpreendente (%d):", categorias->surpreendente);
        if (i == 2)
            printf("Normal (%d):", categorias->normal);
        if (i == 3)
            printf("Local (%d):", categorias->local);
        if (i == 4)
            printf("Irelevante (%d):", categorias->irrelevante);
        
        printf('\n');
        
    }

    int main()
    {
        int num_termos, dias;
        Termo *termos;
        C *categorias;

        /**
     * Aloca memória dinamicamente
     * */
        scanf("%d %d", &num_termos, &dias);
        termos = malloc(num_termos * sizeof(Termo));
        for (int i = 0; i < num_termos; i++)
        {
            termos[i].palavra = malloc(TAM_TERMO * sizeof(char));
        }
        for (int i = 0; i < num_termos; i++)
        {
            termos[i].relevancia_diaria = malloc(dias * sizeof(double));
        }

        categorias = malloc(sizeof(C));

        le_termos_teclado(num_termos, dias, termos);

        calcular_dados(num_termos, dias, termos);
        imprime_dados(termos, num_termos);

        inicializa_categorias(categorias);
        aloca_termos_categorias(termos, num_termos, categorias);
        imprime_categorias(categorias, termos, NUM_CATEGORIAS);

        /**
     * Libera memória
     * */

        free(categorias);

        for (int i = 0; i < num_termos; i++)
            free(termos[i].relevancia_diaria);
        free(termos);

        return 0;
    }