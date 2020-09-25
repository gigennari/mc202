/*
Contém a Implementação 


Vamos criar um programa que lida com números complexos da forma
a + bi
i = sqrt(-1)

Queremos somar dois números complexos lidos e calcular o valor absoluto
sqrt(a² + b²)
*/


typedef struct {
    double real;
    double imag;
} complexo;

complexo complexo_novo(double real, double imag) {
    complexo c;
    c.real = real;
    c.imag = imag;
    return c;
}


complexo complexo_soma(complexo a, complexo b){
    return complexo_novo(a.real + b.real, a.imag + b.imag);
}

complexo complexo_le(){
    complexo a;
    scanf("%lf %lf", &a.real, &a.imag);
    return a;
}


