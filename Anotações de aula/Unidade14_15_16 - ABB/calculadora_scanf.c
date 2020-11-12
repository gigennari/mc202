#include <stdio.h>

int main(){
    char operador;
    int operando1, operando2;
    int resultado;

    while (scanf(" %c%d%d", &operador, &operando1, &operando2) != EOF){
        switch (operador)
    {
    case '+':
        resultado  = operando1 + operando2;
        break;
    case '-':
        resultado = operando1 - operando2;
    default:
        break;
    }
    printf("%d\n", resultado);
    }
   
}