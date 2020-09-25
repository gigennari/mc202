/*
Contém a Interface
*/


typedef struct {
    double real;
    double imag;
} complexo;

complexo complexo_novo(double real, double imag);

complexo complexo_soma(complexo a, complexo b);

double complexo_aboluto(complexo a);

complexo complexo_le();

int complexos_iguais(complexo a, complexo b);

complexo complexo_conjugado(complexo a);


