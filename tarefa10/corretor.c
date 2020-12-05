#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashing.h"
#define M 2000

void comparar_com_dicio(p_hash t, char *palavra)
{
    p_no correto;
    correto = buscar(t, palavra);

    if (correto != NULL)
    {
        printf("verde\n");
    }
    else
    {
        busca_similares(t, palavra);
    }
}

//caso a palavra não seja idêntica, a chave não vai bater
void busca_similares(p_hash t, char *palavra)
{
    p_no buscado = NULL;
    //caso tenha um letra a mais, podemos remover uma a uma e testar
    for (int i = 0; i < strlen(palavra); i++)
    {
        char *nova_palavra = malloc(26 * sizeof(char));
        for (int j = 0; j < strlen(palavra); j++)
        {
            if (j != i)
            {
                strcat(nova_palavra, palavra[j]);
            }
        }
        buscado = buscar(t, nova_palavra);
        free(nova_palavra);

        if (buscado != NULL)
        {
            printf("amarelo\n");
            free(buscado);
            break;
        }
    }

    //caso tenha uma letra a menos, podemos inserir em cada posição
    int letra_a = 97;
    for (int i = 0; i <= strlen(palavra) && buscado == NULL; i++)
    {
        for (int acrescimo = 0; acrescimo < 26 && buscado == NULL; acrescimo++)
        {
            char *nova_palavra = malloc(26 * sizeof(char));

            //copiar palavra acrescentando letra
            for (int j = 0; j <= strlen(palavra); j++)
            {
                //antes de chegar na letra extra
                if (j < i)
                {
                    strcat(nova_palavra, palavra[j]);
                }
                //add letra extra
                if (i == j)
                {
                    int numero_asc = letra_a + acrescimo;
                    char letra = numero_asc;
                    strcat(nova_palavra, letra);
                }

                //depois de passar a letra extra
                if (j > i)
                {
                    strcat(nova_palavra, palavra[j - 1]);
                }
            }

            //para cada acrescimo, fazemos uma busca
            buscado = buscar(t, nova_palavra);
            if (buscado != NULL)
            {
                printf("amarelo\n");
                free(buscado);
                break;
            }
        }
    }

    //se não foi encontrado adicionando ou removendo uma letra, há dois erros
    if (buscado == NULL)
    {
        printf("vermelho\n");
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