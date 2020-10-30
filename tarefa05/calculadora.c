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

p_lista add_elemento(p_lista lista, char c){

    return lista; 
}

void imprime_lista(p_lista lista){

}





/**
 * Implementacao das funcoes principais
 * */

p_lista converte_str(char *vetor)
{
    p_lista lista;
    lista->tamanho = 0;
    for (int i = 0; vetor[1] != '0'; i++){
        lista = add_elemento(lista, vetor[i]);

    }
    return lista;

}

void executa_operacao(char operacao, p_lista num1, p_lista num2)
{
    p_lista resultado;
    resultado->tamanho = 0;

    if (operacao == '+'){
        resultado = soma(num1, num2);
    }
    else if (operacao == '-'){
        resultado = subtrai(num1, num2);

    }
    else if (operacao == '*'){
        resultado = multiplica(num1, num2);

    }
    else if ((operacao == '/')){
        printf("%c", "0");
    }

    imprime_lista(resultado);
}

/**
 * Implementacao das operacoes da calculadora
 * */

soma(p_lista num1, p_lista num2){

}

subtrai(p_lista num1, p_lista num2){
    
}

multiplica(p_lista num1, p_lista num2){
    
}


int main()
{
    int num_operacoes;
    char *vetor_1, *vetor_2, operacao;
    p_lista num1, num2;

    scanf("%d", num_operacoes);
    for (int i = 0; i < num_operacoes; i++)
    {
        scanf("%c", operacao);
        scanf("%s %s", vetor_1, vetor_2);

        num1 = converte_str(vetor_1);
        num2 = converte_str(vetor_2);

        executa_operacao(operacao, num1, num2);
    }

    return 0;
}