/*
Contém a Interface
*/


typedef struct {
    double real;
    double imag;
} complexo;

complexo complexo_novo(double real, double imag);

complexo complexo_le();

complexo complexo_soma(complexo a, complexo b);

complexo complexo_subtrai(complexo a, complexo b);

complexo complexo_potencia(complexo a, int potencia);

complexo complexo_conjugado(complexo a);

complexo complexo_multiplica(complexo a, complexo b);

complexo complexo_divide(complexo a, complexo b);

double complexo_absoluto(complexo a);




