/*
Entrada: k e nome
6
beto

Saída: nome encriptado
HKZU

ASCII --> de 65 a 90 (26 letras, de 0 a 25?)

BETU --> o U + 6 seria 91, quando chega no Z, volta para o A
COnveção para parar o texto: # 

*/

#include <stdio.h>

int main() {
    int k:
    char original, encriptado, pos_original, pos_encriptado;
    scanf("%d", &k);
    scanf("%c", &original);
    while (original != '#') {
        pos_original = original - 'A';  //incia no A como 0, não como 65; usa caractere como nº da tabela ASC
        pos_encriptado = (pos_original + k) % 26;   //decobrir o valor dele encirptado
        encriptado = 'A' + pos_encriptado;
        printf("%c", encriptado);
        scanf("%c", &original);
    }
    printf("\n");
    return 0;
}