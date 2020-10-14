a) A diferença entre passagem por referência é que, ao passarmos apenas um valor, não podemos alterá-lo e retorná-lo no caso de matrizes e vetores. Passando apenas o valor, ele é usado e alterado no escopo da função chamada apenas. No entanto, quando passamos um valor por referências, podemos alterá-lo na memória. 

b) É vantajoso passar registros/structs por referências quando a finalidade da função é alterar alguma informação da sruct. 

c) É melhor usar passagem por valores quando apenas uma cópia da informação basta para realizar as tarefas da função. Ou seja, quando não é necessário alterar valores da srtuct (o que também vale para matizes e vetores), mas precisamos apenas de uma cópia dela ou então um número, aí é melhor usar passagem por valores. 