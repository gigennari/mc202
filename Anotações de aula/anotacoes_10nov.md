# Árovores Rubro-Negras Esquerdistas 

Propriedades que devem sempre valer!!!

* ABB tal que:
1. Todo nó é ou vermelho ou preto
2. A **raiz** é **preta** 
3. As **folhas** são **NULL** e têm cor **preta**
4. Se um no é vermelho, seus dois filhos são pretos
    - ele é o filho esquerdo do seu pai (por isso esquerdistas)
5. Em cada npo, todo **caminho** dele para uma de suas folhas descendentes tem a **mesma quantidade de nós pretos** 
    - não contamos o nó
    -chamamos de altura-negra

* Essas propriedades garantem uma árvore balanceada, ou seja, que tem uma altura da ordem de O(lg n)
* Assim, todas as operações são de ordem O(lg n)

![Árvore Rubro-Negra Esquerdista](https://ibb.co/xfYn5SF)

## Altura da árvore 

Seja **bh** a altura-negra da árvore 

* A árvore tem pelo menos 2^bh - 1 nós não nulos 

Para provar, basta utilizar a indução matemática (recursão):
* Se bh = 0, 
    - árvore é apenas uma folha NULL
    - tem exatamente 2^bh - 1 = 0 nós não nulos 
* Se bh > 0
    - seus filhos têm altura-negra pelos menos bh - 1
    - cada subarvore tem pelo menos 2^(bh-1) - 1 nós não nulos 
    - a árvore tem pelo menos 2(2^(bh-1) - 1) nós não nulos 

A altura negra bh é pelo menos metade da altura h da árvore 
* **h < 2bh**
* nao existe nó vermelho com filho vermelho
* o número de nós não nulos é **n >= 2^bh -1 >= 2^(h/2) - 1**

# Operações para manter as propriedades

* ![Rotacionar à esquerda](https://ibb.co/0ySp3dy)

```C 
p_no rotaciona_para_esquerda(p_no raiz){
    p_no x = raiz->dir;
    raiz->dir = x->esq;
    x->esq = raiz;
    x->cor = raiz->cor;
    raiz->cor = VERMELHO;
    return x;
}
```

