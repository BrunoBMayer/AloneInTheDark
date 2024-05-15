#include <stdio.h>

int main() {
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
            system("clear");
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

            printf("\n");
            printf("1 - Iniciar o jogo\n");
            printf("2 - Como jogar\n");
            printf("3 - Pontuações salvas\n\n");
            printf("0 - Voltar para a tela inicial");
            printf("Digite a opção: ");
            scanf("%d", &var);

        }

        if(var == 0){

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
