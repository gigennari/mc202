#include <stdio.h>
#include <stdlib.h>

typedef struct Token
{
    int valor;
    char expressao[25];

} Token;

typedef struct Planilha
{
    Token **planilha;
    int **visitados;
    int m, n;

} Planilha;

typedef struct Planilha *p_planilha;

p_planilha aloca_planilha(int m, int n)
{
    p_planilha p = malloc(sizeof(Planilha));

    p->m = m;
    p->n = n;

    p->planilha = malloc(m * sizeof(Token *));

    for (int i = 0; i < m; i++)
    {
        p->planilha[i] = malloc(n * sizeof(Token));
    }

    p->visitados = malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++)
    {
        p->visitados[i] = calloc(n, sizeof(int));
    }

    return p;
}

p_planilha zera_visitados(p_planilha p)
{
    for (int i = 0; i < p->m; i++)
    {
        for (int j = 0; j < p->n; j++)
        {
            p->visitados[i][j] = 0;
        }
    }
}

void le_linha(p_planilha p, char *linha, int num_linha)
{
    char auxiliar[25];
    char caractere;
    int i = 0, coluna = 0, pos = 0;

    for (caractere = linha[i]; i < strlen(linha); i++)
    {
        //se for diferente de espaço
        if (caractere != " ")
        {

            //pode estar no fim, com uma vírgula, então devemos inserir na planilha
            if (caractere == ",")
                auxiliar[pos] = "\0";
            //se começar com "=" é expressão
            if (auxiliar[0] == "=")
            {
                strcpy(p->planilha[num_linha][coluna]->expressao, auxiliar);
            }
            //caso contrário, é número
            else
            {
                int valor = atoi(auxiliar);
                p->planilha[num_linha][coluna]->valor = valor;
            }
            coluna++;
            pos = 0;
        }
        //caso contrário, copiar caractere
        else
        {
            auxiliar[pos] = caractere;
            pos++;
        }
    }
}


p_planilha le_arquivo(p_planilha p, char *nome_arquivo)
{

    FILE *arquivo = fopen(nome_arquivo, "r");

    char linha[256];
    int linha_atual = 0;

    while (fgets(linha, sizeof(linha), arquivo))
    {
        le_linha(linha, strlen(linha), linha_atual);
        linha_atual++;
    }

    fclose(arquivo);

    return p;
}

void leitura_e_calculo(p_planilha p, char *celula){

}

void atualizacao(p_planilha p, char *celula, int novo_valor){
    
}

int main()
{

    //lê nome do arquivo e dimensões da planilha
    char nome_arquivo[25];
    int m, n;
    scanf("%s %d %d", nome_arquivo, m, n);

    //aloca planilha
    p_planilha p = aloca_planilha(m, n);

    //lê arquivo csv
    p = le_arquivo(p, nome_arquivo);

    //lê e realiza operações
    int retorno;
    char operacao;
    
    scanf("%c", operacao);
    do{
        //operacao de leitura e calculo do valor atual
        if(operacao == "G"){
            char celula[10];
            scanf("%c", celula);
            leitura_e_calculo(p, celula);
        }
        //operacao de atualizar célula e calcular novo valor
        else{
            char celula[10];
            int novo_valor;
            scanf("%s %d", celula, &novo_valor);
            atualizacao(p, celula, novo_valor);
        }

        //lê próxima operação se existir 
        retorno = scanf("%c", operacao);

    }while(retorno != EOF);

    return 0;
}