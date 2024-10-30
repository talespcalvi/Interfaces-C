/**
 * Arquivo: pilhampuTAD.c
 * −−−−−−−−−−−−−−−−−−−−−−−−−
 * Este arquivo implemente a interface pilhampuTAD.h para implementar
 * uma pilha para os sensores mpu, utilizando TAD's.

/*** Includes ***/

#include <stdio.h>
#include <stdlib.h>
#include "pilhampuTAD.h"

/*** Defines ***/

#define MAX_PILHA 100

/**
 * Estrutura interna: pilhaMPU
 * ---------------------------
 * Representa uma pilha de sensores MPU usando um array de ponteiros para sensores.
 * O campo "topo" mantém o índice do topo da pilha, começando em -1 para indicar
 * que a pilha está inicialmente vazia.
 */
struct pilhaMPU {
    MPU* sensores[MAX_PILHA];  // Array de ponteiros para sensores MPU
    int topo;                  // Índice do topo da pilha
};

/**
 * FUNÇÃO: criar_pilha
 * Uso: pilha = criar_pilha();
 * ---------------------------
 * Aloca dinamicamente uma nova pilha de sensores MPU. Inicializa o topo da pilha
 * como -1, indicando que está vazia. Em caso de erro de alocação, exibe uma
 * mensagem e encerra o programa. Retorna um ponteiro para a pilha alocada.
 */
pilhaMPU* criar_pilha() 
{
    pilhaMPU* pilha = (pilhaMPU*) malloc(sizeof(pilhaMPU));
    if (pilha == NULL) {
        fprintf(stderr, "Erro ao alocar memória para a pilha.\n");
        exit(1);
    }
    pilha->topo = -1;
    return pilha;
}

/**
 * FUNÇÃO: cheia
 * Uso: status = cheia(pilha);
 * ---------------------------
 * Verifica se a pilha "pilha" está cheia. Retorna 1 se o topo da pilha atingiu
 * o limite máximo permitido, e 0 caso contrário.
 */
int cheia(pilhaMPU* pilha)
{
    return pilha->topo == MAX_PILHA - 1;
}

/**
 * FUNÇÃO: vazia
 * Uso: status = vazia(pilha);
 * ---------------------------
 * Verifica se a pilha "pilha" está vazia. Retorna 1 se o topo da pilha é -1,
 * indicando que não há sensores armazenados, e 0 caso contrário.
 */
int vazia(pilhaMPU* pilha)
{
    return pilha->topo == -1;
}

/**
 * FUNÇÃO: empilhar
 * Uso: sucesso = empilhar(pilha, sensor);
 * ---------------------------------------
 * Adiciona um sensor MPU no topo da pilha "pilha". Caso a pilha esteja cheia,
 * exibe uma mensagem de erro e retorna 0. Caso contrário, insere o sensor na
 * posição seguinte do topo e retorna 1, indicando sucesso.
 */
int empilhar(pilhaMPU* pilha, MPU* sensor)
{
    if (cheia(pilha)) {
        printf("ERRO: PILHA CHEIA\n");
        return 0;
    }
    pilha->sensores[++(pilha->topo)] = sensor;
    return 1;
}

/**
 * FUNÇÃO: desempilhar
 * Uso: sensor = desempilhar(pilha);
 * ---------------------------------
 * Remove e retorna o sensor MPU do topo da pilha "pilha". Caso a pilha esteja
 * vazia, exibe uma mensagem de erro e retorna NULL. Caso contrário, retorna
 * o sensor do topo e decrementa o índice do topo.
 */
MPU* desempilhar(pilhaMPU* pilha)
{
    if (vazia(pilha)) {
        printf("ERRO: PILHA VAZIA\n");
        return NULL;
    }
    return pilha->sensores[(pilha->topo)--];
}

/**
 * PROCEDIMENTO: apagar_pilha
 * Uso: apagar_pilha(pilha);
 * -------------------------
 * Libera a memória de todos os sensores armazenados na pilha "pilha" e, em
 * seguida, libera a memória alocada para a própria pilha. Após a execução
 * desse procedimento, o ponteiro para a pilha não deve ser mais utilizado.
 */
void apagar_pilha(pilhaMPU* pilha)
{
    while (!vazia(pilha)) {
        MPU* sensor = desempilhar(pilha);  // Remove cada sensor do topo
        apagar_mpu(sensor);                // Libera a memória de cada sensor
    }
    free(pilha);  // Libera a estrutura da pilha
}
