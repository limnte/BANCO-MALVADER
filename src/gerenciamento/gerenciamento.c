#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciamento.h"
#include "clientes/io.h"
#include "menus/menu.h"
#include <locale.h>
#include <string.h>
#include "operacoes/quicksort.h"
#include <time.h>
#include <ctype.h>

static int tudo_digito(const char* str){
    for(int i = 0; str[i]!= '\0'; i++){
        if(!isdigit(str[i])){
            return 0; //Se econtrar algo que não é digito numerico, retorna falso
        }
    }
    return 1;
}

void consultar_dados(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    Conta* logada = &nova[i_contalogada];

    printf("\n====== Consulta de dados =======\n");   
    printf("Nome: %s %s\n", logada->Nome, logada->Sobrenome);
    printf("CPF: %.3s.%.3s.%.3s-%.2s\n", logada->Cpf, logada->Cpf+3, logada->Cpf+6,logada->Cpf+9); //mostrar o cpf formatodo
    printf("Data de nascimento: %02d/%02d/%02d\n", logada->Dia, logada->Mes, logada->Ano);
    printf("Conta: %s-%d\n", logada ->Agencia, logada->Conta);

    printf("\n====== Endereço ======\n");
    printf("Endereço: %s\n", logada->Endereco);
    printf("Numero: %d\n", logada->Numerodacasa);
    printf("Cidade: %s\n", logada->Cidade);
    printf("CEP: %.5s-%.3s\n", logada->Cep, logada -> Cep + 5);//mostra o cep formatado
}

void alterar_dados(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    Conta *logada = &nova[i_contalogada];
    int op;
    int dados_alterados = 0; //flag
    char buffer_temp[30];
    int cep_invalido;

    do{
        limpar_tela();
        header();

        printf("\n======Alteração de Dados======\n");
        printf("Qual dado deseja alterar?\n");
        printf("1 - Endereço\n");
        printf("2 - Senha\n");
        printf("0 - Voltar\n");
        printf("Escolha: ");
        scanf("%d",&op);
        limpar_buffer_entrada();

        switch(op){
            case 1:
                printf("\nNovo endereço: ");
                scanf(" %59[^\n]", logada->Endereco);
                limpar_buffer_entrada();

                printf("\nNumero da casa: ");
                scanf("%d",&logada->Numerodacasa);
                limpar_buffer_entrada();

                printf("\nCidade: ");
                scanf(" %19[^\n]",logada->Cidade);
                limpar_buffer_entrada();

                do{
                    printf("\nCEP(somente 8 numeros): ");
                    scanf(" %8s", buffer_temp);
                    limpar_buffer_entrada();

                    if(strlen(buffer_temp) != 8 || !tudo_digito(buffer_temp)){
                        printf("Erro: O CEP deve conter 8 digitos. Tente novamente!");
                        cep_invalido = 1;
                    }else{
                        cep_invalido = 0;
                        strcpy(logada->Cep, buffer_temp); //salva o Cep valido na conta logada.
                    }


                }while(cep_invalido);
                

                dados_alterados = 1;
                break;
            case 2:
                printf("Nova Senha (max 9 caracteres): ");
                scanf(" %9s", logada->Senha);
                limpar_buffer_entrada();

                dados_alterados = 1;
                break;
            case 0:
                break;
            default:
                printf("Opção invalida!\n");
        }
    } while(op!=0);

    if(dados_alterados){
        salvar_todas_contas(nova, total_contas);
        printf("\nDados alterados e salvos com sucesso!");
    }else{
        printf("Nenhuma alteração realizada.\n");
    }
}

void excluir_conta(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    Conta* logada = &nova[i_contalogada];
    char confirmar_senha[10];
    int op;

    printf("\n======Excluir Conta======\n");

    if(logada->Saldo > 0.1){
        printf("Erro: Não é possivel excluir uma conta com saldo maior que R$0.1\n");
        printf("Por favor, saque todo o valor antes de excluir a conta.\n");
        return;
    }

    printf("ATENÇÃO: essa ação é irreversível.\n");
    printf("Tem certeza que deseja continuar? (sim=1/não=0): ");
    scanf("%d", &op);

    switch(op){
        case 1:
            printf("\nDigite sua senha: ");
            scanf("%9s", confirmar_senha);

            if(strcmp(logada->Senha, confirmar_senha) != 0){
                printf("Senha incorreta.\n");
                return;
            }

            for(int i = i_contalogada; i<total_contas - 1; i++){
                nova[i] = nova[i+1];
            }

            total_contas--;
            salvar_todas_contas(nova, total_contas);
            printf("Conta excluida com sucesso.\n");

            i_contalogada=-1;
        case 0:
            return;
        default:
            printf("Opção invalida!\n");
    }

}

void listar_contas_por_nome(){
    Conta copia_contas[200];
    memcpy(copia_contas, nova, total_contas *sizeof(Conta));

    quicksort_nome(copia_contas, 0, total_contas - 1);

    printf("\n======Lista de Contas (Ordenadas por Nome)======\n");
    printf("Total de contas: %d\n", total_contas);
    printf("----------------------------------------------\n");
    printf("%-20s | %s-%s\n","Nome","Agencia","Conta");
    printf("----------------------------------------------\n");

    for(int i = 0; i < total_contas; i++){
        printf("%-20s | %s-%d\n",
                copia_contas[i].Nome,
                copia_contas[i].Agencia,
                copia_contas[i].Conta);
    }
    printf("----------------------------------------------\n");
}

void listar_contas_por_conta() {
    Conta copia_contas[200];
    memcpy(copia_contas, nova, total_contas * sizeof(Conta));

    quicksort_conta(copia_contas, 0, total_contas - 1);

    printf("\n======Lista de Contas (Ordenada por Conta)======");
    printf("Total de contas: %d\n", total_contas);
    printf("----------------------------------------------\n");
    printf("%-10s | %-20s\n", "Conta", "Nome");
    printf("----------------------------------------------\n");
    for (int i = 0; i < total_contas; i++) {
        printf("%-10d | %-20s\n", 
               copia_contas[i].Conta, 
               copia_contas[i].Nome);
    }
    printf("----------------------------------------------\n");
}

void salvar_operacao(const char *cpf, const char *tipo, double valor) {
    char caminho[200];
    sprintf(caminho, "data/op_%s.bin", cpf);

    FILE *fp = fopen(caminho, "ab");
    if (!fp) {
        printf("Erro ao abrir arquivo de operações.\n");
        return;
    }

    Operacao op;
    strcpy(op.tipo, tipo);
    op.valor = valor;

    // gerar data e hora
    time_t agora = time(NULL);
    struct tm *t = localtime(&agora);
    strftime(op.data, sizeof(op.data), "%d/%m/%Y %H:%M", t);

    fwrite(&op, sizeof(Operacao), 1, fp);
    fclose(fp);
}

void mostrar_extrato() {
    const char *cpf = nova[i_contalogada].Cpf;


    char caminho[200];
    sprintf(caminho, "data/op_%s.bin", cpf);

    FILE *fp = fopen(caminho, "rb");
    if (!fp) {
        printf("\nNenhuma operação encontrada.\n");
        return;
    }

    Operacao ops[500];
    int total = 0;

    while (fread(&ops[total], sizeof(Operacao), 1, fp) == 1) {
        total++;
    }
    fclose(fp);

    if (total == 0) {
        printf("\nNenhuma operação registrada.\n");
        return;
    }

    printf("\n===== EXTRATO (Últimas 5 operações) =====\n");

    int inicio = (total > 5 ? total - 5 : 0);

    for (int i = inicio; i < total; i++) {
        printf("%s | %-14s | R$ %.2lf\n",
            ops[i].data,
            ops[i].tipo,
            ops[i].valor
        );
    }

    printf("==========================================\n");
}