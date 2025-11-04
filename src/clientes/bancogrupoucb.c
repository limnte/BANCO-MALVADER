#include <stdio.h>
#include "io.h"
#include <string.h>

void criar_conta(Conta nova[], int *total_contas){
	int operacoes;
	int dia, mes, ano;

	printf("\ndigite o primeiro nome do usuario:");   
	scanf(" %[^\n]", nova[*total_contas].Nome);	
	printf("\ndigite o sobrenome completo do usuario:");
	scanf(" %[^\n]", nova[*total_contas].Sobrenome);
	printf("digite o dia, mes e ano do usuario, nessa ordem!!");
	scanf("%d %d %d", &nova[*total_contas].Dia, &nova[*total_contas].Mes, &nova[*total_contas].Ano);
	dia=nova[*total_contas].Dia;
	mes=nova[*total_contas].Mes;
	ano=nova[*total_contas].Ano;
	printf("data %d/%d/%d",dia, mes, ano);
	printf("\ndigite o cpf do usuario:");
	scanf("%s", nova[*total_contas].Cpf);
	printf("\ndigite o endereço do usuario:");
	scanf(" %[^\n]", nova[*total_contas].Endereco);
	printf("\ndigite a cidade do usuario:");
	scanf(" %[^\n]", nova[*total_contas].Cidade);
	printf("\ndigite o numero da casa do usuario:");
	scanf("%d", &nova[*total_contas].Numerodacasa);
	printf("\nagora digite uma senha para o usuario:");
	scanf("%s", nova[*total_contas].Senha);		
	printf("\nagencias são padrão, 0001; digite 1 para confirmar.");
	scanf("%d", &operacoes);
	if(operacoes==1){
	strcpy(nova[*total_contas].Agencia, "0001");
	printf("\nCONCLUIDO!!");
	printf("\npara finalizar o cadastro, digite uma conta disponivel para o usuario:");
	scanf("%d", &nova[*total_contas].Conta);
	}
	else{
		printf("opcao invalida!!");
	}

	salvar_contas_sem_arquivo(&nova[*total_contas]);	
	(*total_contas)++;
}
