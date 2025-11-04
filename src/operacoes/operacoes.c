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