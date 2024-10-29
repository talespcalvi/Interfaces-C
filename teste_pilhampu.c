#include <stdio.h>
#include "pilhampuTAD.h"

int main() {
    pilhaMPU* pilha = criar_pilha();

    if (vazia(pilha)) {
        printf("Pilha inicialmente vazia.\n");
    }

    printf("Empilhando sensores...\n");

    for (int i = 0; i < 3; i++) {
        MPU* sensor = criar_mpu(i, i);
        setar_aceleracao(sensor, 1000 * (i + 1), 2000 * (i + 1), 3000 * (i + 1));
        setar_rotacao(sensor, 10 * (i + 1), 20 * (i + 1), 30 * (i + 1));
        empilhar(pilha, sensor);
        printf("Sensor %d empilhado com sucesso.\n", i + 1);
    }

    if (cheia(pilha)) {
        printf("A pilha está cheia! Não é possível empilhar mais sensores.\n");
    } else {
        MPU* sensorExtra = criar_mpu(0, 0);
        empilhar(pilha, sensorExtra);
        printf("Sensor extra empilhado com sucesso.\n");
    }

    printf("\nDesempilhando sensores...\n");
    while (!vazia(pilha)) {
        MPU* sensor = desempilhar(pilha);

        float acX, acY, acZ, rotX, rotY, rotZ;
        pegar_aceleracao(sensor, &acX, &acY, &acZ);
        pegar_rotacao(sensor, &rotX, &rotY, &rotZ);

        printf("Aceleração do Sensor: X = %.2fg, Y = %.2fg, Z = %.2fg\n", acX, acY, acZ);
        printf("Rotação do Sensor: X = %.2f°/s, Y = %.2f°/s, Z = %.2f°/s\n\n", rotX, rotY, rotZ);

        apagar_mpu(sensor);
    }

    if (vazia(pilha)) {
        printf("Pilha vazia após desempilhar todos os sensores.\n");
    }

    apagar_pilha(pilha);

    return 0;
}
