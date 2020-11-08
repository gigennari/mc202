#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *prox;
    struct No *ant;
} No;

typedef struct No *p_no;

typedef struct Lista
{
    int tamanho;
    p_no ini, fim;

} Lista;

typedef struct Lista *p_lista;

/**
 * Implementacao das funcoes para ponteiros de listas e ponteiros de nós 
 * */

p_lista criar_lista()
{
    return NULL;
}


p_lista add_direita(p_lista lista, int c)
{

    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = c;
    if (lista == NULL)
    {
        lista = malloc(sizeof(Lista));
        lista->ini = novo;
        lista->fim = novo;
        lista->tamanho = 1;
        novo->prox = NULL;
        novo->ant = NULL;
    }
    else
    {
        novo->prox = NULL;
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->tamanho += 1;
    }
    return lista;
}

p_lista add_esquerda(p_lista lista, int c)
{

    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = c;
    if (lista == NULL)
    {
        lista = malloc(sizeof(Lista));
        lista->ini = novo;
        lista->fim = novo;
        lista->tamanho = 1;
        novo->prox = NULL;
        novo->ant = NULL;
    }
    else
    {
        novo->prox = lista->ini;
        novo->ant = NULL;
        lista->ini->ant = novo;
        lista->ini = novo;
        lista->tamanho += 1;
    }
    return lista;
}

void imprime_lista(p_lista lista)
{
    if (lista != NULL)
    {
        p_no atual;
        atual = malloc(sizeof(No));
        atual = lista->ini;
        
        do{
            printf("%d", atual->dado);
            atual = atual->prox;
        }while(atual != NULL);
        
        free(atual);
    }
}

void liberar_memoria(p_lista lista){
    p_no no;
    no = lista->ini;
    while (no != NULL)
    {
        p_no aux = no;
        no = no->prox;
        free(aux);
    }
    free(lista);
    free(no);
    
}


/**
 * Implementacao das operacoes da calculadora
 * */


void somar_em_no(p_lista num1, p_lista num2, p_lista resultado, int x){
    
    if ((num1->ini == num1->fim)  && (num2->ini == num2->fim)){
        resultado = add_esquerda(resultado, x);
    }
    else if (num1->ini == num1->fim){
        num2->fim->ant->dado += 1; 
    }
    else if (num2->ini == num2->fim)
    {
        num1->fim->ant->dado += 1;
    }
}
void add_resultado(p_lista num1, p_lista num2, p_lista resultado, int soma){
    if (soma > 10)
    {
        int x = soma % 10;
        resultado = add_esquerda(resultado, x);
        somar_em_no(num1, num2, resultado, 1);
    }
    else
    {
        resultado = add_esquerda(resultado, soma);
    }
}

p_lista soma(p_lista resultado, p_lista num1, p_lista num2)
{
    int soma;
    for (int i = 0; (i < num1->tamanho) && (i < num2->tamanho); i++)
    {
        soma = num1->fim->dado + num2->fim->dado;
        
        add_resultado(num1, num2, resultado, soma);

        num1->fim = num1->fim->ant;
        num2->fim = num2->fim->ant;
    }

    /**
     * Caso o numero 1 tenha mais algarismos que o 2,
     * precisamos terminar de copiá-lo
     * */
    if (num1->ini != num1->fim)
    {
        while(num1->ini != num1->fim){
            resultado = add_esquerda(resultado, num1->fim->dado);
            num1->fim = num1->fim->ant;
        }
    }
    else if (num2->ini != num2->fim)
    {
        
        while(num2->ini != num2->fim){
            resultado = add_esquerda(resultado, num2->fim->dado);
            num2->fim = num2->fim->ant;
        }
    }

    return resultado;
}





/**
 * 
p_lista subtrai(p_lista resultado, p_lista num1, p_lista num2)
{
    return NULL;
}

p_lista multiplica(p_lista resultado, p_lista num1, p_lista num2)
{
    return NULL; 
} 
*/

/**
 * Implementacao das funcoes principais
 * */


void executa_operacao(char operacao, p_lista num1, p_lista num2)
{
    p_lista resultado = criar_lista();

    if (operacao == '+')
    {
        resultado = soma(resultado, num1, num2);
    }
    /**
    else if (operacao == '-')
    {
        resultado = subtrai(resultado, num1, num2);
    }
    else if (operacao == '*')
    {
        resultado = multiplica(resultado, num1, num2);
    }
    else if ((operacao == '/'))
    {
        printf("%d", 0);
    }
    */

    imprime_lista(resultado);
    printf("\n");

    liberar_memoria(num1);
    liberar_memoria(num2);
    liberar_memoria(resultado);
}

p_lista ler_numero(p_lista num){
    char caractere;
    scanf("%c", &caractere);
    while(caractere <= '9' && caractere >= '0'){
    
            if (caractere != '\0'){
                int algarismo = caractere - '0';
                num = add_direita(num, algarismo);
                scanf("%c", &caractere);
            }       
    }

    return num;
}

int main()
{
    int num_operacoes;
    char operacao;
    p_lista num1, num2;
    num1 = criar_lista();
    num2 = criar_lista();
    scanf("%d ", &num_operacoes);

    for (int i = 0; i < num_operacoes; i++)
    {
        scanf("%c ", &operacao);
        num1 = ler_numero(num1);
        num2 = ler_numero(num2);
        imprime_lista(num1);
        executa_operacao(operacao, num1, num2);
    }
    return 0;
}

