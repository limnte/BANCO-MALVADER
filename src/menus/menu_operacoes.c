#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "operacoes/operacoes.h"

int menu_operacoes() {
    int op;
    printf("\n1 - Depósito\n");
    printf("2 - Saque\n");
    printf("3 - Transferência\n");
    printf("0 - Voltar\n");
    printf("Escolha: ");
    scanf("%d", &op);
    limpar_buffer_entrada();
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
            case 1: fazer_deposito(); break;
            case 2: fazer_saque(); break;
            case 3: fazer_transferencia(); break;
            case 0: printf("Voltando ao menu principal...\n"); break;
            default: printf("Opção inválida!\n");
        }
        if (op != 0) system("pause");
    } while (op != 0);
}