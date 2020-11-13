#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Usaremos No para armazenar salas que o paciente visita
 * */
typedef struct No
{
    int dado;
    struct No *prox;
    struct No *ant;
} No;

typedef struct No *p_no;

typedef struct Lista
{
    int tamanho;
    p_no ini, fim;

} Lista;

typedef struct Lista *p_lista;

/**
 * Usaremos um deque de pacientes
 * */
typedef enum 
{
    normal,
    prioridade
} Preferencia;

typedef struct Paciente
{
    char nome[50];
    Preferencia status;
    p_lista salas;
    int posicao;
    struct Paciente *prox, *ant;
} Paciente;

typedef Paciente *p_paciente;

typedef struct Deque
{
    p_paciente ini, fim;   // prox posição livre
    int qtde_medicos, qtde_pacientes;
} Deque;

typedef Deque *p_deque;


/**
 * Funções para lista de salas com cabeça e cauda
 * */
p_lista criar_lista()
{
    return NULL;
}

p_lista add_direita(p_lista lista, int c)
{

    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = c;
    if (lista == NULL)
    {
        lista = malloc(sizeof(Lista));
        lista->ini = novo;
        lista->fim = novo;
        lista->tamanho = 1;
        novo->prox = NULL;
        novo->ant = NULL;
    }
    else
    {
        novo->prox = NULL;
        novo->ant = lista->fim;
        lista->fim->prox = novo;
        lista->fim = novo;
        lista->tamanho += 1;
    }
    return lista;
}

p_lista eliminar_esquerda(p_lista lista)
{
    if (lista != NULL)
    {
        if (lista->tamanho == 1)
        {
            free(lista);
            return NULL;
        }
        else
        {
            p_no aux = lista->ini;
            lista->ini = lista->ini->prox;
            free(aux);
            lista->tamanho -= 1;
            return lista;
        }
    }
    return NULL;
}

void liberar_memoria_lista(p_lista lista)
{
    if (lista != NULL)
    {
        p_no no;
        no = lista->ini;
        while (no != NULL)
        {
            p_no aux = no;
            no = no->prox;
            free(aux);
        }
        free(lista);
    }
}



/**
 * Funções de paciente ("nó")
 * */

p_paciente criar_paciente(char *nome, Preferencia x, p_lista salas, int posicao){
    p_paciente paciente;
    paciente = malloc(sizeof(Paciente));
    strcpy(paciente->nome, nome);
    paciente->status = x;
    paciente->salas = salas;
    paciente->posicao = posicao;
    paciente->prox = paciente->ant = NULL; //definimos prox e ant na hora de inserir na fila
    return paciente;
}


/**
 * Funções de deque 
 * */
p_deque criar_deque(int qtde_medicos){
    p_deque deque;
    deque = malloc(sizeof(Deque));
    deque->qtde_medicos = qtde_medicos;
    deque->qtde_pacientes = 0;
    deque->ini = deque->fim = NULL;
    return deque;
}

void liberar_memoria_deque(p_deque fila){
    while(fila->ini != fila->fim->prox){
        p_paciente aux = fila->ini;
        fila->ini = fila->ini->prox;
        free(aux);
    }
    free(fila);
    
}

int fila_vazia(p_deque especialidade){
    if (especialidade->qtde_pacientes == 0 || especialidade->ini == NULL){
        return 1;
    }
    return 0; //se fila não for vazia, remover pacientes existentes de acordo com qtde de médicos
}
    
/**
//para pacientes prioridade
p_deque insere_incio(p_deque especialidade, p_paciente paciente){

}

//para pacientes normal 
p_deque insere_fim(p_deque especialidade, p_paciente paciente){

}



//sempre remove do início
p_deque remover_paciente(p_deque especialidade){

}
*/



p_deque inserir_paciente(p_deque especialidade, p_paciente paciente){
    return NULL;
}
