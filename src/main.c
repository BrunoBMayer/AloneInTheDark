#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"


// Função para mover o ponto com base na entrada do teclado
void movePoint(int *x, int *y, char direction, int obst[80][24]);

int obst[80][24];

void print_obst(int obst[80][24], int *x, int *y);

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
obst[78][6] = 1; 
obst[78][15] = 1;

obst[77][6] = 1; 
obst[77][15] = 1;

obst[76][6] = 1; 
obst[76][7] = 1;
obst[76][8] = 1; 
obst[76][9] = 1;
obst[76][10] = 1; 
obst[76][11] = 1;
obst[76][12] = 1; 
obst[76][15] = 1;
obst[76][18] = 1; 
obst[76][21] = 1;

obst[75][12] = 1; 
obst[75][15] = 1;
obst[75][18] = 1; 
obst[75][21] = 1;

obst[74][12] = 1; 
obst[74][15] = 1;
obst[74][18] = 1; 
obst[74][21] = 1;

obst[73][4] = 1; 
obst[73][5] = 1;
obst[73][6] = 1; 
obst[73][9] = 1;
obst[73][10] = 1; 
obst[73][11] = 1;
obst[73][12] = 1; 
obst[73][15] = 1;
obst[73][18] = 1; 
obst[73][21] = 1;
obst[73][22] = 1; 
obst[73][23] = 1;

obst[72][9] = 1; 
obst[72][15] = 1;
obst[72][18] = 1; 
obst[72][21] = 1;

obst[71][9] = 1; 
obst[71][15] = 1;
obst[71][18] = 1; 
obst[71][21] = 1;

obst[70][6] = 1; 
obst[70][9] = 1;
obst[70][12] = 1; 
obst[70][13] = 1; 
obst[70][14] = 1;
obst[70][15] = 1; 
obst[70][16] = 1;
obst[70][17] = 1; 
obst[70][18] = 1;
obst[70][21] = 1; 

obst[69][6] = 1;

obst[68][6] = 1;

obst[67][6] = 1;
obst[67][7] = 1; 
obst[67][8] = 1;
obst[67][9] = 1; 
obst[67][10] = 1;
obst[67][11] = 1; 
obst[67][12] = 1;
obst[67][13] = 1; 
obst[67][14] = 1;
obst[67][15] = 1; 
obst[67][16] = 1;
obst[67][17] = 1; 
obst[67][18] = 1;
obst[67][19] = 1; 
obst[67][20] = 1;
obst[67][21] = 1; 
obst[67][22] = 1;
obst[67][23] = 1; 

obst[66][6] = 1;

obst[65][6] = 1;

obst[64][6] = 1;
obst[64][7] = 1; 
obst[64][8] = 1;
obst[64][9] = 1; 
obst[64][10] = 1;
obst[64][11] = 1; 
obst[64][12] = 1;
obst[64][15] = 1; 
obst[64][16] = 1;
obst[64][17] = 1; 
obst[64][18] = 1;
obst[64][19] = 1; 
obst[64][20] = 1;
obst[64][21] = 1; 
obst[64][22] = 1;
obst[64][23] = 1; 

obst[63][6] = 1;
obst[63][12] = 1; 
obst[63][15] = 1;
obst[63][21] = 1; 

obst[62][6] = 1;
obst[62][12] = 1; 
obst[62][15] = 1;
obst[62][21] = 1;

obst[61][6] = 1;
obst[61][9] = 1; 
obst[61][12] = 1;
obst[61][15] = 1;
obst[61][6] = 1;
obst[61][12] = 1; 
obst[61][15] = 1;
obst[61][18] = 1;
obst[61][19] = 1;
obst[61][20] = 1; 
obst[61][21] = 1;

obst[60][9] = 1;
obst[60][12] = 1; 
obst[60][15] = 1;

obst[59][9] = 1;
obst[59][12] = 1; 
obst[59][15] = 1;

obst[58][4] = 1;
obst[58][5] = 1; 
obst[58][6] = 1;
obst[58][9] = 1;
obst[58][10] = 1; 
obst[58][11] = 1;
obst[58][12] = 1;
obst[58][15] = 1;
obst[58][18] = 1;
obst[58][21] = 1;
obst[58][22] = 1; 
obst[58][23] = 1;

obst[57][18] = 1;

obst[56][18] = 1;

obst[55][4] = 1;
obst[55][5] = 1; 
obst[55][6] = 1;
obst[55][7] = 1;
obst[55][8] = 1; 
obst[55][9] = 1;
obst[55][10] = 1;
obst[55][11] = 1;
obst[55][12] = 1;
obst[55][13] = 1;
obst[55][14] = 1; 
obst[55][15] = 1;
obst[55][18] = 1;
obst[55][19] = 1; 
obst[55][20] = 1;
obst[55][21] = 1;
obst[55][22] = 1; 
obst[55][23] = 1;

obst[52][4] = 1;
obst[52][5] = 1; 
obst[52][6] = 1;
obst[52][9] = 1;
obst[52][10] = 1; 
obst[52][11] = 1;
obst[52][12] = 1;
obst[52][13] = 1; 
obst[52][14] = 1;
obst[52][15] = 1;
obst[52][16] = 1; 
obst[52][17] = 1;
obst[52][18] = 1;
obst[52][19] = 1; 
obst[52][20] = 1;
obst[52][21] = 1;
obst[52][22] = 1; 
obst[52][23] = 1;

obst[51][9] = 1;

obst[50][9] = 1;

obst[49][4] = 1;
obst[49][5] = 1;
obst[49][6] = 1;
obst[49][9] = 1;
obst[49][12] = 1;
obst[49][13] = 1;
obst[49][14] = 1;
obst[49][15] = 1;
obst[49][16] = 1;
obst[49][17] = 1;
obst[49][18] = 1;
obst[49][21] = 1;
obst[49][22] = 1;
obst[49][23] = 1;

obst[48][6] = 1;
obst[48][12] = 1;

obst[47][6] = 1;
obst[47][12] = 1;

obst[46][6] = 1;
obst[46][9] = 1;
obst[46][10] = 1;
obst[46][11] = 1;
obst[46][12] = 1;
obst[46][13] = 1;
obst[46][14] = 1;
obst[46][15] = 1;
obst[46][18] = 1;
obst[46][21] = 1;

obst[45][6] = 1;
obst[45][9] = 1;
obst[45][18] = 1;
obst[45][21] = 1;

obst[44][6] = 1;
obst[44][9] = 1;
obst[44][18] = 1;
obst[44][21] = 1;

obst[43][6] = 1;
obst[43][7] = 1;
obst[43][8] = 1;
obst[43][9] = 1;
obst[43][12] = 1;
obst[43][13] = 1;
obst[43][14] = 1;
obst[43][15] = 1;
obst[43][18] = 1;
obst[43][19] = 1;
obst[43][20] = 1;
obst[43][21] = 1;

obst[42][12] = 1;
obst[42][21] = 1;

obst[41][12] = 1;
obst[41][21] = 1;

obst[40][6] = 1;
obst[40][7] = 1;
obst[40][8] = 1;
obst[40][9] = 1;
obst[40][10] = 1;
obst[40][11] = 1;
obst[40][12] = 1;
obst[40][13] = 1;
obst[40][14] = 1;
obst[40][15] = 1;
obst[40][16] = 1;
obst[40][17] = 1;
obst[40][18] = 1;
obst[40][21] = 1;
obst[40][22] = 1;
obst[40][23] = 1;

obst[39][9] = 1;

obst[38][9] = 1;

obst[37][4] = 1;
obst[37][5] = 1;
obst[37][6] = 1;
obst[37][9] = 1;
obst[37][12] = 1;
obst[37][15] = 1;
obst[37][16] = 1;
obst[37][17] = 1;
obst[37][18] = 1;
obst[37][19] = 1;
obst[37][20] = 1;
obst[37][21] = 1;
obst[37][22] = 1;
obst[37][23] = 1;

obst[36][6] = 1;
obst[36][12] = 1;
obst[36][15] = 1;
obst[36][18] = 1;

obst[35][6] = 1;
obst[35][12] = 1;
obst[35][15] = 1;
obst[35][18] = 1;

obst[34][6] = 1;
obst[34][12] = 1;
obst[34][15] = 1;
obst[34][18] = 1;
obst[34][6] = 1;
obst[34][12] = 1;
obst[34][15] = 1;
obst[34][18] = 1;
obst[34][19] = 1;
obst[34][20] = 1;
obst[34][21] = 1;

obst[33][9] = 1;
obst[33][12] = 1;

obst[32][9] = 1;
obst[32][12] = 1;

obst[31][4] = 1;
obst[31][5] = 1;
obst[31][6] = 1;
obst[31][7] = 1;
obst[31][8] = 1;
obst[31][9] = 1;
obst[31][12] = 1;
obst[31][13] = 1;
obst[31][14] = 1;
obst[31][15] = 1;
obst[31][18] = 1;
obst[31][19] = 1;
obst[31][20] = 1;
obst[31][21] = 1;
obst[31][22] = 1;
obst[31][23] = 1;

obst[28][6] = 1;
obst[28][7] = 1;
obst[28][8] = 1;
obst[28][9] = 1;
obst[28][12] = 1;
obst[28][13] = 1;
obst[28][14] = 1;
obst[28][15] = 1;
obst[28][16] = 1;
obst[28][17] = 1;
obst[28][18] = 1;
obst[28][19] = 1;
obst[28][20] = 1;
obst[28][21] = 1;

obst[27][15] = 1;
obst[27][21] = 1;

obst[26][15] = 1;
obst[26][21] = 1;

obst[25][4] = 1;
obst[25][5] = 1;
obst[25][6] = 1;
obst[25][9] = 1;
obst[25][12] = 1;
obst[25][13] = 1;
obst[25][14] = 1;
obst[25][15] = 1;
obst[25][18] = 1;
obst[25][21] = 1;

obst[24][6] = 1;
obst[24][9] = 1;
obst[24][12] = 1;
obst[24][18] = 1;

obst[23][6] = 1;
obst[23][9] = 1;
obst[23][12] = 1;
obst[23][18] = 1;

obst[22][6] = 1;
obst[22][9] = 1;
obst[22][10] = 1;
obst[22][11] = 1;
obst[22][12] = 1;
obst[22][15] = 1;
obst[22][16] = 1;
obst[22][17] = 1;
obst[22][18] = 1;
obst[22][19] = 1;
obst[22][20] = 1;
obst[22][21] = 1;
obst[22][22] = 1;
obst[22][23] = 1;

obst[21][6] = 1;
obst[21][15] = 1;

obst[20][6] = 1;
obst[20][15] = 1;

obst[19][6] = 1;
obst[19][7] = 1;
obst[19][8] = 1;
obst[19][9] = 1;
obst[19][10] = 1;
obst[19][11] = 1;
obst[19][12] = 1;
obst[19][15] = 1;
obst[19][18] = 1;
obst[19][21] = 1;
obst[19][22] = 1;
obst[19][23] = 1;

obst[18][15] = 1;
obst[18][18] = 1;

obst[17][15] = 1;
obst[17][18] = 1;

obst[16][6] = 1;
obst[16][7] = 1;
obst[16][8] = 1;
obst[16][9] = 1;
obst[16][12] = 1;
obst[16][15] = 1;
obst[16][16] = 1;
obst[16][17] = 1;
obst[16][18] = 1;
obst[16][19] = 1;
obst[16][20] = 1;
obst[16][21] = 1;

obst[15][9] = 1;
obst[15][12] = 1;
obst[15][18] = 1;

obst[14][9] = 1;
obst[14][12] = 1;
obst[14][18] = 1;

obst[13][4] = 1;
obst[13][5] = 1;
obst[13][6] = 1;
obst[13][7] = 1;
obst[13][8] = 1;
obst[13][9] = 1;
obst[13][10] = 1;
obst[13][11] = 1;
obst[13][12] = 1;
obst[13][13] = 1;
obst[13][14] = 1;
obst[13][15] = 1;
obst[13][18] = 1;
obst[13][19] = 1;
obst[13][20] = 1;
obst[13][21] = 1;
obst[13][22] = 1;
obst[13][23] = 1;

obst[12][9] = 1;
obst[12][15] = 1;

obst[11][9] = 1;
obst[11][15] = 1;

obst[10][6] = 1;
obst[10][9] = 1;
obst[10][12] = 1;
obst[10][15] = 1;
obst[10][16] = 1;
obst[10][17] = 1;
obst[10][18] = 1;
obst[10][21] = 1;

obst[9][6] = 1;
obst[9][9] = 1;
obst[9][12] = 1;
obst[9][15] = 1;
obst[9][18] = 1;
obst[9][21] = 1;

obst[8][6] = 1;
obst[8][9] = 1;
obst[8][12] = 1;
obst[8][15] = 1;
obst[8][18] = 1;
obst[8][21] = 1;

obst[7][4] = 1;
obst[7][5] = 1;
obst[7][6] = 1;
obst[7][9] = 1;
obst[7][12] = 1;
obst[7][15] = 1;
obst[7][18] = 1;
obst[7][21] = 1;

obst[6][12] = 1;
obst[6][18] = 1;
obst[6][21] = 1;

obst[5][12] = 1;
obst[5][18] = 1;
obst[5][21] = 1;

obst[4][4] = 1;
obst[4][5] = 1;
obst[4][6] = 1;
obst[4][9] = 1;
obst[4][10] = 1;
obst[4][11] = 1;
obst[4][12] = 1;
obst[4][13] = 1;
obst[4][14] = 1;
obst[4][15] = 1;
obst[4][18] = 1;
obst[4][21] = 1;
obst[4][22] = 1;
obst[4][23] = 1;

obst[3][15] = 1;




    


    int x = 34, y = 14;  // Posição inicial do ponto

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
            if (key == '\n') {
                screenDestroy();

                printf("  _____.__               .___             __                            ___    \n");
                printf("_/ ____\\__| _____      __| _/____        |__| ____   ____   ____    /\\  \\  \\   \n");
                printf("\\   __\\|  |/     \\    / __ |/ __ \\       |  |/  _ \\ / ___\\ /  _ \\   \\/   \\  \\  \n");
                printf(" |  |  |  |  Y Y  \\  / /_/ \\  ___/       |  (  <_> ) /_/  >  <_> )  /\\    )  ) \n");
                printf(" |__|  |__|__|_|  /  \\____ |\\___  >  /\\__|  |\\____/\\___  / \\____/   \\/   /  /  \n");
                printf("                \\/        \\/    \\/   \\______|     /_____/               /__/   \n");

                sleep(4); // Atraso de 4 segundos
                break;
            }

            // Move o ponto com base na tecla pressionada
            movePoint(&x, &y, key, obst);

            // Limpa a tela
            screenClear();

            print_obst(obst, &x, &y);

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

void print_obst(int obst[80][24], int *x, int *y){

    for(int i = 0; i < 80; i++){
        for(int j = 0; j < 24; j++){
            
            screenGotoxy(i,j);

            if ((obst[i][j] == 1) && (obst[i][j] == ((obst[*x-1][*y]) || (obst[*x+1][*y]) || (obst[*x][*y-1]) || (obst[*x][*y+1]) || (obst[*x-1][*y-1]) || (obst[*x-1][*y+1]) || (obst[*x+1][*y-1]) || (obst[*x-1][*y+1])))){

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