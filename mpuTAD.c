#include <stdlib.h>
#include "mpuTAD.h"

// Escalas para as sensibilidades
int ac_escala[] = {16384, 8192, 4096, 2048};
float rot_escala[] = {131, 65.5, 32.8, 16.4};

struct MPU {
    int ax, ay, az;          // Valores brutos da aceleração
    float acX, acY, acZ;     // Valores finais da aceleração
    int rx, ry, rz;          // Valores brutos da rotação
    float rotX, rotY, rotZ;  // Valores finais da rotação
    int ac_sens, rot_sens;   // Sensibilidade da aceleração e rotação
};

MPU* criar_mpu(int ac_sens, int rot_sens)
{
  MPU* sensor = (MPU*) malloc(sizeof(MPU));
  sensor->ac_sens = ac_sens;
  sensor->rot_sens = rot_sens;
  
  return sensor;
}

void setar_aceleracao(MPU* sensor, int ax, int ay, int az)
{
  sensor->ax = ax;
  sensor->ay = ay;
  sensor->az = az;

  // Aplicação da fórmula de aceleração g
  sensor->acX = (float) ax / ac_escala[sensor->ac_sens];
  sensor->acY = (float) ay / ac_escala[sensor->ac_sens];
  sensor->acZ = (float) az / ac_escala[sensor->ac_sens];
}

void setar_rotacao(MPU* sensor, int rx, int ry, int rz)
{
  sensor->rx = rx;
  sensor->ry = ry;
  sensor->rz = rz;

  // Aplicação da fórmula de rotação °s-¹
  sensor->rotX = (float) rx / rot_escala[sensor->rot_sens];
  sensor->rotY = (float) ry / rot_escala[sensor->rot_sens];
  sensor->rotZ = (float) rz / rot_escala[sensor->rot_sens];
}

void pegar_aceleracao(MPU* sensor, float* acX, float* acY, float* acZ)
{
  *acX = sensor->acX;
  *acY = sensor->acY;
  *acZ = sensor->acZ;
}

void pegar_rotacao(MPU* sensor, float* rotX, float* rotY, float* rotZ)
{
  *rotX = sensor->rotX;
  *rotY = sensor->rotY;
  *rotZ = sensor->rotZ;
}

void apagar_mpu(MPU* sensor)
{
  free(sensor);
}
