#include <stdio.h>

int prefixo_viavel(int vetor[], int m){
    for (int i = 0; i < m; i++){
        // se está na mesma linha 
        if (vetor[i] ==  vetor[m-1]){
            return 0;
        }
        // se está na mesma diagonal --> vê se del x == del y 
        if ((m-1) - i == abs(vetor[m-1]) - vetor[i]){
            return 0;
        }
    }
}

/**
 * Devolve 1 se nenhuma dama é atacada
 * */
int disposicao_valida(int vetor[], int n)
{
}

/**
 * Devolve 1 se existe alguma disposicao valiudas que mantem 
 * a posicao das m primeiras damas
 * */
int existe_solucao(int vetor[], int n, int m)
{
    if (!prefixo_viavel(vetor, m))
        return 0;
    if (n == m)
    {
        if (disposicao_valida(vetor, n))
        {
            imprimir_vetor(vetor, n);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        vetor[m] = i;
        if (existe_solucao(vetor, m + 1, n)) 
        {
            return 1;
        }
    }
}

void imprimir_vetor(int vetor[], int n)
{
    for (int i = 0; i < n; i++){
        printf("%d", vetor[i]);
    }
    printf('\n');
}

int main()
{
    int *prefixo, n, m;

    if (prefixo_viavel(prefixo, m)){
        existe_solucao(prefixo, n , m);
    }
}