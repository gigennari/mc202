#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashing.h"

void comparar_com_dicio(p_hash t, char *palavra)
{
    p_no correto;
    correto = buscar(t, palavra);
    
    if (correto != NULL)
    {
        if (strlen(correto->palavra) == strlen(palavra))  //se o tamanho for igual
        {
            if (strcmp(correto->palavra, palavra) == 0)   // se strcmp == 0, printa verde
            {
                printf("verde\n");
            }
            else                                         //caso contrário, duas letras trocadas, printa vermelho
            {
                printf("vermelho\n");
            }
        }
        else                                            //com tamanho diferente, uma letra a mais ou a menos, printa amarelo
        {
            printf("amarelo\n");
        }
    }
}

int main()
{
    int num_dicio, num_texto;
    scanf("%d %d", &num_dicio, &num_texto);

    //cria hash table
    p_hash t = criar_hash();

    // lê palavras e insere na hash table do dicionário
    for (int i = 0; i < num_dicio; i++)
    {
        char *palavra = malloc(26 * sizeof(char));
        scanf("%s ", palavra);
        t = inserir(t, palavra);
        free(palavra);
    }

    //lê palavra do texto e compara uma a uma com as do dicionário
    for (int i = 0; i < num_texto; i++)
    {
        char *palavra = malloc(26 * sizeof(char));
        scanf("%s ", palavra);
        comparar_com_dicio(t, palavra);
        free(palavra);
    }

    //libera memória alocada
    destruir_hash(t);

    return 0;
}