/*
Implementação 
*/

#include <stdio.h>
#include <stdio.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct aluno {
    Data nascimento;
    char nome[15];
    char sobrenome[15];
} Aluno;

typedef struct turma {
    Aluno alunos[50];
    int qtd;
} Turma;


Aluno procura_novo_na_turma(Turma t[], int qtd_turmas, int j){
    for(int i = 0; )
}

int add_aluno(Turma t[], Aluno A, int j);{
    t[j].alunos[t[j].qtd] = A;
    t[j].qtd ++;
    return t[j].qtd;
}

int remove_aluno(Turma t[], int j);{
    t[j].qtd --;
    return t[j].qtd;
}

