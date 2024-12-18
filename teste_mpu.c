#include <stdio.h>
#include "mpuTAD.h"

int main(void) 
{
  MPU* sensor = criar_mpu(0, 0); // Cria o sensor MPU com sensibilidade de ±2g e ±250°/s
  float acX, acY, acZ, rotX, rotY, rotZ;

  // Define os valores brutos
  setar_aceleracao(sensor, 16384, 0, 0); // 1g no eixo x
  setar_rotacao(sensor, 131, 0, 0);      // 1°/s no eixo X

  // Indexa os valores ao sensor
  pegar_aceleracao(sensor, &acX, &acY, &acZ);
  pegar_rotacao(sensor, &rotX, &rotY, &rotZ);

  // Calcula dos valores de aceleração e rotação
  printf("Teste 1:\n");
  printf("Aceleração: X = %.2fg, Y = %.2fg, Z = %.2fg\n", acX, acY, acZ);
  printf("Rotação: X = %.2f°/s, Y = %.2f°/s, Z = %.2f°/s\n", rotX, rotY, rotZ);

  
  setar_aceleracao(sensor, 8192, -8192, 4096); // ±4g nos eixos
  setar_rotacao(sensor, 65, -65, 33);          // ±500°/s nos eixos

  pegar_aceleracao(sensor, &acX, &acY, &acZ);
  pegar_rotacao(sensor, &rotX, &rotY, &rotZ);

  printf("Teste 2:\n");
  printf("Aceleração: X = %.4fg, Y = %.4fg, Z = %.4fg\n", acX, acY, acZ);
  printf("Rotação: X = %.4f°/s, Y = %.4f°/s, Z = %.4f°/s\n\n", rotX, rotY, rotZ);

  
  setar_aceleracao(sensor, -4096, -4096, -4096); // -8g nos três eixos
  setar_rotacao(sensor, -32, -32, -32);          // -1000°/s nos três eixos 

  pegar_aceleracao(sensor, &acX, &acY, &acZ);
  pegar_rotacao(sensor, &rotX, &rotY, &rotZ);

  printf("Teste 3:\n");
  printf("Aceleração: X = %.4fg, Y = %.4fg, Z = %.4fg\n", acX, acY, acZ);
  printf("Rotação: X = %.4f°/s, Y = %.4f°/s, Z = %.4f°/s\n\n", rotX, rotY, rotZ);

 
  setar_aceleracao(sensor, 1024, 512, 256); // ±16g com pequenos valores     
  setar_rotacao(sensor, 16, 8, 4);          // ±2000°/s com pequenos valores               

  pegar_aceleracao(sensor, &acX, &acY, &acZ);
  pegar_rotacao(sensor, &rotX, &rotY, &rotZ);

  printf("Teste 4:\n");
  printf("Aceleração: X = %.4fg, Y = %.4fg, Z = %.4fg\n", acX, acY, acZ);
  printf("Rotação: X = %.4f°/s, Y = %.4f°/s, Z = %.4f°/s\n\n", rotX, rotY, rotZ);

  
  setar_aceleracao(sensor, 100, 50, 25); // Valores menores que os tabelados
  setar_rotacao(sensor, 5, 2, 1);        // Valores menores que os tabelados

  pegar_aceleracao(sensor, &acX, &acY, &acZ);
  pegar_rotacao(sensor, &rotX, &rotY, &rotZ);

  printf("Teste 5:\n");
  printf("Aceleração: X = %.4fg, Y = %.4fg, Z = %.4fg\n", acX, acY, acZ);
  printf("Rotação: X = %.4f°/s, Y = %.4f°/s, Z = %.4f°/s\n\n", rotX, rotY, rotZ);

  apagar_mpu(sensor);
   
  return 0;
}
