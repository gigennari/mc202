/*
Lista legal --> para todo elemento x pertencente à lista, 
existe exatamente x cópias de x 

Entrada: uma lista de números
(Obs: a lista da entrada pode não ser uma lista legal, então 
queremos descobrir qual a menor quantidade de elementos a serem removidos
para que ela seja uma lista legal)

Saída: menor quantidade de números que devem ser removidos para 
a  lista ser uma lista legal

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

enum Cor
{
    VERMELHO,
    PRETO
};

typedef struct No
{
    long int chave, contagem;
    enum Cor cor;
    struct No *esq, *dir;
} No;

typedef No *p_no;

int ehVermelho(p_no x)
{
    if (x == NULL)
    {
        return 0;
    }
    else
    {
        return x->cor == VERMELHO;
    }
}

int ehPreto(p_no x)
{
    if (x == NULL)
    {
        return 1;
    }
    else
    {
        return x->cor == PRETO;
    }
}

void sobe_vermelho(p_no raiz)
{
    raiz->cor = VERMELHO;
    raiz->esq->cor = PRETO;
    raiz->dir->cor = PRETO;
}

p_no rotaciona_para_esquerda(p_no raiz)
{
    p_no x = raiz->dir;
    raiz->dir = x->esq;
    x->esq = raiz;
    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}

p_no rotaciona_para_direita(p_no raiz)
{
    p_no x = raiz->esq;
    raiz->esq = x->dir;
    x->dir = raiz;
    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}

p_no inserir_rec(p_no raiz, long int chave)
{

    if (raiz == NULL)
    {
        p_no novo;
        novo = malloc(sizeof(No));
        novo->esq = novo->dir = NULL;
        novo->chave = chave;
        novo->contagem = 1;
        novo->cor = VERMELHO;

        return novo;
    }

    if (chave < raiz->chave)
    {
        raiz->esq = inserir_rec(raiz->esq, chave);
    }
    else if (chave > raiz->chave)
    {
        raiz->dir = inserir_rec(raiz->dir, chave);
    }
    else if (raiz->chave == chave)
    {
        raiz->contagem += 1;
    }

    if (ehVermelho(raiz->dir) && ehPreto(raiz->esq))
    {
        raiz = rotaciona_para_esquerda(raiz);
    }
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->esq->esq))
    {
        raiz = rotaciona_para_direita(raiz);
    }
    if (ehVermelho(raiz->esq) && ehVermelho(raiz->dir))
    {
        sobe_vermelho(raiz);
    }
    return raiz;
}

p_no inserir(p_no raiz, long int chave)
{
    raiz = inserir_rec(raiz, chave);
    raiz->cor = PRETO;
    return raiz;
}

p_no buscar(p_no raiz, long int chave)
{
    if (raiz == NULL || chave == raiz->chave)
    {
        return raiz;
    }

    if (chave < raiz->chave)
    {
        return buscar(raiz->esq, chave);
    }
    else // (chave > raiz->chave)
    {
        return buscar(raiz->dir, chave);
    }
}

void numero_chaves(p_no raiz, long int chave)
{

    p_no buscado;
    //buscar nó com a chave
    buscado = buscar(raiz, chave);
    //devolver contagem
    if (buscado != NULL)
    {
        printf("%ld\n", buscado->contagem);
    }
    else
    {
        printf("0\n");
    }
}

p_no maximo(p_no raiz)
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

p_no buscar_max(p_no raiz, p_no x)
{
    
    if (raiz == NULL)
    {
        return NULL;
    }
    else
    {
        p_no dir, esq;
        dir = buscar_max(raiz->dir, x);
        esq = buscar_max(raiz->esq, x);
        if (dir != NULL && dir->chave < x->chave)
        {
            return dir;
        }
        if (raiz->chave < x->chave)
        {
            return raiz;
        }
        else
        {
            return esq;
        }
    }
}

p_no antecessor(p_no raiz, p_no x)
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

//vai do máximo para o mínimo, percorrendo a árvore e contabilizando token a serem removidos
int percorre_arvore(p_no raiz)
{
    int quantidade = 0;
    p_no atual;
    atual = maximo(raiz);

    while (atual != NULL)
    {
        if (atual->chave != atual->contagem)
        {
            if (atual->contagem > atual->chave)
            {
                quantidade += (atual->contagem - atual->chave);
            }
            else
            {
                quantidade += atual->contagem;
            }
        }
        atual = antecessor(raiz, atual);
    }

    return quantidade;
}

void menor_qtde_remover(p_no raiz)
{
    int quantidade = 0;

    quantidade = percorre_arvore(raiz);

    printf("%d\n", quantidade);
}

void liberar_arvore(p_no raiz)
{
    if (raiz != NULL)
    {
        liberar_arvore(raiz->dir);
        liberar_arvore(raiz->esq);
        free(raiz);
    }
}

int main()
{
    int qtde_inicial, num_op;
    p_no raiz = NULL;

    scanf("%d %d", &qtde_inicial, &num_op);

    for (int i = 0; i < qtde_inicial; i++)
    {
        long int chave;
        scanf("%ld", &chave);
        raiz = inserir(raiz, chave);
    }
    printf("leu arvore");
    for (int i = 0; i < num_op; i++)
    {
        int operacao;
        scanf("%d", &operacao);

        if (operacao == 1)
        {
            long int chave;
            scanf("%ld", &chave);

            raiz = inserir(raiz, chave);
        }

        else if (operacao == 2)
        {
            long int chave;
            scanf("%ld", &chave);
            numero_chaves(raiz, chave);
        }
        else
        {
            menor_qtde_remover(raiz);
        }
    }

    liberar_arvore(raiz);

    return 0;
}