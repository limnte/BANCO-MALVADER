#ifndef IO_H
#define IO_H

typedef struct{
    char Nome[20];
	char Sobrenome[60];
	char Endereco[60];
	char Cidade[20];
	char Cpf[12];
	char Senha[10];
	char Agencia[10];
	int Dia;
	int Mes;
	int Ano;
	int Conta;
	char Cep[9];
	int Numerodacasa;
	double Saldo;
}Conta;

extern Conta nova[200];
extern int total_contas;
extern int i_contalogada;

void criar_conta(Conta *nova, int *total_contas);
void ler_contas(Conta *nova, int *total_contas);
void salvar_contas_sem_arquivo(Conta *nova);
void salvar_todas_contas(Conta nova[], int total_contas);

#endif