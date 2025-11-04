#ifndef IO_H
#define IO_H

typedef struct{
    char Nome[20];
	char Sobrenome[20];
	char Endereco[60];
	char Cidade[20];
	char Cpf[20];
	char Senha[10];
	char Agencia[10];
	int Dia;
	int Mes;
	int Ano;
	int Conta;
	int Cep;
	int Numerodacasa;
}Conta;

extern Conta nova[200];
extern int total_contas;

void criar_conta(Conta *nova, int *total_contas);
void ler_contas(Conta *nova, int *total_contas);
void salvar_contas_sem_arquivo(Conta *nova);

#endif