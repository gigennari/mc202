#include <stdio.h>

int potencia_recursiva(int base, int expoente){
    if (expoente == 0)
        return 1;
    else
        return base * potencia(base, expoente-1);
    

}

int main(){
    int base, expoente, potencia;
    potencia = potencia_recursiva(base, expoente);
    printf("%d", potencia);
}