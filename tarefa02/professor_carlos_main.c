/*
Cliente
*/

#include <stdio.h>
#include <professor_carlos.h>
#define N 50 //numero máx de turmas
#define M 40 //numero max de alunos por turma 
#define K 50 //numero max de operacoes

Aluno ler_aluno(){
    Aluno A;
    int dia, mes, ano;
    ("%c %c %d %d %d", &A.nome, &A.sobrenome, &dia, &mes, &ano);
    A.nascimento.dia = dia;
    A.nascimento.mes = mes;
    A.nascimento.ano = ano;
    return A;
}

Turma criar_turmas(Turma turmas[], int num_turmas){
    for(int i = 0; i < num_turmas; i++)
    {
        int alunos;
        scanf("%d ", &alunos);
        for(int j = 0; j < alunos; j++){
            Aluno A;
            A = ler_aluno();
            add_aluno(turmas[], A, i);
        }
    }
}

void realizar_operacao(int num_operacoes){


}


int main(){
    int num_turmas, num_operacoes;
    Turma turmas[N];
    scanf("%d %d", &num_turmas, num_operacoes);
    criar_turmas(turmas, num_turmas);
    


}