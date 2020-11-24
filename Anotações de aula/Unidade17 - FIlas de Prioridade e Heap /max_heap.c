#include <stdio.h>
#include <stdlib.h>

#define PAI(i) ((i - 1) / 2)
#define F_DIR(i) (2 * i + 2)
#define F_ESQ(i) (2 * i + 1)

typedef struct
{
    char nome[20];
    int chave;
} Item;


typedef struct
{
    Item *v;
    int n, capacidade;
} FP;

typedef FP *p_fp;

p_fp aloca_fprio(int capacidade){
    p_fp fprio = malloc(sizeof(FP));
    fprio->capacidade = capacidade;
    fprio->n = 0;
    fprio->v = malloc(sizeof(Item));
    return fprio;
}

void troca(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * no máximo, subimos até a raiz
 * O(lg n)
 * */
void inserir_heap(p_fp fprio, int n, Item item)
{
    fprio->v[fprio->n] = item;  //coloca na última posição
    fprio->n++; //aumenta tamanho na struct
    sobe_no_heap(fprio, fprio->n - 1);  
}

/**
 * Casos básicos: k é a raíz da árvore ou 
 * o pai é maior que o elemento
 * O(log (n))
 * */
void sobe_no_heap(p_fp fprio, int k)
{
    if (k > 0 && fprio->v[PAI(k)].chave < fprio->v[k].chave) //a chave do atual é maior, trocar
    {
        troca(&fprio->v[k], &fprio->v[PAI(k)]);
        sobe_no_heap(fprio, PAI(k));
    }
}

void sobe_heap_iter(p_fp fprio, int k)
{
    while (k > 0)
    {
        if (fprio->v[PAI(k)].chave < fprio->v[k].chave)
        {
            troca(&fprio->v[PAI(k)], &fprio->v[k]);
            k = PAI(k);
        }
    }
}

/**
 * O(log (n))
 * */
Item extrai_max(p_fp fprio)
{
    Item max = fprio->v[0];
    troca(fprio->v[0].chave, fprio->v[fprio->n].chave);
    fprio->n--;
    desce_no_heap(fprio, 0); //corige raiz, que falha propriedade de max heap
    return max;
}

void desce_no_heap(p_fp fprio, int k)
{
    int maior_filho;
    if (F_ESQ(k) < fprio->n)
    {
        maior_filho = F_ESQ(k);
        if (F_DIR(k) < fprio->n &&
            fprio->v[F_ESQ(k)].chave < fprio->v[F_DIR(k)].chave) // se o filho esq for menor q o dir
        {
            maior_filho = F_DIR(k);
        }
    }
    if (fprio->v[k].chave < fprio->v[maior_filho].chave)
    {
        troca(&fprio->v[k], &fprio->v[maior_filho]);
        desce_no_heap(fprio, maior_filho);
    }
}

/**
 * k é a posiçao atual do elemento e valor é sua nova 
 * chave 
 * */
void muda_prioridade(p_fp fprio, int k, int valor)
{

    fprio->v[k].chave = valor;

    // se o novo valor da prioridade for maior que a chave anterior, sobre no heap
    if (fprio->v[k].chave < valor)
    {

        sobe_no_heap(fprio, k);
    }
    else
    {
        desce_no_heap(fprio, k);
    }
}

int encontra_indice(){
    
}

int main(){

    int vetor[7] = {20, 10, 5, 30, 50, 45, 35};
    p_fp fprio = aloca_fprio(7);
    for(int i = 0; i < 7; i++){
        Item item;
        item->chave = vetor[i];
        fprio->n++;
        inserir_heap(fprio, fprio->n, item);
    }

    return 0;

}