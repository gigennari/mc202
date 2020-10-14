#include <stdio.h>

int potencia_iterativa(int base, int expoente){
    int potencia = 1;
    for (int i = 0; i < expoente; i++){
        potencia *= base;
    }
    return potencia;

}

int main(){
    int base, expoente, potencia;
    potencia = potencia_iterativa(base, expoente);
    printf("%d", potencia);
}