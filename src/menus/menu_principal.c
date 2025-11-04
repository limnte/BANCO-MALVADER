#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

//nao precisa mudar nada aqui, eu acho Ass.Gabe

void limpar_tela(){
    system("cls || clear");
}

void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void header(){
    printf("===========================================================================\n");
    printf("  ____                          __  __       _                _           \n");
    printf(" |  _ \\                        |  \\/  |     | |              | |          \n");
    printf(" | |_) | __ _ _ __   ___ ___   | \\  / | __ _| |_   ____ _  __| | ___ _ __ \n");
    printf(" |  _ < / _` | '_ \\ / __/ _ \\  | |\\/| |/ _` | \\ \\ / / _` |/ _` |/ _ \\ '__|\n");
    printf(" | |_) | (_| | | | | (_| (_) | | |  | | (_| | |\\ V / (_| | (_| |  __/ |   \n");
    printf(" |____/ \\__,_|_| |_|\\___\\___/  |_|  |_|\\__,_|_| \\_/ \\__,_|\\__,_|\\___|_|   \n");
    printf("===========================================================================\n");
}

int menu_inicial(){
    int op;
    printf("\n1 - Entrar\n");
    printf("2 - Criar Conta\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
    scanf("%d", &op);
    return op;
}


int menu_principal() {
    int op;
    printf("\n1 - Gerenciar conta\n");
    printf("2 - Consultas\n");
    printf("3 - Operações\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
    scanf("%d", &op);
    return op;
}
