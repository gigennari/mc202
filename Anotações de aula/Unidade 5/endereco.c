#include <stdio.h>

int main(){
    int *endereco;
    int variavel = 90;
    endereco = &variavel; // é 127 por exemplo
    printf("Variável: %d\n", variavel); //imprime 90
    printf("Variável: %d\n", *endereco); //qual a variável cujo endereço é 127? --> imprime 90
    printf("Endereço: %d\n", endereco); //imprime 127
    printf("Endereço: %d\n", &variavel); //retorna endreço de emória de variavel --> 127

}
