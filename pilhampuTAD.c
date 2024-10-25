#include <stdio.h>
#include <stdlib.h>
#include "pilhampuTAD.h"

pilhaMPU* criar_pilha() 
{
    pilhaMPU* pilha = (pilhaMPU*) malloc(sizeof(pilhaMPU));
    pilha->topo -1;
    return pilha;
}

int cheia(pilhaMPU* pilha)
{
    return pilha->topo == MAX_PILHA - 1;
}

int vazia(pilhaMPU* pilha)
{
    return pilha->topo == -1;
}

int empilhar(pilhaMPU* pilha, MPU* sensor)
{
    if (cheia(pilha))
    {
        printf("ERRO: PILHA CHEIA\n");
        return 0;
    }
    pilha->sensores[++(pilha->topo)] = sensor;
    return 1;
}

MPU* desempilhar(pilhaMPU* pilha)
{
    if (vazia(pilha))
    {
        printf("ERRO: PILHA VAZIA");
        return NULL;
    }
    return pilha->sensores[(pilha->topo)--];
}

void apagar_pilha(pilhaMPU* pilha)
{
    while (!vazia(pilha))
    {
        MPU* sensor = desempilhar(pilha);
        apagar_mpu(sensor);
    }
    free(pilha);
}