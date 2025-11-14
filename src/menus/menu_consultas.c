#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "operacoes/operacoes.h"
#include "gerenciamento/gerenciamento.h"

int menu_consultas() {
    int op;
    printf("\n1 - Consultar saldo\n");
    printf("2 - Consultar dados\n");
    printf("3 - Listar contas por nome\n");
    printf("4 - Listar por numero da conta\n");
    printf("5 - Extrato\n");
    printf("0 - Voltar\n");
    printf("Escolha: ");
    scanf("%d", &op);
    limpar_buffer_entrada();
    return op;
}

void submenu_consultas() {
    int op;
    do {
        limpar_tela();
        header();
        op = menu_consultas();
        switch (op) {
            case 1: ver_saldo(); break;
            case 2: consultar_dados(); break;
            case 3: listar_contas_por_nome(); break;
            case 4: listar_contas_por_conta(); break;
            case 5: mostrar_extrato(); break;
            case 0: printf("Voltando ao menu principal...\n"); break;
            default: printf("Opção inválida!\n");
        }
        if (op != 0) pausar_tela();
    } while (op != 0);
}
