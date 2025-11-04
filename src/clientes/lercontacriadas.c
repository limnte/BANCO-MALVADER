#include <stdio.h>
#include <stdlib.h>
#include "io.h"

void ler_contas(Conta nova[], int *total_contas){
    *total_contas = 0;
    FILE *fbancoucb;
    fbancoucb = fopen("data/clientes.txt", "r");

    if(fbancoucb == NULL){
        printf("Erro ao abrir o arquivo de contas:Arquivo não encontrado.\n");
        system("pause");
        getchar();
        exit(1);
    }

    while(fscanf(fbancoucb, "%s %s %d %d %d %s %s %s %d %s %s %d\n",
		nova[*total_contas].Nome,
		nova[*total_contas].Sobrenome,
		&nova[*total_contas].Dia,
		&nova[*total_contas].Mes,
		&nova[*total_contas].Ano,
		nova[*total_contas].Cpf,
		nova[*total_contas].Endereco,
		nova[*total_contas].Cidade,
		&nova[*total_contas].Numerodacasa,
		nova[*total_contas].Senha,
		nova[*total_contas].Agencia,
		&nova[*total_contas].Conta)==13)
	{
	(*total_contas)++;
	}
	fclose(fbancoucb);
    return;
}