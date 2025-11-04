#include <stdio.h>
#include <locale.h>
#include "io.h"
#include <string.h>
#include <stdlib.h>
#include "verificacao.h"
#include "menus/menu.h"

void criar_conta(Conta nova[], int *total_contas){
    setlocale(LC_ALL, "pt_BR.UTF-8");

	int resposta;
    int cpf_invalido = 0;
    int conta_invalida = 0;

    Conta *conta_atual = &nova[*total_contas];

    if(*total_contas >= 200){
        printf("Erro: Limite maximo de contas atingido!\n");
        return;
    }

    do{
        //dados pessoais
        printf("\n=== Criacao de Nova Conta ===\n");
        printf("Por favor, preencha os dados abaixo:\n\n");

        printf("Primeiro nome: ");   
        scanf(" %19[^\n]", conta_atual->Nome);
        limpar_buffer_entrada();	

        printf("Sobrenome Completo: ");
        scanf(" %59[^\n]", conta_atual->Sobrenome);
        limpar_buffer_entrada();

        printf("Data de Nascimento (DD MM AAAA): ");
        scanf("%d %d %d", &conta_atual->Dia, &conta_atual->Mes, &conta_atual->Ano);
        limpar_buffer_entrada();

        do{
            printf("CPF (Somente numeros): ");
            scanf("%11s", conta_atual->Cpf);
            limpar_buffer_entrada();

            if(cpf_existe(conta_atual -> Cpf, nova, *total_contas)){
                printf("Erro: CPF invalido! Tente novamente.\n");
                cpf_invalido = 1;
            }else{
                cpf_invalido = 0;
            }

        }while(cpf_invalido);
        

        //endereço
        printf("Endereço (Ex: Rua Limoeiro): ");
        scanf(" %59[^\n]", conta_atual -> Endereco);
        limpar_buffer_entrada();

        printf("Cidade: ");
        scanf(" %19[^\n]", conta_atual -> Cidade);
        limpar_buffer_entrada();

        printf("Numero da casa: ");
        scanf("%d", &conta_atual -> Numerodacasa);
        limpar_buffer_entrada();

        //dados da conta
        printf("Senha (maximo 9 caracteres, sem espaços): ");
        scanf("%9s", conta_atual -> Senha);
        limpar_buffer_entrada();	

        strcpy(conta_atual -> Agencia, "0001"); //agencia padrao
        printf("Agência: 0001(padrão)\n");

        do{
            printf("Numero da Conta (Ex: 12345): ");
            scanf("%d", &conta_atual -> Conta);
            limpar_buffer_entrada();

            if(conta_existe(conta_atual -> Conta, nova, *total_contas)){
                printf("Erro: Numero de conta invalido! Tente novamente.\n");
                conta_invalida = 1;
            }else{
                conta_invalida = 0;
            }
        }while(conta_invalida);

        printf("Numero da sua conta: %s %d\n",conta_atual->Agencia, conta_atual -> Conta);
        
        printf("\nTem certeza que as informações estão corretas? (sim=1/não=0): ");
        scanf("%d", &resposta);
        limpar_buffer_entrada();

    }while(resposta == 0);

    salvar_contas_sem_arquivo(conta_atual);	
    (*total_contas)++;

    printf("\nConta criada com sucesso!\n");
}
