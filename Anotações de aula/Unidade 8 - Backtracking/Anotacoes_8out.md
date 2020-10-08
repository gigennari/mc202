# Backtracking 

### Problema: como dispor oito damas em um tabuleiro de xadrez sem posições de ameaça?

* tabuleiro 8x8
* matriz 8x8, onde 1 representa uma dama e 0, uma casa vazia?
    - essa não é uma boa representação, pois, além de haver muitos espaços sobrando, e não podemos colocar duas damas na mesma coluna, pois elas se atacariam 
* desse modo, basta um vetor, em que a posição i é a coluna e conteúdo de v[i] é a linha 
    - int v = {1, 7, 5, 2, 1, 4, 8, 4}
    - conteúdo vai de 1 a 8, pois há apenas 8 linhas 

* em tabuleiro 3X3, teremos 27 combinações possíveis
    - fixamos a primeira posição
    - listamos todos os sufixos de tamanho 2
    - repetimos para as outras possibilidades (recursão)

* como imprimir todas as disposições com prefixo dado?
    - função recebe vetor c pos fixas até m-1 e pos abertas até n-1
    -entrada: vetor de tamanho n; prefixo de tam m
    saída: uma lista de todas as combinações de valores de 1-8 tais que o prefixo é preservado

## Bracktracking
* algoritmo genérico
    - soluções consctruídas incrementalmente
    - uma solução parcial é descartada logo ela se mostre inviável 

* ao invés de enumerar todas as soluções possíveis (de força bruta), eu só enumero algumas delas (de retrocesso)

*eficiência:
    - mais rápido que força bruta, pois elimina vários candidatos de uma vez só 
    - implementação simples, mas pode ser lento com muitas soluções parciais

## Aplicações para backtracking

* conceito de solução parcial 
    - satisfação de restrições (sudoku)
    - otimização combinatória (valor mínimo)
    - programação lógica (prolog, prova automática de teoremas)



 

