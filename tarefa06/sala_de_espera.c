#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface_fila.h"

#define NUM_ESPECIALIDADES 9

int HORARIO[] = {0, 8, 0, 0};

void cria_hospital(p_deque *hospital)
{
    hospital[0] = criar_deque(10);
    hospital[1] = criar_deque(2);
    hospital[2] = criar_deque(5);
    hospital[3] = criar_deque(3);
    hospital[4] = criar_deque(4);
    hospital[5] = criar_deque(7);
    hospital[6] = criar_deque(2);
    hospital[7] = criar_deque(1);
    hospital[8] = criar_deque(4);
}

void atualiza_horario()
{
    //caso seja minuto 50, hora vira (2 casos)
    if (HORARIO[2] == 5)
    {
        HORARIO[2] = 0;
        if (HORARIO[1] < 9)
        {
            HORARIO[1] += 1;
        }
        else
        {
            HORARIO[0] += 1;
            HORARIO[1] = 0;
        }
    }
    else
    {
        HORARIO[2] += 1;
    }
}

void imprime_horario()
{
    for (int i = 0; i < 4; i++)
    {
        if (i == 2)
        {
            printf("%c", ':'); //imprimir dois pontos quando chegar nos minutos
        }
        printf("%d", HORARIO[i]);
    }
}

p_deque le_entrada(p_deque pacientes)
{
    scanf("%*c");
    int retorno = 1, posicao = 1;
    do
    {
        char nome[50];
        char aspas;
        char status[13];
        p_lista salas;
        salas = criar_lista();
        p_paciente paciente;
        Preferencia x;

        scanf("%[^\"]%*c", nome);
        scanf("%s", status);

        
        if (status[0] == 'n')
        {
            x = normal;
        }
        else
        {
            x = preferencial;
        }

        int num;
        int ret = 1;

        do
        {
            ret = scanf("%d", &num);
            if (ret == 1)
            {
                salas = add_direita(salas, num);
            }
        } while (ret == 1);

        retorno = scanf("%c", &aspas);

        paciente = criar_paciente(nome, x, salas, posicao);
        pacientes = inserir_paciente(pacientes, paciente);
        posicao += 1;
    } while (retorno != -1);

    return pacientes;
}

//devolve 1
int entrou_antes(const void *p1, const void *p2)
{
    p_paciente *P1, *P2;
    P1 = (p_paciente *)p1;
    P2 = (p_paciente *)p2;
    return (*P1)->posicao - (*P2)->posicao;

}

void add_pacientes_fila(p_deque hospital[], p_paciente *restantes, int num_pacientes)
{
    int ja_add = 0;

    for (int sala = 0; sala < NUM_ESPECIALIDADES; sala++)
    {
        p_paciente *sala_atual = malloc(num_pacientes * sizeof(p_paciente));
        if (ja_add < num_pacientes) //se todos j?? foram add, podemos parar de verificar as pr??ximas salas
        {
            //num_pacientes ?? o maximo que precisa, caso todos vao p mesma sala
            int qtde = 0; //guarda qtde de pacientes que v??o para o deque da sala
            //percorre pacientes de um restantes e verifica proxima sala
            for (int p = 0; p < num_pacientes; p++)
            {
                //se a proxima sala for a que estamos visitando (1?? for), add em um restantes sala_atual
                if (restantes[p] != NULL && restantes[p]->salas->ini->dado - 1 == sala)
                {
                    sala_atual[qtde] = restantes[p];

                    qtde += 1;
                
                }
            }

            ja_add += qtde;

            if (qtde > 0)
            {
                
                //ordena pessoas que v??o p fila da mesma especilidade por ordem de quem entrou primeiro
                
                qsort(sala_atual, qtde, sizeof(p_paciente), entrou_antes);
                
                //add pessoas na fila
                for (int a = 0; a < qtde; a++)
                {
                    hospital[sala] = inserir_paciente(hospital[sala], sala_atual[a]);
                }
            }

        }
        free(sala_atual);
    }
}

//atualiza deques do vetor hospital
int roda_filas(p_deque hospital[], p_paciente **restantes, int num_pacientes)
{

    atualiza_horario();
    p_deque deque_restantes;
    deque_restantes = criar_deque(0);
    //para cada especialidade (elemento do vetor hospital)
    for (int sala = 0; sala < NUM_ESPECIALIDADES; sala++)
    {
        //se fila n??o estiver vazia
        if (fila_nao_vazia(hospital[sala]) == 1)
        {
            int qtde_pacientes = hospital[sala]->qtde_pacientes;

            //remover qtde_medicos pacientes ou at?? a fila esvaziar

            for (int x = 0; x < hospital[sala]->qtde_medicos && x < qtde_pacientes; x++)
            {
                p_paciente removido = remover_paciente(hospital[sala]);
                eliminar_esquerda(removido->salas);

               
                //se o paciente removido ainda tiver uma sala para visitar
                if (removido->salas->tamanho > 0)
                {
                    //inserir em um vetor tempor??rio
                    deque_restantes = inserir_paciente(deque_restantes, removido);
                }

                //caso contr??rio, imprimir o hor??rio de sa??da e paciente->nome
                else
                {
                    liberar_memoria_lista(removido->salas);
                    imprime_horario();
                    //imprime nome
                    printf(" %s", removido->nome);
                    printf("\n");
                    free(removido);
                }
            }
        }
    }
    int num = deque_restantes->qtde_pacientes;
    free(*restantes);
    *restantes = malloc(sizeof(p_paciente) * num);
    colocar_pacientes_vetor(*restantes, deque_restantes, num);

    free(deque_restantes);

    return num;
}

int restam_pacientes(p_deque *hospital)
{
    for (int i = 0; i < NUM_ESPECIALIDADES; i++)
    {
        if (fila_nao_vazia(hospital[i]) != 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    p_deque hospital[NUM_ESPECIALIDADES];
    cria_hospital(hospital);
    p_deque pacientes;
    pacientes = criar_deque(0);
    pacientes = le_entrada(pacientes);
    int num_pacientes = 0;
    p_paciente atual = pacientes->ini;
    while(atual != NULL){
        num_pacientes += 1;
        atual = atual->prox;
    }

    p_paciente *vetor_todos_pacientes = malloc(sizeof(p_paciente) * num_pacientes);
    colocar_pacientes_vetor(vetor_todos_pacientes, pacientes, num_pacientes);

    p_paciente *restantes = malloc(sizeof(p_paciente) * num_pacientes);
    int iter = 1;

    while (num_pacientes > 0 || restam_pacientes(hospital))
    {
        if (iter == 1)
        {
            add_pacientes_fila(hospital, vetor_todos_pacientes, num_pacientes);
            num_pacientes = roda_filas(hospital, &restantes, num_pacientes);
        }
        else
        {
            add_pacientes_fila(hospital, restantes, num_pacientes);
            num_pacientes = roda_filas(hospital, &restantes, num_pacientes);
        }

        iter += 1;
    }

    for(int i = 0; i < NUM_ESPECIALIDADES; i++){
        liberar_memoria_deque(hospital[i]);
    }
    free(pacientes);
    free(vetor_todos_pacientes);
    free(restantes);

    return 0;
}