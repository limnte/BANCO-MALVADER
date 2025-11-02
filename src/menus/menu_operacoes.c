#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu_operacoes() {
    int op;
    printf("\n1 - Depósito\n");
    printf("2 - Saque\n");
    printf("3 - Transferência\n");
    printf("0 - Voltar\n");
    printf("Escolha: ");
    scanf("%d", &op);
    return op;
}

//placeholder pras funções de operações, coloca as funções na case basicamente
void submenu_operacoes() {
    int op;
    do {
        limpar_tela();
        header();
        op = menu_operacoes();
        switch (op) {
            case 1: printf(">>> Realizando depósito...\n"); break;
            case 2: printf(">>> Realizando saque...\n"); break;
            case 3: printf(">>> Realizando transferência...\n"); break;
            case 0: printf("Voltando ao menu principal...\n"); break;
            default: printf("Opção inválida!\n");
        }
        if (op != 0) system("pause");
    } while (op != 0);
}