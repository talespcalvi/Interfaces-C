/** 
* Arquivo: mpuTAD.c
* -----------------
* Este arquivo implementa a interface mpuTAD.h utilizando o
* tipo de dado 'mpu' anteriormente criado. 
*/

#include <stdlib.h>
#include "mpuTAD.h"

/** 
* Escalas para as sensibilidades
* ------------------------------
* Estas tabelas de escala são utilizadas para calcular os valores finais de
* aceleração e rotação com base nas sensibilidades definidas para o sensor.
* ac_escala define os valores de sensibilidade para aceleração em g,
* enquanto rot_escala define os valores de sensibilidade para rotação em °/s.
* Seguem a seguinte classificação:
* --------------------------------------------------
* | Sensibilidade de aceleração | Fator de escala  |
* |             ±2 g            |     16 384       |
* |             ±4 g            |      8192        |
* |             ±8 g            |      4096        |
* |             ±16 g           |      2048        |
* --------------------------------------------------
* -------------------------------------------------
* |  Sensibilidade de rotação   | Fator de escala |
* |           ±250 °/s          |      131,0      |
* |           ±500 °/s          |       65,5      |
* |           ±1000 °/s         |       32,8      |
* |           ±2000 °/s         |       16,4      |
* -------------------------------------------------
*/
int ac_escala[] = {16384, 8192, 4096, 2048};
float rot_escala[] = {131, 65.5, 32.8, 16.4};

/**
 * Tipo: struct MPU
 * ----------------
 * Estrutura que representa um sensor MPU, incluindo os valores brutos e finais
 * de aceleração e rotação, além das configurações de sensibilidade.
 */
struct MPU {
    int ax, ay, az;          // Valores brutos da aceleração
    float acX, acY, acZ;     // Valores finais da aceleração
    int rx, ry, rz;          // Valores brutos da rotação
    float rotX, rotY, rotZ;  // Valores finais da rotação
    int ac_sens, rot_sens;   // Sensibilidade da aceleração e rotação
};

/**
 * FUNÇÃO: criar_mpu
 * Uso: mpu = criar_mpu(ac_sens, rot_sens);
 * ----------------------------------------
 * Esta função aloca dinamicamente memória para um novo sensor MPU, inicializando
 * as configurações de sensibilidade para aceleração e rotação. Retorna um ponteiro
 * para o sensor alocado ou NULL em caso de erro.
 */
MPU* criar_mpu(int ac_sens, int rot_sens)
{
    MPU* sensor = (MPU*) malloc(sizeof(MPU));
    sensor->ac_sens = ac_sens;
    sensor->rot_sens = rot_sens;
  
    return sensor;
}

/**
 * PROCEDIMENTO: setar_aceleracao
 * Uso: setar_aceleracao(sensor, ax, ay, az);
 * -----------------------------------------
 * Define os valores brutos de aceleração para os eixos X, Y e Z no sensor "sensor".
 * Calcula os valores finais de aceleração aplicando a escala de sensibilidade
 * definida para o sensor.
 */
void setar_aceleracao(MPU* sensor, int ax, int ay, int az)
{
    sensor->ax = ax;
    sensor->ay = ay;
    sensor->az = az;

    sensor->acX = (float) ax / ac_escala[sensor->ac_sens];
    sensor->acY = (float) ay / ac_escala[sensor->ac_sens];
    sensor->acZ = (float) az / ac_escala[sensor->ac_sens];
}

/**
 * PROCEDIMENTO: setar_rotacao
 * Uso: setar_rotacao(sensor, rx, ry, rz);
 * ---------------------------------------
 * Define os valores brutos de rotação para os eixos X, Y e Z no sensor "sensor".
 * Calcula os valores finais de rotação aplicando a escala de sensibilidade
 * definida para o sensor.
 */
void setar_rotacao(MPU* sensor, int rx, int ry, int rz)
{
    sensor->rx = rx;
    sensor->ry = ry;
    sensor->rz = rz;

    sensor->rotX = (float) rx / rot_escala[sensor->rot_sens];
    sensor->rotY = (float) ry / rot_escala[sensor->rot_sens];
    sensor->rotZ = (float) rz / rot_escala[sensor->rot_sens];
}

/**
 * PROCEDIMENTO: pegar_aceleracao
 * Uso: pegar_aceleracao(sensor, &acX, &acY, &acZ);
 * -----------------------------------------------
 * Recupera os valores finais de aceleração calculados para os eixos X, Y e Z e
 * armazena nas variáveis fornecidas por referência (&acX, &acY, &acZ).
 */
void pegar_aceleracao(MPU* sensor, float* acX, float* acY, float* acZ)
{
    *acX = sensor->acX;
    *acY = sensor->acY;
    *acZ = sensor->acZ;
}

/**
 * PROCEDIMENTO: pegar_rotacao
 * Uso: pegar_rotacao(sensor, &rotX, &rotY, &rotZ);
 * ------------------------------------------------
 * Recupera os valores finais de rotação calculados para os eixos X, Y e Z e
 * armazena nas variáveis fornecidas por referência (&rotX, &rotY, &rotZ).
 */
void pegar_rotacao(MPU* sensor, float* rotX, float* rotY, float* rotZ)
{
    *rotX = sensor->rotX;
    *rotY = sensor->rotY;
    *rotZ = sensor->rotZ;
}

/**
 * PROCEDIMENTO: apagar_mpu
 * Uso: apagar_mpu(sensor);
 * ------------------------
 * Libera a memória alocada para o sensor "sensor". Após essa chamada, o ponteiro
 * "sensor" não deve ser mais utilizado.
 */
void apagar_mpu(MPU* sensor)
{
    free(sensor);
}
