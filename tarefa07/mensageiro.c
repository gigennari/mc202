#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Token
{
    int num;
    char *palavra;
    struct Token *dir, *esq, *pai;
} Token;

typedef Token *p_token;

typedef struct Triade
{
    p_token t1, t2, t3;
    int soma, atual;
} Triade;

typedef Triade *p_triade;

p_token criar_ABB()
{
    return NULL;
}

p_token alocar_token(int num_caracteres)
{
    p_token token;
    token = malloc(sizeof(Token));
    token->palavra = malloc(num_caracteres * sizeof(num_caracteres));
    return token;
}

p_triade alocar_triade()
{
    return NULL;
}

p_token inserir(p_token raiz, p_token cartao)
{
    if (raiz == NULL)
    {
        raiz = cartao;
    }
    else if (cartao->num < raiz->num)
    {
        raiz->esq = inserir(raiz->esq, cartao->num);
    }
    else
    {
        raiz->dir = inserir(raiz->dir, cartao->num);
    }

    return raiz;
}

p_token ler_token(ABB)
{
    p_token cartao;
    cartao = alocar_token(6);
    scanf("%d", cartao->num);
    scanf("%*c%[^\"]%*c", cartao->palavra);
    ABB = inserir(ABB, cartao);
    return ABB;
}

void remove_sucessor(p_token raiz)
{
    p_token min = raiz->dir; //será o minimo da subarvore direita
    p_token pai = raiz;      //pai do nó mínimo
    while (min->esq != NULL)
    {
        pai = min;
        min = min->esq;
    }
    if (pai->esq == min)
    {
        pai->esq = min->dir;
    }
    else
    {
        pai->dir = min->dir;
    }
    raiz->num = min->num;
}

p_token remover_rec(p_token raiz, int num)
{

    if (raiz == NULL)
    {
        return NULL;
    }
    else if (num < raiz->num)
    {
        raiz->esq = remover_rec(raiz->esq, num);
    }
    else if (num > raiz->num)
    {
        raiz->dir = remover_rec(raiz->dir, num);
    }
    else if (raiz->esq == NULL)
    {
        return raiz->dir;
    }
    else if (raiz->dir == NULL)
    {
        return raiz->esq;
    }
    else
    {
        remove_sucessor(raiz);
    }
    return raiz;
}

p_token minimo(p_token raiz)
{
    if (raiz == NULL || raiz->esq == NULL)
    {
        return raiz;
    }
    else
    {
        return minimo(raiz->esq);
    }
}

p_token maximo(p_token raiz)
{
    if (raiz == NULL || raiz->dir == NULL)
    {
        return raiz;
    }
    else
    {
        return minimo(raiz->dir);
    }
}



p_triade encontar_triade(p_token ABB, p_triade triade, int soma)
{

    return triade;
}

p_token concatenar_e_inserir(p_token ABB, p_triade triade)
{
    int num_caracteres = 1;
    num_caracteres += strlen(triade->t1->palavra);
    num_caracteres += strlen(triade->t2->palavra);
    num_caracteres += strlen(triade->t3->palavra);

    
    p_token novo = alocar_token(num_caracteres);
    novo->num = triade->soma;
    
    strcpy(novo->palavra, triade->t1->palavra); //copia string do 1º token
    strcat(novo->palavra, triade->t2->palavra);    //concatena 1º com 2º
    strcat(novo->palavra, triade->t3->palavra);
    
    inserir(ABB, novo);
    return ABB;
}

p_token remover(p_token ABB, p_triade triade)
{
    remover_rec(ABB, triade->t1->num);
    remover_rec(ABB, triade->t2->num);
    remover_rec(ABB, triade->t3->num);

    return ABB;
}

void imprimir_ordem_crescente(p_token raiz)
{
    if (raiz != NULL)
    {

        imprimir_ordem_crescente(raiz->esq);
        printf("%s", raiz->palavra);
        imprimir_ordem_crescente(raiz->dir);
    }
}

int main()
{
    int retorno = 1;
    do
    {
        p_token ABB; //criar abb vazia para inserir lidos
        ABB = criar_ABB();
        int num_cartoes, num_autoridades;
        scanf("%d %d", &num_cartoes, &num_autoridades);

        //lê cartões
        for (int i = 0; i < num_cartoes; i++)
        {
            ABB = ler_token(ABB);
        }

        //remove soma da tríade de cada autoridade se a combinação é possível
        for (int i = 0; i < num_autoridades; i++)
        {
            int soma;
            p_triade triade;

            scanf("%d ", &soma);
            triade = encontar_triade(ABB, triade, soma);
            ABB = concatenar_e_inserir(ABB, triade);
            ABB = remover(ABB, triade);
        }

        imprime_ordem_crescente();

    } while (retorno != -1);

    return 0;
}
