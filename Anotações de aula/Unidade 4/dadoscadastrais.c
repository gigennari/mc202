/*
estruturas aninhadas --> data dentro de aluno 

aluno.ra --> acessa ra

*/

struct data {
    int dia;
    int mes;
    int ano;
};

struct aluno{
    int ra; 
    int telefone;
    char nome[30];
    char endereco[100];
    struct data nascimento;
};

