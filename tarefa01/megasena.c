/*
Mega Sena

Da dvisão do prêmio:
6 acertos - 62% 
5 acertos - 19%
4 acertos - 19%

Os ganhadores da mesma faixa dividem o prêmio entre si 

Entradas:
1ª linha - int m (nº de apostadores) e double n (valor do prêmio)
m matriz binárias de dimesão 6 x 10
1 = nº marcado; 0 = não marcado
última linha - 6 números sorteados

Saída:
m linhas onde a i-ésima linha é o valor do prêmio a ser recebido pelo i-ésimo apostador

Restrições:

nº apostas --> 5 <= m <= 1000
valor do prêmio --> 1e6 <= n <= 1e9 -> ou seja, basta ser double

Como dividir prêmio:
percorrer lista de qtde de acertos, armazenar nas variáveis sena, quina e quadra a qtde de pessoas
que acertaram os respectivos número; 
percorrer a lista de prêmio individuais e criar 3 condições:
se lista[i] == 6, somar 0,62*premio / sena

*/

#include <stdio.h>
#define MAX 1000

void le_matriz(int matriz[6 * MAX][10], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d ", &matriz[i][j]);
        }
    }
}

void le_vetor(int vetor[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d\n", &vetor[i]);
    }
}

void contabiliza_acertos(int matriz_apostas[6 * MAX][10], int sorteados[6], int acertos[MAX], int apostadores)
{
    int pos_i, pos_j; // acessar matriz de apostas
    int s, a;         //contabilizar sorteados e apostadores

    for (s = 0; s < 6; s++)
    {
        if (sorteados[s] <= 10) //posição j será igual para todos, basta calcular nesse for 1 vez
        {
            pos_j = sorteados[s] - 1;
        }
        else
        {
            pos_j = (sorteados[s] % 10) - 1;
        }

        for (a = 0; a < apostadores; a++)
        {
            pos_i = a * 6 + sorteados[s] / 10;

            if (pos_i <= 6 * apostadores)
            {
                if (matriz_apostas[pos_i][pos_j] == 1)
                {
                    acertos[a] += 1;
                }
            }
        }
    }
}

void divide_premio(double premio_total, int acertos[], double premios_individuais[], int apostadores)
{
    int sena = 0, quina = 0, quadra = 0;
    int i;

    for (i = 0; i < apostadores; i++)
    {
        if (acertos[i] == 6)
        {
            sena += 1;
        }
        else if (acertos[i] == 5)
        {
            quina += 1;
        }
        else if (acertos[i] == 4)
            ;
        quadra += 1;
    }

    for (i = 0; i < apostadores; i++)
    {
        if (acertos[i] == 6)
        {
            premios_individuais[i] = 0.62 * premio_total / sena;
        }
        else if (acertos[i] == 5)
        {
            premios_individuais[i] = 0.62 * premio_total / quina;
        }
        else if (acertos[i] == 4)
            ;
        premios_individuais[i] = 0.62 * premio_total / quadra;
    }
}

void imprime_premios(double premios_individuais[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf("%lf ", premios_individuais[i]);
    }
}

int main()
{
    int apostadores;
    double premio_total;
    int matriz_apostas[6 * MAX][10]; //como cada apostador ocupa 6 linhas, o max de linhas é 6000
    int sorteados[6];
    int acertos[MAX];
    double premios_individuais[MAX];
    scanf("%d %lf", &apostadores, &premio_total);
    le_matriz(matriz_apostas, apostadores, 10);
    le_vetor(sorteados, 6);
    contabiliza_acertos(matriz_apostas, sorteados, acertos, apostadores);
    divide_premio(premio_total, acertos, premios_individuais, apostadores);
    imprime_premios(premios_individuais, apostadores);
    return 0;
}