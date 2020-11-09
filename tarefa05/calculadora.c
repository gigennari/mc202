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

int apenas_zeros(p_lista num){
    p_no no;
    no = num->fim;

    do{
        if (no->dado != 0){
            return 0;
        }
        no = no->ant;

    }while(no != NULL);
    return 1;
}

p_lista eliminar_zeros_inicio(p_lista num){
    p_no aux;

    while(num->ini->dado == 0){
    aux = num->ini;
    num->ini = num->ini->prox;
    free(aux);
    }

    return num;

}

void imprime_lista(p_lista lista)
{
    if (lista != NULL)
    {
        
        if (apenas_zeros(lista)){
            printf("%d", 0);
        }
        else{
        lista = eliminar_zeros_inicio(lista);
        p_no atual;
        atual = lista->ini;

        do
        {
            printf("%d", atual->dado);
            atual = atual->prox;
        } while (atual != NULL);
        free(atual);
        }
        printf("\n");
    }
}

void liberar_memoria(p_lista lista)
{
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

//soma
void somar_em_no(p_lista num1, p_lista num2, p_lista resultado, int x)
{

    if ((num1->ini == num1->fim) && (num2->ini == num2->fim))
    {
        resultado = add_esquerda(resultado, x);
    }
    else if (num1->ini == num1->fim)
    {
        num2->fim->ant->dado += 1;
    }
    else if (num2->ini == num2->fim)
    {
        num1->fim->ant->dado += 1;
    }
    else
    {
        num1->fim->ant->dado += 1;
    }
}
p_lista add_resultado(p_lista num1, p_lista num2, p_lista resultado, int soma)
{
    if (soma >= 10)
    {
        int x = soma % 10;
        resultado = add_esquerda(resultado, x);
        somar_em_no(num1, num2, resultado, 1);
    }
    else
    {
        resultado = add_esquerda(resultado, soma);
    }
    return resultado;
}

p_lista soma(p_lista resultado, p_lista num1, p_lista num2)
{
    int soma;
    for (int i = 0; (i < num1->tamanho) && (i < num2->tamanho); i++)
    {
        soma = num1->fim->dado + num2->fim->dado;

        resultado = add_resultado(num1, num2, resultado, soma);

        num1->fim = num1->fim->ant;
        num2->fim = num2->fim->ant;
    }

    //atualiza tamanhos
    if (num1->tamanho > num2->tamanho)
    {
        num1->tamanho = num1->tamanho - num2->tamanho;
        num2->tamanho = 0;
    }
    else if (num2->tamanho > num1->tamanho)
    {
        num2->tamanho = num2->tamanho - num1->tamanho;
        num1->tamanho = 0;
    }

    /**
     * Caso o numero 1 tenha mais algarismos que o 2,
     * precisamos terminar de copiá-lo
     * */
    if (num1->fim != num1->ini->ant)
    {
        do
        {
            resultado = add_esquerda(resultado, num1->fim->dado);
            num1->fim = num1->fim->ant;
        } while (num1->fim != num1->ini->ant);
    }
    else if (num2->fim != num1->ini->ant)
    {
        do
        {
            resultado = add_esquerda(resultado, num2->fim->dado);
            num2->fim = num2->fim->ant;
        } while (num2->fim != num1->ini->ant);
    }

    return resultado;
}

//subtrai

p_lista completar_zeros(p_lista num, int qtde)
{
    for (int i = 0; i < qtde; i++)
    {
        num = add_esquerda(num, 0);
    }
    return num;
}

p_lista numero_maior(p_lista num1, p_lista num2)
{

    if (num1->tamanho > num2->tamanho)
    {
        return num1;
    }
    else if (num2->tamanho > num1->tamanho)
    {
        return num2;
    }
    else
    {
        p_no atual_1, atual_2;
        atual_1 = num1->ini;
        atual_2 = num2->ini;

        while (atual_1 != num1->fim)
        {
            if (atual_1->dado > atual_2->dado)
            {
                return num1;
            }
            else if (atual_2->dado > atual_1->dado)
            {
                return num2;
            }

            atual_1 = atual_1->prox;
            atual_2 = atual_2->prox;
        } 

        //se forem iguais, tanto faz qual devolver
        return num1;
    }
}

p_lista achar_dif_zero(p_lista num)
{
    p_no atual;
    atual = num->fim->ant; //já sabemos que é 0
    int i = 0;

    while (atual->dado == 0)
    {
        atual = atual->ant;
        i += 1;
        if (atual->dado != 0)
        {
            atual->dado -= 1;
        }
    }

    for (int j = 0; j < i; j++)
    {
        num->fim->ant->dado = 9;
        
    }

    num->fim->dado += 10;

    return num;
}
p_lista subtrai(p_lista resultado, p_lista num1, p_lista num2)
{
    p_lista maior, menor;
    maior = numero_maior(num1, num2);
    if (maior == num1)
    {
        menor = completar_zeros(num2, num1->tamanho - num2->tamanho);
    }
    else
    {
        menor = completar_zeros(num1, num2->tamanho - num1->tamanho);
    }

    int diferenca;
    do
    {
        if (maior->fim->dado < menor->fim->dado)
        {

            if (maior->fim->ant->dado == 0)
            {
                maior = achar_dif_zero(maior);
            }
            else
            {
                maior->fim->ant->dado -= 1;
                maior->fim->dado += 10;
            }
        }
        diferenca = maior->fim->dado - menor->fim->dado;
        resultado = add_esquerda(resultado, diferenca);
        maior->fim = maior->fim->ant;
        menor->fim = menor->fim->ant;
    } while (maior->fim != maior->ini->ant);

    return resultado;
}

//multiplica
/**
p_lista multiplica(p_lista resultado, p_lista num1, p_lista num2)
{
    p_lista parcial;
    p_no atual;
    atual = num2->fim;
    int iter = 0;
    int produto, restante;

    do
    {
        do
        {
            produto = num1->fim->dado * atual->dado;


            iter += 1;
            atual = atual->ant;
        } while (atual != num2->ini);

        num1->fim = num1->fim->ant;

    } while (num1->fim != num1->ini);
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

    else if (operacao == '-')
    {
        resultado = subtrai(resultado, num1, num2);
    }
    /**
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

    liberar_memoria(num1);
    liberar_memoria(num2);
    liberar_memoria(resultado);
}

p_lista ler_numero(p_lista num)
{
    char caractere;
    scanf("%c", &caractere);
    while (caractere <= '9' && caractere >= '0')
    {

        if (caractere != '\0')
        {
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

    scanf("%d ", &num_operacoes);

    for (int i = 0; i < num_operacoes; i++)
    {
        num1 = criar_lista();
        num2 = criar_lista();
        scanf("%c ", &operacao);
        num1 = ler_numero(num1);
        num2 = ler_numero(num2);
        executa_operacao(operacao, num1, num2);
    }
    return 0;
}
