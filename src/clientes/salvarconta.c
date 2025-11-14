#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include <locale.h>
#include "menus/menu.h"

void salvar_contas_sem_arquivo(Conta *nova){
    FILE *fbancoucb;
    fbancoucb = fopen("data/clientes.txt", "a");

    if(fbancoucb == NULL){
		setlocale(LC_ALL, "pt_BR.UTF-8");
        printf("Erro ao abrir o arquivo de contas:Arquivo não encontrado.\n");
        pausar_tela();
        getchar();
        exit(1);
    }

    fprintf(fbancoucb, "%s|%s|%d|%d|%d|%s|%s|%s|%d|%s|%s|%s|%d|%lf\n",
		nova->Nome,
		nova->Sobrenome,
		nova->Dia,
		nova->Mes,
		nova->Ano,
		nova->Cpf,
		nova->Endereco,
		nova->Cidade,
		nova->Numerodacasa,
		nova->Cep,
		nova->Senha,
		nova->Agencia,
		nova->Conta,
		nova->Saldo);	

    fclose(fbancoucb);
}

void salvar_todas_contas(){
	setlocale(LC_ALL, "pt_BR.UTF-8");
	FILE *fbancoucb;
	fbancoucb = fopen("data/clientes.txt", "w");

	if(fbancoucb == NULL){
		printf("ERRO CRITICO: não foi possivel re-salvar os dados das contas.\n");
		pausar_tela();
		return;
	}

	//loop nas contas da memoria e salvar elas e pah
	for(int i = 0; i < total_contas; i++){
		fprintf(fbancoucb, "%s|%s|%d|%d|%d|%s|%s|%s|%d|%s|%s|%s|%d|%lf\n",
			nova[i].Nome,
			nova[i].Sobrenome,
			nova[i].Dia,
			nova[i].Mes,
			nova[i].Ano,
			nova[i].Cpf,
			nova[i].Endereco,
			nova[i].Cidade,
			nova[i].Numerodacasa,
			nova[i].Cep,
			nova[i].Senha,
			nova[i].Agencia,
			nova[i].Conta,
			nova[i].Saldo);
	}

	fclose(fbancoucb);
}