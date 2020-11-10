#include <stdio.h>
#include <stdlib.h>
#include "interface_fila.h"
#define NUM_ESPECIALIDADES 9

char HORARIO = {'0', '8', '0', '0'};

p_deque cria_hospital(p_deque hospital[]){
    hospital[0] = criar_deque(10);
    hospital[1] = criar_deque(2);
    hospital[2] = criar_deque(5);
    hospital[3] = criar_deque(3);
    hospital[4] = criar_deque(4);
    hospital[5] = criar_deque(7);
    hospital[6] = criar_deque(2);
    hospital[7] = criar_deque(1);
    hospital[8] = criar_deque(4);

    return hospital;

}


void atualiza_horario(){

}

void imprime_horario(){
    
}


p_deque roda_filas(){
    atualiza_horario();
    //para cada especialidade (elemento do vetor hospital)

    //se fila não estiver vazia
        //remover qtde_medicos pacientes ou até a fila esvaziar
            //se o paciente removido ainda tiver uma sala para visitar
                //inserir na fila da sala (hospital[paciente->salas->prox] = inserir_paciente) 
            //caso contrário, imprimir o horário de saída e paciente->nome    

}


int main(){
    p_deque hospital[NUM_ESPECIALIDADES];
    hospital[NUM_ESPECIALIDADES] = cria_hospital(hospital);
    le_entrada();
    roda_filas();


    return 0;
}