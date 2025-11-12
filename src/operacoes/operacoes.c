#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"
#include "clientes/io.h"
#include "menus/menu.h"
#include <locale.h>
#include <string.h>


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
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    char cpf_destino[12];
    double valor = 0.0;
    int ind_dest = -1;
    int confirmar;

    printf("\n====== TRANSFERÊNCIA ======\n");

    printf("Digite o CPF da conta de destino(apenas numeros): ");
    scanf("%11s", cpf_destino);
    limpar_buffer_entrada();

    if(strcmp(nova[i_contalogada].Cpf, cpf_destino) == 0){
        printf("Erro: não é possível transferir para a mesma conta.\n");
        return;
    }

    //procurando a conta de destino pelo cpf
    for(int i = 0; i < total_contas; i++){
        if(strcmp(nova[i].Cpf, cpf_destino) == 0){
            ind_dest = i; //Encontrou o destinatario
            break;
        }
    }

    if(ind_dest == -1){
        printf("Erro: CPF de destino não encontrado.\n");
        return;
    }

    //validar valor de transferencia

    printf("Digite o valor a ser transferido: R$");
    if (scanf("%lf", &valor) != 1) {
        printf("Entrada invalida.\n");
        limpar_buffer_entrada();
        return;
    }
    limpar_buffer_entrada();

    if(valor <= 0.1){
        printf("Erro: Valor inválido!.\n");
        return;
    }

    if(valor>nova[i_contalogada].Saldo){
        printf("Erro: Saldo insuficiente.\n");
        return;
    }

    // confirmar conta de destino:
    Conta* destino = &nova[ind_dest];

    printf("\n====== Confirmar transferência ======\n");
    printf("Valor: R$%.2lf\n", valor);
    printf("Para: %s %s\n",destino->Nome, destino->Sobrenome);
    printf("CPF: %s\n",destino->Cpf);
    printf("\nConfirmar?(sim=1/Cancelar=0): ");
    scanf("%d",&confirmar);
    limpar_buffer_entrada();

    if(confirmar == 1){
        nova[i_contalogada].Saldo -= valor;
        nova[ind_dest].Saldo += valor;

        salvar_todas_contas(nova, total_contas);

        printf("\nTransferencia realizada com sucesso!");
    }else{
        printf("\nTransferencia cancelada.\n");
    }


}