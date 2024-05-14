#include <stdio.h>
#include <unistd.h>
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
    printf("👺");

    // Atualiza a tela
    screenUpdate();

    // Loop principal do jogo
    while (1) {
        // Captura a entrada do teclado
        if (keyhit()) {
            char key = readch();

            // Verifica se a tecla Enter foi pressionada para encerrar o programa
            if (key == '\n') {
                system("clear");
                
                printf("\n.d888 d8b                          888                  d8b                                     88b.   \n");
                printf("d88P\"  Y8P                         888                  Y8P                                     \"Y88b  \n");
                printf("888                                888                                                            Y88b \n");
                printf("888888 888 88888b.d88b.        .d88888  .d88b.         8888  .d88b.   .d88b.   .d88b.       d8b    888 \n");
                printf("888    888 888 \"888 \"88b      d88\" 888 d8P  Y8b        \"888 d88\"\"88b d88P\"88b d88\"\"88b      Y8P    888 \n");
                printf("888    888 888  888  888      888  888 88888888         888 888  888 888  888 888  888            d88P \n");
                printf("888    888 888  888  888      Y88b 888 Y8b.             888 Y88..88P Y88b 888 Y88..88P      d8b .d88P  \n");
                printf("888    888 888  888  888       \"Y88888  \"Y8888          888  \"Y88P\"   \"Y88888  \"Y88P\"       Y8P 88P\"   \n");
                printf("                                                        888               888                          \n");
                printf("                                                       d88P          Y8b d88P                          \n");
                printf("                                                     888P\"            \"Y88P\"                          \n");

                sleep(4); // Atraso de 4 segundos
                break;
            }

            // Move o ponto com base na tecla pressionada
            movePoint(&x, &y, key);

            // Limpa a tela
            screenClear();

            // Desenha o ponto na nova posição
            screenSetColor(WHITE, BLACK); // Define a cor do ponto para branco
            screenGotoxy(x, y);
            printf("👺");

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
