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

enum Cor
{
    VERMELHO,
    PRETO
};

typedef struct No
{
    int chave, contagem;
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
        return 0;
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

p_no inserir_rec(p_no raiz, int chave, int contagem)
{
    p_no novo;
    if (raiz == NULL)
    {
        novo = malloc(sizeof(No));
        novo->esq = novo->dir = NULL;
        novo->chave = chave;
        novo->chave = contagem;
        novo->cor = VERMELHO;
        return novo;
    }
    if (chave < raiz->chave)
    {
        raiz->esq = inserir_rec(raiz->esq, chave);
    }
    else
    {
        raiz->dir = inserir_rec(raiz->dir, chave);
    }
    return raiz;
}

p_no inserir(p_no raiz, int chave, int contagem)
{
    raiz = inserir_rec(raiz, chave, contagem);
    raiz->cor = PRETO;
    //ainda precisamos corrigir as propriedades da raiz
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

p_no buscar(p_no raiz, int chave){
    if (raiz == NULL || chave == raiz->chave)
    {
        return raiz;
    }
    if (chave < raiz->chave)
    {
        return buscar(raiz->esq, chave);
    }
    if (chave > raiz->chave)
    {
        return buscar(raiz->dir, chave);
    }
} 

void numero_chaves(p_no raiz, int chave){

    p_no buscado;
    //buscar nó com a chave 
    buscado = buscar(raiz, chave);
    //devolver contagem 
    printf("%d\n", buscado->contagem);
}

int menor_qtde_remover(p_no raiz)
{
    int quantidade = 0;
    //percorrer toda a árvore
        //se chave != contagem
            //quantidade += contagem;

    printf("%d\n", quantidade);
}

/*
void liberar_arvore(p_no raiz)
{
}
*/

int main()
{
    int qtde_inicial, num_op;
    p_no raiz = NULL;

    scanf("%d %d", &qtde_inicial, &num_op);

    for (int i = 0; i < qtde_inicial; i++)
    {
        int chave;
        scanf("%d ", &chave);
        //antes de inserir, precisamos verificar se o nó já existe na árvore 
        p_no no;
        no = buscar(raiz, chave);

        //se não estiver na árvore, insere
        if(no == NULL){
            raiz = inserir(raiz, chave, 1);
        }
        //se já estiver, basta incrementar a contagem
        else{
            no->contagem++;
        }
        
    }

    for (int i = 0; i < num_op; i++)
    {
        int operacao;
        scanf("%d ", &operacao);

        if(operacao == 1)
        {
            int chave;
            scanf("%d ", &chave);
            //antes de inserir, precisamos verificar se o nó já existe na árvore 
            p_no no;
            no = buscar(raiz, chave);

            //se não estiver na árvore, insere
            if(no == NULL){
                raiz = inserir(raiz, chave, 1);
            }
            //se já estiver, basta incrementar a contagem
            else{
                no->contagem++;
            }
        }
        
        else if(operacao == 2)
        {
            int chave;
            int contagem = 0;
            scanf("%d ", &chave);
            contagem = contar_chaves(raiz, chave, contagem);
        }
        /*
        else
        {
            int menor_qtde;
            menor_qtde = menor_qtde_remover(raiz);
        }
        */
    }

    /*
    liberar_arvore(raiz);
    */
    return 0;
}