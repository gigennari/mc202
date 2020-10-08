void permutacoes(int vetor[], int m, int n){
    //se tofo o vetor estiver fixo, so há uma permutação
    if (n == m){
        imprimir_vetor(vetor, n);
        return ;
    }
    for (int i = m; i < n; i++){
        troca(&vetor[m], &vetor[i]);
        permutacoes(vetor, m+1, n);
        troca(&vetor[m], &vetor[i]);
    }

}