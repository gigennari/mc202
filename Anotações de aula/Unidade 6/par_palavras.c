#include <stdio.h>
#include <stdlib.h> // contém malloc, 
#include <string.h>

struct par_palavras{
    char *palavra;
    char *inverso;
};

void inverte_string(char *palavra, char *inverso)
{
    int k = 0;
    for (int i = strlen(palavra) - 1; i >= 0; i--, k++)
    {
        inverso[k] = palavra[i];
    }
    inverso[k] = '0';
}

int main(){
    struct par_palavras *p_par;

    int tamanho_max;

    scanf("%d", &tamanho_max);

    p_par = malloc(sizeof(struct par_palavras));
    p_par->palavra = malloc(tamanho_max * sizeof(char));
    p_par->inverso = malloc(tamanho_max * sizeof(char));

    scanf("%s", p_par->palavra);
    inverte_string(p_par->palavra, p_par->inverso);
    printf("%s\n", p_par->inverso);

    free(p_par->inverso);
    free(p_par->palavra);
    return 0;

}