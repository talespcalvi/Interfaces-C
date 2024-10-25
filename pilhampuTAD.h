#ifndef PILHA_MPU_TAD_H
#define PILHA_MPU_TAD_H

#include  "mpuTAD.h"

#define MAX_PILHA 100

typedef struct 
{
    MPU* sensores[MAX_PILHA];
    int topo;
} pilhaMPU;

pilhaMPU* criar_pilha();
int empilhar(pilhaMPU* pilha, MPU* sensor);
MPU* desempilhar(pilhaMPU* pilha);
int cheia(pilhaMPU* pilha);
int vazia(pilhaMPU* pilha);
void apagar_pilha(pilhaMPU* pilha);

#endif