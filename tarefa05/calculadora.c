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
        lista = malloc(sizeof(Lista));
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


void somar_em_no(p_lista num1, p_lista num2, p_lista resultado, int x){
    
    if ((num1->ini == num1->fim)  && (num2->ini == num2->fim)){
        add_esquerda(resultado, x);
    }
    else if ((num1->ini == num1->fim)  && (num2->ini != num2->fim)){
        num2->fim->ant->dado += 1; 
    }
    else if ((num1->ini != num1->fim)  && (num2->ini == num2->fim))
    {
        num1->fim->ant->dado += 1;
    }
}
void add_resultado(p_lista num1, p_lista num2, p_lista resultado, int soma){
    if (soma > 10)
    {
        int x = soma % 10;
        add_esquerda(resultado, x);
        somar_em_no(num1, num2, resultado, 1);
    }
    else
    {
        add_esquerda(resultado, soma);
    }
}

p_lista soma(p_lista resultado, p_lista num1, p_lista num2)
{
    for (int i = 0; (i <= num1->tamanho) || (i <= num2->tamanho) ; i++)
    {
        int soma = num1->fim->dado + num2->fim->dado;
        
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
        for (int i = 0; num1->ini != num1->fim; i++){
            add_esquerda(resultado, num1->fim->dado);
            num1->fim = num1->fim->ant;
        }
    }
    else if (num2->ini != num2->fim)
    {
        for (int i = 0; num2->ini != num2->fim; i++){
            add_esquerda(resultado, num2->fim->dado);
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

    libera_memoria(num1->ini);
    libera_memoria(num2->ini);
    libera_memoria(resultado->ini);
    free(num1);
    free(num2);
    free(resultado);
}

p_lista ler_numero(){
    char caractere;
    p_lista num = malloc(sizeof(Lista));
    
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

    scanf("%d", &num_operacoes);
    
    for (int i = 0; i < num_operacoes; i++)
    {
        char operacao;
        scanf("%c", &operacao);

        
        p_lista num1 = ler_numero();
        p_lista num2 = ler_numero();

        imprime_lista(num1);

        executa_operacao(operacao, num1, num2);

    }

    return 0;
}