#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include <locale.h>

void ler_contas(int *total_contas){
    setlocale(LC_ALL, "pt_BR.UTF-8");
	*total_contas = 0; //zera o contador
    FILE *fbancoucb;
    fbancoucb = fopen("data/clientes.txt", "r");
	

    if(fbancoucb == NULL){
        return;
    }

    
    while(1){
		//garante que existe espaço para a proxima conota
		if(*total_contas>=capacidade_contas){
			//Se atingir o limite dobra a capacidade. inicia com 10 se for 0
			int nova_capacidade = (capacidade_contas == 0) ? 10 : capacidade_contas * 2;
			Conta *temp = (Conta*) realloc(nova, nova_capacidade * sizeof(Conta));

			//Se falha na alocação
			if(temp == NULL){
				printf("ERRO FATAL: Falha ao realocar memoria durante leitura.\n");
				liberar_memoria();
				exit(1);
			}

			nova = temp; //atualiza ponteiro global
			capacidade_contas = nova_capacidade;
		}

		//lidas com %[^|] para ler até o caractere '|'
		int resultado = fscanf(fbancoucb, " %[^|]|%[^|]|%d|%d|%d|%[^|]|%[^|]|%[^|]|%d|%[^|]|%[^|]|%[^|]|%d|%lf",
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
			&nova[*total_contas].Saldo);

		if (resultado != 14){
			break;
		}

		//se sucesso, incrementa o total.
		(*total_contas)++;

	}

	fclose(fbancoucb);
    return;
}