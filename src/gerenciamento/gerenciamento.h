#ifndef GERENCIAMENTO_H
#define GERENCIAMENTO_H

typedef struct {
    char tipo[20];
    double valor;
    char data[20];
} Operacao;

void salvar_operacao(const char *cpf, const char *tipo, double valor);
void mostrar_extrato();

void consultar_dados();
void alterar_dados();
void excluir_conta();

void listar_contas_por_nome();
void listar_contas_por_conta();

#endif