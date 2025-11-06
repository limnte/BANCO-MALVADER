#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"
#include "clientes/io.h"
#include "menus/menu.h"
#include <locale.h>

void ver_saldo(){
    //o i_contalogada é util aqui pq ele da um "codigo" unico pra cada conta criada
    printf("\n====== SALDO ATUAL ======\n");
    printf("R$%.2lf\n", nova[i_contalogada].Saldo);
}

void fazer_deposito(){
    double valor_deposito = 0.0;

    printf("\n====== DEPOSITO ======\n");
    printf("Valor a depositar (Ex: 50.00): ");
    scanf("%lf", &valor_deposito);
    limpar_buffer_entrada();

    if(valor_deposito <= 0.1){
        printf("Erro: Valor invalido. O deposito deve ser maior que R$0.1\n");
        return;
    }

    //atualiza o saldo na memoria
    nova[i_contalogada].Saldo += valor_deposito;
    //salva as contas na memoria de volta para o arquivo
    salvar_todas_contas(nova, total_contas);

    printf("\nDeposito de R$%.2lf realizado com sucesso.\n", valor_deposito);

}

void fazer_saque(){
    double valor_saque = 0.0;

    printf("\n====== SAQUE ======\n");
    printf("Valor a sacar (Ex: 50.00): ");
    scanf("%lf", &valor_saque);
    limpar_buffer_entrada();

    if(valor_saque <= 0.1){
        printf("Erro: Valor invalido. O saque deve ser maior que R$0.1\n");
        return;
    }

    if(valor_saque > nova[i_contalogada].Saldo){
        printf("Erro: Saldo insuficiente!");
        return;
    }

    //atualiza o saldo na memoria
    nova[i_contalogada].Saldo -= valor_saque;
    salvar_todas_contas(nova, total_contas);

    printf("\nSaque de R$%.2lf realizado com sucesso.\n", valor_saque);
}
void fazer_transferencia(){
    int conta_destino = 0;
    double valor = 0.0;
    printf("\n====== TRANSFERÊNCIA ======\n");
    printf("Digite o número da conta de destino: ");
    if (scanf("%d", &conta_destino) != 1) {
        printf("Entrada inválida.\n");
        // limpar buffer
        int ch; while ((ch = getchar()) != '\n' && ch != EOF);
        return;
    }
    if (conta_destino == nova[i_contalogada].Conta) {
        printf("Erro: não é possível transferir para a mesma conta.\n");
        return;
    }
    printf("Digite o valor a ser transferido: R$ ");
    if (scanf("%lf", &valor) != 1) {
        printf("Entrada inválida.\n");
        int ch; while ((ch = getchar()) != '\n' && ch != EOF);
        return;
    }
    if (valor <= 0.0) {
        printf("Erro: valor inválido.\n");
        return;
    }
    if (valor > nova[i_contalogada].Saldo) {
        printf("Erro: saldo insuficiente.\n");
        return;
    }

    // procurar conta destino
    int idx_dest = -1;
    for (int i = 0; i < total_contas; i++) {
        if (nova[i].Conta == conta_destino) {
            idx_dest = i;
            break;
        }
    }
    if (idx_dest == -1) {
        printf("Erro: conta de destino não encontrada.\n");
        return;
    }

    // executar transferência
    nova[i_contalogada].Saldo -= valor;
    nova[idx_dest].Saldo += valor;

    salvar_todas_contas(nova, total_contas);

    printf("Transferência de R$%.2lf para a conta %d realizada com sucesso.\n", valor, conta_destino);
}