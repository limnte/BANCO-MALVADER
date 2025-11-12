#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "clientes/io.h"
#include "gerenciamento/gerenciamento.h"

int menu_gerenciar() {
    int op;
    printf("\n1 - Excluir conta\n");
    printf("2 - Alterar dados\n");
    printf("0 - Voltar\n");
    printf("Escolha: ");
    scanf("%d", &op);
    limpar_buffer_entrada();
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
            case 1: excluir_conta(); if(i_contalogada == -1) op = 0; break;
            case 2: alterar_dados(); break;
            case 0: printf("Voltando ao menu principal...\n"); break;
            default: printf("Opção inválida!\n");
        }
        if (op != 0) system("pause");
    } while (op != 0);
}