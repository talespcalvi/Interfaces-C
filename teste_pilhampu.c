#include <stdio.h>
#include "pilhampuTAD.h"

int main(void) 
{
    pilhaMPU*  pilha = criar_pilha();

    MPU* sensor1 = criar_mpu(0, 0);
    setar_aceleracao(sensor1, 16384, 0, 0);
    setar_rotacao(sensor1, 131, 0, 0);
    empilhar(pilha, sensor1);
    
    MPU* sensor2 = criar_mpu(1, 1); // ±4g, ±500°/s
    setar_aceleracao(sensor2, 8192, -8192, 4096); // Exemplo de acelerações variadas
    setar_rotacao(sensor2, 65, -65, 33);           // Exemplo de rotações variadas
    empilhar(pilha, sensor2);

    MPU* sensor3 = criar_mpu(2, 2); // ±8g, ±1000°/s
    setar_aceleracao(sensor3, -4096, -4096, -4096); // Acelerações negativas
    setar_rotacao(sensor3, -32, -32, -32);           // Rotações negativas
    empilhar(pilha, sensor3);

    while (!vazia(pilha))
    {
        MPU* sensor = desempilhar(pilha);

        float acX, acY, acZ, rotX, rotY, rotZ;
        pegar_aceleracao(sensor, &acX, &acY, &acZ);
        pegar_rotacao(sensor, &rotX,  &rotY, &rotZ);

        printf("Aceleração: X = %.4fg, Y = %.4fg, Z = %.4fg\n", acX, acY, acZ);
        printf("Rotação: X = %.4f°/s, Y = %.4f°/s, Z = %.4f°/s\n\n", rotX, rotY, rotZ);

        apagar_mpu(sensor);
    }

    apagar_pilha(pilha);

    return 0;
}