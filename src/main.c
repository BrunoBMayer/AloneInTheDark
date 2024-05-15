#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

// Função para mover o ponto com base na entrada do teclado
void movePoint(int *x, int *y, char direction, int obst[80][24]);

int obst[80][24];

void print_obst(int obst[80][24]);

int tela_inicial();

int main() {

    tela_inicial();

    for(int i = 0; i < 80; i++){
        for(int j = 0; j < 24; j++){

            obst[i][j] = 0;
        }
    }


    // Mapa do primeiro labirinto

    //Coluna extrema esquerda
    for (int i = 3; i <= 24; i++) {
    obst[1][i] = 1; 
}

    //Parte de baixo 
    for (int i = 2; i <= 79; i++) {
    obst[i][23] = 1; 

 }

 // Coluna extrema direita 
    for (int j = 3; j <= 23; j++) {
    obst[79][j] = 1; 
}

// Coluna de cima 
for (int i = 4; i <= 79; i++) {
    obst[i][3] = 1; 
}




    


    int x = 34, y = 12;  // Posição inicial do ponto

    // Inicializa as bibliotecas
    screenInit(1);   // Inicializa a tela com bordas
    keyboardInit();  // Inicializa o teclado
    timerInit(50);   // Inicializa o temporizador com um intervalo de 50 milissegundos

    // Desenha o ponto inicial na tela
    screenSetColor(WHITE, BLACK); // Define a cor do ponto para branco
    screenGotoxy(x, y);
    printf("♟️");

    // Atualiza a tela
    screenUpdate();

    // Loop principal do jogo
    while (1) {
        // Captura a entrada do teclado
        if (keyhit()) {
            char key = readch();

            // Verifica se a tecla Enter foi pressionada para encerrar o programa
            if (key == ' ') {
                screenDestroy();

                
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
            movePoint(&x, &y, key, obst);

            // Limpa a tela
            screenClear();

            print_obst(obst);

            // Desenha o ponto na nova posição
            screenSetColor(WHITE, BLACK); // Define a cor do ponto para branco
            screenGotoxy(x, y);
            printf("♟️");

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

void movePoint(int *x, int *y, char direction, int obst[80][24]) {
    switch (direction) {
        case 'a':
            if ((*x > 1) && (obst[*x-1][*y] != 1)) // Verifica se não está na borda esquerda
                (*x)--;
            break;
        case 'd':
            if ((*x < 79) && (obst[*x+1][*y] != 1)) // Largura da tela - 1 (80 colunas)
                (*x)++;
            break;
        case 'w':
            if ((*y > 1) && (obst[*x][*y-1] != 1)) // Verifica se não está na borda superior
                (*y)--;
            break;
        case 's':
            if ((*y < 23) && (obst[*x][*y+1] != 1)) // Altura da tela - 1 (24 linhas)
                (*y)++;
            break;
        default:
            break;
    }
}

void print_obst(int obst[80][24]){

    for(int i = 0; i < 80; i++){
        for(int j = 0; j < 24; j++){
            
            screenGotoxy(i,j);

            if (obst[i][j] == 1){

                screenSetColor(WHITE, BLACK);
                printf("⚜️");

            }else if (obst[i][j] == 0){

                printf(" ");

            }
        }
    }

}

int tela_inicial(){

    int var;
    while(var != 1){
        printf("       .__                          .__            __  .__                  .___             __    \n");
        printf("_____  |  |   ____   ____   ____    |__| ____    _/  |_|  |__   ____      __| _/____ _______|  | __\n");
        printf("\\__  \\ |  |  /  _ \\ /    \\_/ __ \\   |  |/    \\   \\   __\\  |  \\_/ __ \\    / __ |\\__  \\\\_  __ \\  |/ /\n");
        printf(" / __ \\|  |_(  <_> )   |  \\  ___/   |  |   |  \\   |  | |   Y  \\  ___/   / /_/ | / __ \\|  | \\/    < \n");
        printf("(____  /____/\\____/|___|  /\\___  >  |__|___|  /   |__| |___|  /\\___  >  \\____ |(____  /__|  |__|_ \\\n");
        printf("     \\/                 \\/     \\/           \\/              \\/     \\/        \\/     \\/           \\/\n");
        printf("\n");
        printf("1 - Iniciar o jogo\n");
        printf("2 - Como jogar\n");
        printf("3 - Pontuações salvas\n\n");
        printf("Digite a opção: ");
        scanf("%d", &var);
        
        if(var == 2){
            screenDestroy();
            printf("_________                               ____.                                 __   \n");
            printf("\\_   ___ \\  ____   _____   ____        |    | ____   _________ _______    /\\  \\ \\  \n");
            printf("/    \\  \\/ /  _ \\ /     \\ /  _ \\       |    |/  _ \\ / ___\\__  \\\\__  __ \\   \\/   \\ \\ \n");
            printf("\\     \\___(  <_> )  Y Y  (  <_> )  /\\__|    (  <_> ) /_/  > __ \\|  | \\/   /\\   / / \n");
            printf(" \\______  /\\____/|__|_|  /\\____/   \\________|\\____/\\___  (____  /__|      \\/  /_/  \n");
            printf("        \\/             \\/                         /_____/     \\/                    \n");
            printf("\n");
            printf("Utilize as teclas W-A-S-D para mover o personagem pelos labiritnos.\n");
            printf("Procure as lanternas para aumentar a área de visão do personagem.\n");
            printf("O contador ficará rodando durante cada labirinto, seu tempo refletirá na sua pontuação.\n");
            printf("Importante: Se a contagem chegar em 0 você perdeu o jogo :(.\n");
            printf("Dica: Coletar todas as lanternas deixará o campo de visão no máximo nos últimos labirintos.\n");
            printf("\n");
            printf("1 - Iniciar o jogo\n");
            printf("2 - Como jogar\n");
            printf("3 - Pontuações salvas\n\n");
            printf("0 - Voltar para a tela inicial");
            printf("Digite a opção: ");
            scanf("%d", &var);
        }

        if(var == 3){
            
            screenDestroy();
            printf("\n");
            printf("1 - Iniciar o jogo\n");
            printf("2 - Como jogar\n");
            printf("3 - Pontuações salvas\n\n");
            printf("0 - Voltar para a tela inicial");
            printf("Digite a opção: ");
            scanf("%d", &var);

        }

        if(var == 0){
            
            screenDestroy();
            printf("       .__                          .__            __  .__                  .___             __    \n");
            printf("_____  |  |   ____   ____   ____    |__| ____    _/  |_|  |__   ____      __| _/____ _______|  | __\n");
            printf("\\__  \\ |  |  /  _ \\ /    \\_/ __ \\   |  |/    \\   \\   __\\  |  \\_/ __ \\    / __ |\\__  \\\\_  __ \\  |/ /\n");
            printf(" / __ \\|  |_(  <_> )   |  \\  ___/   |  |   |  \\   |  | |   Y  \\  ___/   / /_/ | / __ \\|  | \\/    < \n");
            printf("(____  /____/\\____/|___|  /\\___  >  |__|___|  /   |__| |___|  /\\___  >  \\____ |(____  /__|  |__|_ \\\n");
            printf("     \\/                 \\/     \\/           \\/              \\/     \\/        \\/     \\/           \\/\n");
            printf("\n");
            printf("1 - Iniciar o jogo\n");
            printf("2 - Como jogar\n");
            printf("3 - Pontuações salvas\n\n");
            printf("Digite a opção: ");
            scanf("%d", &var);

        }
    }

    return 0;
}