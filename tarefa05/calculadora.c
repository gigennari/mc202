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
        lista->ini = novo;
        lista->fim = novo;
        novo->prox = novo;
        novo->ant = novo;
    }
    else
    {
        novo->prox = lista->ini;
        novo->ant = lista->fim;
        lista->ini->ant = novo;
        lista->fim->prox = novo;
        lista->fim = novo;
    }
    lista->tamanho += 1;

    return lista;
}

p_lista add_esquerda(p_lista lista, int c)
{

    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = c;
    if (lista == NULL)
    {
        lista->ini = novo;
        lista->fim = novo;
        novo->prox = novo;
        novo->ant = novo;
    }
    else
    {
        novo->prox = lista->ini;
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->ini->ant = novo;
        lista->ini = novo;
    }
    lista->tamanho += 1;

    return lista;
}

void imprime_lista(p_lista lista)
{
    p_no no;
    no = lista->ini;

    do
    {
        printf("%d\n", no->dado);
        no = no->prox;
    } while (no != lista->ini);
}

void libera_memoria(p_no no)
{
    libera_memoria(no->prox);
    free(no);
}


/**
 * Implementacao das operacoes da calculadora
 * */

p_lista soma(p_lista resultado, p_lista num1, p_lista num2)
{
    for (int i = 0; i < num1->tamanho && i < num2->tamanho; i++)
    {
    }
    if (num1->tamanho > num2->tamanho)
    {
    }
    else if (num1->tamanho < num2->tamanho)
    {
    }
    return resultado;
}

void add_resultado(p_lista resultado, int num)
{
    if (num > 10)
    {
        int x = num % 10;
        add_esquerda
    (resultado, x);
        int resto = num - x;
        add_resultado(resultado, resto);
    }
    else
    {
        add_esquerda
    (resultado, num);
    }
}

p_lista subtrai(p_lista resultado, p_lista num1, p_lista num2)
{
}

p_lista multiplica(p_lista resultado, p_lista num1, p_lista num2)
{
} 
/**
 * Implementacao das funcoes principais
 * */


p_lista converte_str(char *vetor)
{

    p_lista lista = criar_lista();
    lista->tamanho = 0;

    int tamanho_str = 0;
    for (int i = 0; vetor[i] != '0'; i++){
        tamanho_str += 1;
    }

    for (int i = tamanho_str; i > 0 ; i--)
    {
        int num = vetor[i] - '0';
        lista = add_esquerda
    (lista, num);
    }
    return lista;
}

void executa_operacao(char operacao, p_lista num1, p_lista num2)
{
    p_lista resultado = malloc(sizeof(Lista));
    resultado->tamanho = 0;

    if (operacao == '+')
    {
        resultado = soma(resultado, num1, num2);
    }
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

    imprime_lista(resultado);
    printf('\n');
    libera_memoria(num1->ini);
    libera_memoria(num2->ini);
    libera_memoria(resultado->ini);
    free(num1);
    free(num2);
    free(resultado);
}

p_lista ler_numero(p_lista num){
    char caractere;
    do{
            scanf("%c", &caractere);

            if (caractere != '\0'){
                int algarismo = caractere - '0';
                add_direita(num, algarismo);
            }
            
    }while(caractere != '0');

    return num;
}

int main()
{
    int num_operacoes;
    char operacao;
    p_lista num1, num2;

    scanf("%d", num_operacoes);
    
    for (int i = 0; i < num_operacoes; i++)
    {
        scanf("%c", operacao);
        
        num1 = ler_numero(num1);
        num2 = ler_numero(num2);

        executa_operacao(operacao, num1, num2);

    }

    return 0;
}