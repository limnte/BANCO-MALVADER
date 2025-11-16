#ifndef GERENCIAMENTO_H
#define GERENCIAMENTO_H

typedef struct {
    char tipo[20];
    double valor;
    char data[20];
} Operacao;

//Salva dados da operação de extrato
void salvar_operacao(const char *cpf, const char *tipo, double valor);
//lê dados do arquivo bin criado e mostra no terminal
void mostrar_extrato();

//Consulta dados da conta logada
void consultar_dados();

//altera dados da conta do usuario logado
void alterar_dados();

//Exclui a conta do usuario logado, exclusão falha se saldo >=0.1, caso sucesso, força logout.
void excluir_conta();

//Cria uma copia do vetor de contas e ordena por ordem alfabetico dos nomes
void listar_contas_por_nome();
//Cria uma copia do vetor de contas e ordena por NUMERO de conta em ordem crescente
void listar_contas_por_conta();

#endif