#ifndef VERIFICACAO_H
#define VERIFICACAO_H
#include "io.h"

int cpf_existe(const char *cpf, const Conta nova[], int total_contas);//verifica se cpf já existe em todas as contas de nova[]
int conta_existe(int numero_conta, const Conta nova[], int total_contas);//Verifica se numero de conta já existe em todas as contas de nova[]
int fazer_login(const Conta nova[], int total_contas);//Compara cpf e senha com todas as contas de nova[]

#endif