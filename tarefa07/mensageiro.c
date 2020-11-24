#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Token
{
    int num;
    char *palavra;
    struct Token *dir, *esq;
} Token;

typedef Token *p_token;

typedef struct Triade
{
    p_token t1, t2, t3;
    int soma;
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
    token->palavra = malloc(num_caracteres * sizeof(char));
    token->num = 0;
    token->dir = token->esq = NULL;
    return token;
}

p_triade alocar_triade()
{
    p_triade triade;
    triade = malloc(sizeof(Triade));
    return triade;
}

p_token inserir(p_token raiz, p_token cartao)
{
    if (raiz == NULL)
    {
        raiz = cartao;
    }
    else if (cartao->num < raiz->num)
    {
        raiz->esq = inserir(raiz->esq, cartao);
    }
    else
    {
        raiz->dir = inserir(raiz->dir, cartao);
    }

    return raiz;
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
    free(raiz->palavra);
    raiz->palavra = min->palavra;
    free(min);
}

p_token remover_rec(p_token raiz, int num)
{

    if (raiz == NULL)
    {
        return NULL;
    }
    //se numero for diferente
    else if (num < raiz->num)
    {
        raiz->esq = remover_rec(raiz->esq, num);
        return raiz;
    }
    else if (num > raiz->num)
    {
        raiz->dir = remover_rec(raiz->dir, num);
        return raiz;
    }
    //se numero for igual
    else if (raiz->esq == NULL)
    {
        p_token aux = raiz->dir;
        free(raiz->palavra);
        free(raiz);
        return aux;
        
    }
    else if (raiz->dir == NULL)
    {
        p_token aux = raiz->esq;
        free(raiz->palavra);
        free(raiz);
        return aux;
    }
    else
    {
        remove_sucessor(raiz);
        return raiz;
    }
}

/**
 *
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

p_token ancestral_a_direita(p_token x){
    if (x == NULL){
        return NULL;
    }
    if (x->pai == NULL || x->pai->esq == x){
        return x->pai;
    }
    else{
        return ancestral_a_direita(x->pai);
    }
}

p_token sucessor(p_token x){
    if (x->dir != NULL){
        return minimo(x->dir);
    }
    else
    {
        return ancestral_a_direita(x);
    }
}

*/

p_token maximo(p_token raiz)
{
    if (raiz == NULL || raiz->dir == NULL)
    {
        return raiz;
    }
    else
    {
        return maximo(raiz->dir);
    }
}

p_token buscar_max(p_token raiz, p_token x)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    else
    {
        p_token dir, esq;
        dir = buscar_max(raiz->dir, x);
        esq = buscar_max(raiz->esq, x);
        if (dir != NULL && dir->num < x->num)
        {
            return dir;
        }
        if (raiz->num < x->num)
        {
            return raiz;
        }
        else
        {
            return esq;
        }
    }
}

p_token antecessor(p_token raiz, p_token x)
{
    if (x->esq != NULL)
    {
        return maximo(x->esq);
    }
    else
    {
        return buscar_max(raiz, x);
    }
}

p_token buscar(p_token raiz, int chave)
{
    if (raiz == NULL || chave == raiz->num)
    {
        return raiz;
    }
    if (chave < raiz->num)
    {
        return buscar(raiz->esq, chave);
    }
    if (chave > raiz->num)
    {
        return buscar(raiz->dir, chave);
    }
    return NULL;
}

/**
int contar_tokens(p_token raiz)
{
    if (raiz != NULL)
    {
        return contar_tokens(raiz->esq) + contar_tokens(raiz->dir) + 1;
    }
    return 0;
}
*/

p_triade encontrar_triade(p_token ABB, p_triade triade, int soma)
{
    int diferenca;
    p_token t1, t2, t3;
    t3 = NULL;

    t1 = maximo(ABB);       //fixa o máximo na 1ª vez
    while (t1->num >= soma) //caso o máximo seja maior que a soma ou igual, vai voltando até achar o primeiro menor
    {
        t1 = antecessor(ABB, t1);
    }

    while (t1 != NULL)
    {
        t2 = t1;

        while (t2 != NULL)
        {
            t2 = antecessor(ABB, t2);
            if (t2 == NULL)
            {
                break;
            }
            diferenca = soma - t1->num - t2->num;

            if (diferenca > 0)
            {
                t3 = buscar(ABB, diferenca);
                if (t3 != NULL)
                {
                    triade->t1 = t1;
                    triade->t2 = t2;
                    triade->t3 = t3;
                }
            }

            if (t3 != NULL)
            {
                break;
            }
        }
        if (t3 != NULL)
        {
            break;
        }
        t1 = antecessor(ABB, t1);
    }
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

    strcpy(novo->palavra, triade->t3->palavra); //copia string do 1º token
    strcat(novo->palavra, triade->t2->palavra); //concatena 1º com 2º
    strcat(novo->palavra, triade->t1->palavra);

    ABB = inserir(ABB, novo);
    return ABB;
}

p_token remover(p_token ABB, p_triade triade)
{
    ABB = remover_rec(ABB, triade->t1->num);
    ABB = remover_rec(ABB, triade->t2->num);
    ABB = remover_rec(ABB, triade->t3->num);

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

void liberar_abb(p_token raiz)
{
    if (raiz != NULL)
    {

        liberar_abb(raiz->dir);
        liberar_abb(raiz->esq);
        free(raiz->palavra);
        free(raiz);
    }
}

void liberar_triade(p_triade triade)
{
    
    free(triade);
}

int main()
{

    do
    {
        p_token ABB; //criar abb vazia para inserir lidos
        ABB = criar_ABB();
        int num_cartoes, num_autoridades;
        if (scanf("%d %d", &num_cartoes, &num_autoridades) <= 0)
        {
            break;
        }

        char *palavra;
        //lê cartões
        for (int i = 0; i < num_cartoes; i++)
        {
            p_token cartao;
            palavra = malloc(6 * sizeof(char));
            cartao = alocar_token(6);
            scanf("%d ", &cartao->num);
            scanf("%*c%[^\"]%*c", palavra);
            strcpy(cartao->palavra, palavra);
            cartao->dir = NULL;
            cartao->esq = NULL;
            free(palavra);
            ABB = inserir(ABB, cartao);
        }

        //remove soma da tríade de cada autoridade se a combinação é possível
        for (int i = 0; i < num_autoridades; i++)
        {
            int soma;
            p_triade triade;
            triade = alocar_triade();

            scanf("%d ", &soma);
            triade->soma = soma;
            triade = encontrar_triade(ABB, triade, soma);
            ABB = concatenar_e_inserir(ABB, triade);
            ABB = remover(ABB, triade);

            liberar_triade(triade);
        }

        imprimir_ordem_crescente(ABB);
        printf("\n");

        liberar_abb(ABB);

    } while (1);

    return 0;
}
