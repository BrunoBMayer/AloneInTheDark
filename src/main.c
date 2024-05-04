// Código principal do jogo
#include <string.h>
#include <stdio.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

// Função para mover o ponto com base na entrada do teclado
void movePoint(int *x, int *y, char direction) {
    switch (direction) {
        case 'a':
            if (*x > 1) // Verifica se não está na borda esquerda
                (*x)--;
            break;
        case 'd':
            if (*x < 79) // Largura da tela - 1 (80 colunas)
                (*x)++;
            break;
        case 'w':
            if (*y > 1) // Verifica se não está na borda superior
                (*y)--;
            break;
        case 's':
            if (*y < 23) // Altura da tela - 1 (24 linhas)
                (*y)++;
            break;
        default:
            break;
    }
}

int main() {
    int x = 34, y = 12;  // Posição inicial do ponto

    // Inicializa as bibliotecas
    screenInit(1);   // Inicializa a tela com bordas
    keyboardInit();  // Inicializa o teclado
    timerInit(50);   // Inicializa o temporizador com um intervalo de 50 milissegundos

    // Desenha o ponto inicial na tela
    screenSetColor(WHITE, BLACK); // Define a cor do ponto para branco
    screenGotoxy(x, y);
    printf("O");

    // Atualiza a tela
    screenUpdate();

    // Loop principal do jogo
    while (1) {
        // Captura a entrada do teclado
        if (keyhit()) {
            char key = readch();

            // Verifica se a tecla Enter foi pressionada para encerrar o programa
            if (key == '\n') 
                break;

            // Move o ponto com base na tecla pressionada
            movePoint(&x, &y, key);

            // Limpa a tela
            screenClear();

            // Desenha o ponto na nova posição
            screenSetColor(WHITE, BLACK); // Define a cor do ponto para branco
            screenGotoxy(x, y);
            printf("O");

            // Atualiza a tela
            screenUpdate();
        }
    }

    // Finaliza as bibliotecas
    keyboardDestroy(); // Finaliza o teclado
    screenDestroy();   // Finaliza a tela
    timerDestroy();    // Finaliza o temporizador

    return 0;
}