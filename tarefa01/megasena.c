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



*/

#include <stdio.h>
#define MAX 1000    

void le_vetor(int vetor[], n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d\n", &vetor[i]);
    } 
}

int main(){
    int apostadores;
    double premio_total;
    int matriz_apostas[6 * MAX][10]; //como cada apostador ocupa 6 linhas, o max de linhas é 6000
    int sorteados[6];
    int acertos[MAX];
    double premios_individuais[MAX];
    scanf("%d %lf", &apostadores, &premio_total);
    le_matriz(matriz_apostas, apostadores);
    le_vetor(sorteados, 6);
    contabiliza_acertos(matriz_apostas, sorteados, acertos, apostadores);
    divide_premio(premio_total, acertos, premios_individuais, apostadores);
    imprime_premios(premios_individuais);
    return 0;

}