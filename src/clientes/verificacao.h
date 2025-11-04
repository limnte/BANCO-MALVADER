#ifndef VERIFICACAO_H
#define VERIFICACAO_H
#include "io.h"

int cpf_existe(const char *cpf, const Conta nova[], int total_contas);
int conta_existe(int numero_conta, const Conta nova[], int total_contas);
int fazer_login(const Conta nova[], int total_contas);

#endif