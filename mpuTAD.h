/**
* Arquivo: mpuTAD.h
* ------------------
* Este arquivo define uma interface para a abstração de um sensor mpu, 
* implementado como um TAD.
*/

/*** Inicia Boilerplate da Interface ***/
#ifndef MPU_TAD_H
#define MPU_TAD_H

/*** Tipos de Dados ***/

/**
 * TIPO: MPU
 * −−−−−−−−−−−−−−−
 * Este tipo abstrato de dado é utilizado para representar um sensor mpu.
 */
typedef struct MPU MPU;  

/*** Declarações de Subprogramas ***/

/**
 * FUNÇÃO: criar_mpu
 * Uso: mpu = criar_mpu( );
 * −−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
 * Esta função aloca memória de modo dinâmico, em quantidade suficiente para a
 * representação interna do mpuTAD, e inicializa o sensor para representar
 * um sensor vazio.
 */
MPU* criar_mpu(int ac_sens, int rot_sens);

/**
 * PROCEDIMENTO: setar_aceleracao
 * Uso: setar_aceleracao(sensor, ax, ay, az);
 * -----------------------------------------
 * Define os valores brutos de aceleração para os eixos X, Y e Z no sensor 'sensor'.
 * Esses valores serão posteriormente usados para calcular os valores finais de aceleração.
 */
void setar_aceleracao(MPU* sensor, int ax, int ay, int az);

/**
 * PROCEDIMENTO: setar_rotacao
 * Uso: setar_rotacao(sensor, rx, ry, rz);
 * ---------------------------------------
 * Define os valores brutos de rotação para os eixos X, Y e Z no sensor 'sensor'.
 * Esses valores são usados para calcular os valores finais de rotação.
 */
void setar_rotacao(MPU* sensor, int rx, int ry, int rz);

/**
 * PROCEDIMENTO: pegar_aceleracao
 * Uso: pegar_aceleracao(sensor, &acX, &acY, &acZ);
 * -----------------------------------------------
 * Recupera os valores finais de aceleração calculados para os eixos X, Y e Z e armazena
 * nas variáveis fornecidas por referência (&acX, &acY, &acZ).
 */
void pegar_aceleracao(MPU* sensor, float* acX, float* acY, float* acZ);

/**
 * PROCEDIMENTO: pegar_rotacao
 * Uso: pegar_rotacao(sensor, &rotX, &rotY, &rotZ);
 * ------------------------------------------------
 * Recupera os valores finais de rotação calculados para os eixos X, Y e Z e armazena
 * nas variáveis fornecidas por referência (&rotX, &rotY, &rotZ).
 */
void pegar_rotacao(MPU* sensor, float* rotX, float* rotY, float* rotZ);

/**
 * PROCEDIMENTO: apagar_mpu
 * Uso: apagar_mpu(sensor);
 * ------------------------
 * Libera a memória alocada para o sensor 'sensor'. Após essa chamada,
 * o ponteiro 'sensor' não deve ser mais usado.
 */
void apagar_mpu(MPU* sensor);

/*** Finaliza Boilerplate da Interface ***/
#endif
