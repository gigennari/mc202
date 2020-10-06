/*
Escreva uma função recurisiva que calcule, para n >=0 e k >= 0,
(n, k)2X1

Relação de Stifel:
n-1  +  n-1   = n
k-1  +    k   = k
*/

/**
 * Devolve o binomial de n escolhe k
 * */
int combinacao(int n, int k)
{
    if (n == 0 || k == 0)
    {
        return 0;
    }
    else
    {
        return combinacao(n - 1, k - 1) + combinacao(n - 1, k);
    }
}