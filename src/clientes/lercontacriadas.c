#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include <locale.h>

void ler_contas(Conta nova[], int *total_contas){
    setlocale(LC_ALL, "pt_BR.UTF-8");
	*total_contas = 0;
    FILE *fbancoucb;
    fbancoucb = fopen("data/clientes.txt", "r");
	

    if(fbancoucb == NULL){
        return;
    }

    //As strings estão sendo lidas com %[^|] para ler até o caractere '|', evitar problemas com espaços e garbage data
    while(fscanf(fbancoucb, " %[^|]|%[^|]|%d|%d|%d|%[^|]|%[^|]|%[^|]|%d|%[^|]|%[^|]|%[^|]|%d|%lf",
		nova[*total_contas].Nome,
		nova[*total_contas].Sobrenome,
		&nova[*total_contas].Dia,
		&nova[*total_contas].Mes,
		&nova[*total_contas].Ano,
		nova[*total_contas].Cpf,
		nova[*total_contas].Endereco,
		nova[*total_contas].Cidade,
		&nova[*total_contas].Numerodacasa,
		nova[*total_contas].Cep,
		nova[*total_contas].Senha,
		nova[*total_contas].Agencia,
		&nova[*total_contas].Conta,
		&nova[*total_contas].Saldo) == 14)
	{
	(*total_contas)++;
	}
	fclose(fbancoucb);
    return;
}