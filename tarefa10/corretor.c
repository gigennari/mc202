#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashing.h"
#define M 8627

//caso a palavra não seja idêntica, a chave não vai bater; vamos buscar para 1 erro
void busca_similares(p_hash t, char *palavra)
{
    p_no buscado = NULL;
    int letra_a = 97;
    int tam_palavra = strlen(palavra);

    //caso tenha um letra a mais, podemos remover uma a uma e testar
    for (int i = 0; i < tam_palavra && buscado == NULL; i++)
    {
        char *nova_palavra = malloc((tam_palavra + 1) * sizeof(char));
        for (int j = 0; j < tam_palavra - 1; j++)
        {
            if (j < i)
            {
                nova_palavra[j] = palavra[j];
            }
            //j >= i, pula letra i, pega j+1
            else
            {
                nova_palavra[j] = palavra[j + 1];
            }
        }
        nova_palavra[tam_palavra - 1] = '\0';
        buscado = buscar(t, nova_palavra);
        free(nova_palavra);

        if (buscado != NULL)
        {
            printf("amarelo\n");
            break;
        }
    }

    //caso uma letra esteja trocada, podemos alterar cada uma
    for (int i = 0; i < tam_palavra && buscado == NULL; i++)
    {
        //testar as 26 letras para cada letra na palavra
        for (int acrescimo = 0; acrescimo < 26 && buscado == NULL; acrescimo++)
        {
            char *nova_palavra = malloc((tam_palavra + 1) * sizeof(char));

            //copia a palavra, alterando a letra i
            for (int j = 0; j < tam_palavra; j++)
            {

                if (j == i)
                {
                    int numero_asc = letra_a + acrescimo;
                    char letra = numero_asc;
                    nova_palavra[j] = letra;
                }
                else
                {
                    nova_palavra[j] = palavra[j];
                }
            }
            nova_palavra[tam_palavra] = '\0';
            //para cada alteração, fazemos uma busca
            buscado = buscar(t, nova_palavra);
            free(nova_palavra);

            if (buscado != NULL)
            {
                printf("amarelo\n");
                break;
            }
        }
    }

    //caso tenha uma letra a menos, podemos inserir em cada posição
    for (int i = 0; i <= tam_palavra && buscado == NULL; i++)
    {
        for (int acrescimo = 0; acrescimo < 26 && buscado == NULL; acrescimo++)
        {
            char *nova_palavra = malloc((tam_palavra + 2) * sizeof(char));

            //copiar palavra acrescentando letra
            for (int j = 0; j <= tam_palavra; j++)
            {
                //antes de chegar na letra extra
                if (j < i)
                {
                    nova_palavra[j] = palavra[j];
                }

                //add letra extra
                if (i == j)
                {
                    int numero_asc = letra_a + acrescimo;
                    char letra = numero_asc;
                    nova_palavra[j] = letra;
                }

                //depois de passar a letra extra
                if (j > i)
                {
                    nova_palavra[j] = palavra[j - 1];
                }
            }
            nova_palavra[tam_palavra + 1] = '\0';
            //para cada acrescimo, fazemos uma busca
            buscado = buscar(t, nova_palavra);
            free(nova_palavra); 

            if (buscado != NULL)
            {
                printf("amarelo\n");
                break;
            }
        }
    }

    //se não foi encontrado alterando, removendo ou adicionando uma letra, há dois erros ou mais
    if (buscado == NULL)
    {
        printf("vermelho\n");
    }
}

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