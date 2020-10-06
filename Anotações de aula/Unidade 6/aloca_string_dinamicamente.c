
#include <stdio.h>
#include <stdlib.h> // contém malloc, 
#include <string.h>

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
    char *palavra;
    char *inverso;

    int tamanho_max;

    scanf("%d", &tamanho_max);
    palavra = malloc(tamanho_max * sizeof(char));
    inverso = malloc(tamanho_max * sizeof(char));

    scanf("%s", palavra);
    inverte_string(palavra, inverso);
    printf("%s\n", inverso);

    free(inverso);
    free(palavra);
    return 0;

}