#include <stdio.h>
#include "mpuTAD.h"

int main(void) 
{
  MPU* sensor = criar_mpu(0, 0);
  float acX, acY, acZ, rotX, rotY, rotZ;

  setar_aceleracao(sensor, 16384, 0, 0);
  setar_rotacao(sensor, 131, 0, 0);

  pegar_aceleracao(sensor, &acX, &acY, &acZ);
  pegar_rotacao(sensor, &rotX, &rotY, &rotZ);

  printf("Teste 1:\n");
  printf("Aceleração: X = %.2fg, Y = %.2fg, Z = %.2fg\n", acX, acY, acZ);
  printf("Rotação: X = %.2f°/s, Y = %.2f°/s, Z = %.2f°/s\n", rotX, rotY, rotZ);

  
  setar_aceleracao(sensor, 8192, -8192, 4096); 
  setar_rotacao(sensor, 65, -65, 33);           

  pegar_aceleracao(sensor, &acX, &acY, &acZ);
  pegar_rotacao(sensor, &rotX, &rotY, &rotZ);

  printf("Teste 2:\n");
  printf("Aceleração: X = %.4fg, Y = %.4fg, Z = %.4fg\n", acX, acY, acZ);
  printf("Rotação: X = %.4f°/s, Y = %.4f°/s, Z = %.4f°/s\n\n", rotX, rotY, rotZ);

  
  setar_aceleracao(sensor, -4096, -4096, -4096); 
  setar_rotacao(sensor, -32, -32, -32);

  pegar_aceleracao(sensor, &acX, &acY, &acZ);
  pegar_rotacao(sensor, &rotX, &rotY, &rotZ);

  printf("Teste 3:\n");
  printf("Aceleração: X = %.4fg, Y = %.4fg, Z = %.4fg\n", acX, acY, acZ);
  printf("Rotação: X = %.4f°/s, Y = %.4f°/s, Z = %.4f°/s\n\n", rotX, rotY, rotZ);

 
  setar_aceleracao(sensor, 1024, 512, 256);     
  setar_rotacao(sensor, 16, 8, 4);               

  pegar_aceleracao(sensor, &acX, &acY, &acZ);
  pegar_rotacao(sensor, &rotX, &rotY, &rotZ);

  printf("Teste 4:\n");
  printf("Aceleração: X = %.4fg, Y = %.4fg, Z = %.4fg\n", acX, acY, acZ);
  printf("Rotação: X = %.4f°/s, Y = %.4f°/s, Z = %.4f°/s\n\n", rotX, rotY, rotZ);

  
  setar_aceleracao(sensor, 100, 50, 25); 
  setar_rotacao(sensor, 5, 2, 1); 

  pegar_aceleracao(sensor, &acX, &acY, &acZ);
  pegar_rotacao(sensor, &rotX, &rotY, &rotZ);

  printf("Teste 5:\n");
  printf("Aceleração: X = %.4fg, Y = %.4fg, Z = %.4fg\n", acX, acY, acZ);
  printf("Rotação: X = %.4f°/s, Y = %.4f°/s, Z = %.4f°/s\n\n", rotX, rotY, rotZ);

  apagar_mpu(sensor);
   
  return 0;
}
