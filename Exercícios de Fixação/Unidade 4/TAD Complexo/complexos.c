/*
Contém a Implementação 


Vamos criar um programa que lida com números complexos da forma
a + bi
i = sqrt(-1)

Queremos somar dois números complexos lidos e calcular o valor absoluto
sqrt(a² + b²)
*/

#include <stdio.h>
#include <math.h>

typedef struct
{
    double real;
    double imag;
} complexo;

//inicializa um complexo
complexo complexo_novo(double real, double imag)
{
    complexo c;
    c.real = real;
    c.imag = imag;
    return c;
}

//lê um complexo do teclado
complexo complexo_le()
{
    complexo a;
    scanf("%lf %lf", &a.real, &a.imag);
    return a;
}

//soma
complexo complexo_soma(complexo a, complexo b)
{
    return complexo_novo(a.real + b.real, a.imag + b.imag);
}

//subtrai
complexo complexo_subtrai(complexo a, complexo b)
{
    return complexo_novo(a.real - b.real, a.imag - b.imag);
}

//eleva a potência inteira
complexo complexo_potencia(complexo a, int potencia)
{
}

//obtém conjugado
complexo complexo_conjugado(complexo a)
{
    return complexo_novo(a.real, -a.real);
}

//multiplica a por b
complexo complexo_multiplica(complexo a, complexo b)
{
    double real, imag;
    real = (a.real * b.real) - (a.imag * b.imag);
    imag = (a.real * b.imag) - (a.imag * b.real);
    return complexo_novo(real, imag);
}

//divide a/b
complexo complexo_divide(complexo a, complexo b)
{
    complexo numerador, denominador, quociente;
    numerador = complexo_multiplica(a, complexo_conjugado(b));
    denominador = complexo_multiplica(b, complexo_conjugado(b));
    quociente.real = numerador.real / denominador.real;
    quociente.imag = numerador.imag / denominador.real;
    return quociente;
}

//valor absoluto
double complexo_absoluto(complexo a)
{
    return(sqrt((a.real * a.real) + (a.imag * a.imag)));   
}
