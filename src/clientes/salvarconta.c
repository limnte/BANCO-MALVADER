#include <stdio.h>
#include <stdlib.h>
#include "io.h"

void salvar_contas_sem_arquivo(Conta *nova){
    FILE *fbancoucb;
    fbancoucb = fopen("data/clientes.txt", "a");

    if(fbancoucb == NULL){
        printf("Erro ao abrir o arquivo de contas:Arquivo não encontrado.\n");
        system("pause");
        getchar();
        exit(1);
    }

    fprintf(fbancoucb,  "%s|%s|%d|%d|%d|%s|%s|%s|%d|%s|%s|%d\n",
		nova->Nome,
		nova->Sobrenome,
		nova->Dia,
		nova->Mes,
		nova->Ano,
		nova->Cpf,
		nova->Endereco,
		nova->Cidade,
		nova->Numerodacasa,
		nova->Senha,
		nova->Agencia,
		nova->Conta);	

    fclose(fbancoucb);
}