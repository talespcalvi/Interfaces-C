/**
* Arquivo: pilhampuTAD.h
* −−−−−−−−−−−−−−−−−−−−−−−−−
* Este arquivo implementa a interface pilhampuTAD.h utilizando como 
* tipo de dado o dado 'pilhaMPU'.
* Implenta uma pilha para os sensores da interface mpuTAD.h.
*/

/*** Inicia Boilerplate da Interface ***/
#ifndef PILHA_MPU_TAD_H
#define PILHA_MPU_TAD_H

/*** Includes ***/

#include "mpuTAD.h"

/*** Tipos de Dados ***/

/**
 * TIPO: pilhaMPU
 * ---------------
 * Define um ponteiro opaco para uma pilha de sensores MPU.
 */
typedef struct pilhaMPU pilhaMPU;

/*** Declarações de Subprogramas ***/

/**
 * FUNÇÃO: criar_pilha
 * Uso: pilha = criar_pilha();
 * ---------------------------
 * Esta função aloca memória para uma nova pilha de sensores MPU e inicializa
 * a pilha como vazia, definindo o índice do topo como -1. Retorna um ponteiro
 * para a nova pilha.
 */
pilhaMPU* criar_pilha();

/**
 * FUNÇÃO: empilhar
 * Uso: sucesso = empilhar(pilha, sensor);
 * ---------------------------------------
 * Adiciona um sensor MPU no topo da pilha "pilha". Retorna 1 se o sensor foi
 * empilhado com sucesso ou 0 se a pilha já está cheia.
 */
int empilhar(pilhaMPU* pilha, MPU* sensor);

/**
 * FUNÇÃO: desempilhar
 * Uso: sensor = desempilhar(pilha);
 * ---------------------------------
 * Remove o sensor MPU do topo da pilha "pilha" e o retorna. Retorna NULL se a
 * pilha estiver vazia.
 */
MPU* desempilhar(pilhaMPU* pilha);

/**
 * FUNÇÃO: cheia
 * Uso: status = cheia(pilha);
 * ---------------------------
 * Verifica se a pilha "pilha" está cheia. Retorna 1 se a pilha está cheia
 * e 0 caso contrário.
 */
int cheia(pilhaMPU* pilha);

/**
 * FUNÇÃO: vazia
 * Uso: status = vazia(pilha);
 * ---------------------------
 * Verifica se a pilha "pilha" está vazia. Retorna 1 se a pilha está vazia
 * e 0 caso contrário.
 */
int vazia(pilhaMPU* pilha);

/**
 * PROCEDIMENTO: apagar_pilha
 * Uso: apagar_pilha(pilha);
 * -------------------------
 * Libera a memória alocada para a pilha "pilha" e todos os sensores nela
 * armazenados. Após a chamada, o ponteiro para a pilha não deve ser mais usado.
 */
void apagar_pilha(pilhaMPU* pilha);

/*** Finaliza Boilerplate da Interface ***/

#endif
