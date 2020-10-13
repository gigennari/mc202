a) Considerando o programa original da questão 1, é possível determinar que:
* a vale 1, pois como a função f não recebe um ponteiro para o inteiro, mas apenas o inteiro, ele permanece inalterado;
* c permanece inalterado ao longo do código, assim, vale 3;
* o valor d[1][1] valeria 100 após ser alterado pela função h; no entanto, como o free foi feito antes da impressão, esse valor não existe na memória. 

b) Existe memory leak, pois apenas d recebeu free, mas d era um ponteiro para ponteiro. Assim, os elementos de d (que era apenas 1) deveria receber free antes do d.

c) Código alterado está no arquivo "codigo1_alterado.c".