#include <stdio.h>


double potencia(double a, double b){
    if (b == 0)
        return 1;
    else
        return a * potencia(a, b-1);
    
}

int main(){
    double a, b, resultado;
    scanf("%lf %lf", &a, &b);
    resultado = potencia(a, b);
    printf("%lf", resultado);
}