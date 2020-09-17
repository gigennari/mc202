"""
Encontrar o máximo entre a e b 

Lembrar: toda instrução precisa de um ;
"""

#include <stdio.h>

int maximo(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int potencia(int a, int b) {
    int i;
    int prod 1 ;
    for(i=0; i<b; i++){
        prod = a * prod;
    }
    return prod;
}

int main() {
    int a, b, maior, pot;
    printf("Entre com a e b\n");  
    scanf(" %d %d", &a, &b); 
    maior = maximo(a, b);
    pot = potencia(a,b);
    printf("Maior: %d\n", maior);
    printf("a^b: %d\n", maior);
    return 0;
}
