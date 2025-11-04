#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "clientes/io.h"

int menu_gerenciar() {
    int op;
    printf("\n1 - Abrir conta\n");
    printf("2 - Excluir conta\n");
    printf("3 - Alterar dados\n");
    printf("4 - Consultar dados\n");
    printf("0 - Voltar\n");
    printf("Escolha: ");
    scanf("%d", &op);
    return op;
}

//placeholder pras funções de gerenciar, coloca as funções na case basicamente

void submenu_gerenciar() {
    int op;
    do {
        limpar_tela();
        header();
        op = menu_gerenciar();
        switch (op) {
            case 1: criar_conta(nova, &total_contas); break;
            case 2: printf(">>> Excluindo conta...\n"); break;
            case 3: printf(">>> Alterando dados...\n"); break;
            case 4: printf(">>> Consultando dados...\n"); break;
            case 0: printf("Voltando ao menu principal...\n"); break;
            default: printf("Opção inválida!\n");
        }
        if (op != 0) system("pause");
    } while (op != 0);
}