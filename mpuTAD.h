#ifndef MPU_TAD_H
#define MPU_TAD_H

typedef struct 
{
  int ax, ay, az;          // Valores brutos da aceleração
  float acX, acY, acZ;     // Valores finais da aceleração
  int rx, ry, rz;          // Valores brutos da rotação
  float rotX, rotY, rotZ;  // Valores finais da rotação
  int ac_sens, rot_sens;   // Sensibilidade da aceleração e rotação
} MPU;

MPU* criar_mpu(int ac_sens, int rot_sens);
void setar_aceleracao(MPU* sensor, int ax, int ay, int az);
void setar_rotacao(MPU* sensor, int rx, int ry, int rz);
void pegar_aceleracao(MPU* sensor, float* acX, float* acY, float* acZ);
void pegar_rotacao(MPU* sensor, float* rotX, float* rotY, float* rotZ);
void apagar_mpu(MPU* sensor);

#endif