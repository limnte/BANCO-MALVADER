#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "operacoes/operacoes.h"
#include "QUICKSORT.C"

int menu_consultas() {
    int op;
    printf("\n1 - Consultar saldo\n");
    printf("2 - Consultar dados\n");
    printf("3 - Listar por nome\n");
    printf("4 - Listar por conta\n");
    printf("0 - Voltar\n");
    printf("Escolha: ");
    scanf("%d", &op);
    return op;
}

//placeholder pras funções de consultas, coloca as funções na case basicamente

void submenu_consultas() {
    int op;
    do {
        limpar_tela();
        header();
        op = menu_consultas();
        switch (op) {
            case 1: ver_saldo(); break;
            case 2: printf(">>> Consultando dados...\n"); break;
            case 3: printf(">>> Listando por nome...\n"); break;
            case 4: printf(">>> Listando por conta...\n"); break;
            case 0: printf("Voltando ao menu principal...\n"); break;
            default: printf("Opção inválida!\n");
        }
        if (op != 0) system("pause");
    } while (op != 0);
}
