#include <stdio.h>
#include <locale.h>
#include "io.h"
#include <string.h>
#include <stdlib.h>
#include "verificacao.h"
#include "menus/menu.h"
#include <ctype.h>

static int tudo_digito(const char* str){
    for(int i = 0; str[i]!= '\0'; i++){
        if(!isdigit(str[i])){
            return 0; //Se econtrar algo que não é digito numerico, retorna falso
        }
    }
    return 1;
}



void criar_conta(int *total_contas){
    setlocale(LC_ALL, "pt_BR.UTF-8");

	int resposta;
    int cpf_invalido = 0;
    int conta_invalida = 0;
    char buffer_temp[30];//buffer temporario pra validar

    // --- BLOCO DE VERIFICAÇÃO DE CAPACIDADE ---
    if (*total_contas >= capacidade_contas) {
        int nova_capacidade = (capacidade_contas == 0) ? 10 : capacidade_contas * 2;
        Conta *temp = (Conta*) realloc(nova, nova_capacidade * sizeof(Conta));

        if (temp == NULL) {
            printf("Erro: Nao ha mais memoria para cadastrar novas contas!\n");
            return; // Aborta a criação da conta
        }
        nova = temp; // Atualiza o ponteiro global
        capacidade_contas = nova_capacidade;
    }

    Conta *conta_atual = &nova[*total_contas]; //ponteiro do proximo slot livre

    do{
        //dados pessoais
        printf("\n=== Criacao de Nova Conta ===\n");
        printf("Por favor, preencha os dados abaixo:\n\n");

        printf("Primeiro nome: ");   
        scanf(" %19[^\n]", conta_atual->Nome);
        limpar_buffer_entrada();	

        printf("Sobrenome Completo: ");
        scanf(" %59[^\n]", conta_atual->Sobrenome);
        limpar_buffer_entrada();

        printf("Data de Nascimento (DD MM AAAA): ");
        scanf("%d %d %d", &conta_atual->Dia, &conta_atual->Mes, &conta_atual->Ano);
        limpar_buffer_entrada();

        do{
            printf("CPF (Somente numeros): ");
            scanf("%11s", buffer_temp); //ler no buffer temporario
            limpar_buffer_entrada();

            if(strlen(buffer_temp) != 11 || !tudo_digito(buffer_temp)){
                printf("Erro: O CPF deve conter todos os 11 digitos numericos!.\n");
                cpf_invalido = 1; //verifica se o cpf tem os 11 digitos ou algo que não seja numerico
            }else if(cpf_existe(buffer_temp, nova, *total_contas)){
                printf("Erro: CPF invalido! Tente novamente.\n");
                cpf_invalido = 1; //verifica se o cpf já existe
            }else{
                cpf_invalido = 0;
                strcpy(conta_atual->Cpf, buffer_temp); //copia o cpf se for valido
            }

        }while(cpf_invalido);
        

        //endereço
        printf("Endereço (Ex: Rua Limoeiro): ");
        scanf(" %59[^\n]", conta_atual -> Endereco);
        limpar_buffer_entrada();

        printf("Cidade: ");
        scanf(" %19[^\n]", conta_atual -> Cidade);
        limpar_buffer_entrada();

        printf("Numero da casa: ");
        scanf("%d", &conta_atual -> Numerodacasa);
        limpar_buffer_entrada();

        int cep_invalido;
        do{
            printf("CEP(Somente 8 numeros): ");
            scanf("%8s", buffer_temp);
            limpar_buffer_entrada();

            if(strlen(buffer_temp) != 8 || !tudo_digito(buffer_temp)){
                printf("Erro: o CEP deve conter exatemente 8 digitos numericos. Tente novamente!\n");
                cep_invalido = 1;
            }else{
                cep_invalido = 0;
                strcpy(conta_atual->Cep, buffer_temp); //copia o cep se for valido
            }

        }while(cep_invalido);
        

        //dados da conta
        printf("Senha (maximo 9 caracteres, sem espaços): ");
        scanf("%9s", conta_atual -> Senha);
        limpar_buffer_entrada();	

        strcpy(conta_atual -> Agencia, "0001"); //agencia padrao
        printf("Agência: 0001(padrão)\n");

        do{
            printf("Numero da Conta (Ex: 12345): ");
            scanf("%d", &conta_atual -> Conta);
            limpar_buffer_entrada();

            if(conta_existe(conta_atual -> Conta, nova, *total_contas)){
                printf("Erro: Numero de conta invalido! Tente novamente.\n");
                conta_invalida = 1;
            }else{
                conta_invalida = 0;
            }
        }while(conta_invalida);

        printf("Numero da sua conta: %s %d\n",conta_atual->Agencia, conta_atual -> Conta);
        
        printf("\nTem certeza que as informações estão corretas? (sim=1/não=0): ");
        int confirmar = scanf("%d", &resposta);
        limpar_buffer_entrada();

        //loop de validação pra não permitir algo diferente de 1 e 0
        while(confirmar != 1 || (resposta != 0 && resposta != 1)){
            printf("Erro: Opção invalida.\n");
            confirmar = scanf("%d", &resposta);
            limpar_buffer_entrada();
        }

        if(resposta == 0){
            printf("\n--- ATENÇÃO: Os dados serão solicitados noamente. ---\n\n");
        }

    }while(resposta == 0);

    conta_atual -> Saldo = 0.0;
    
    salvar_contas_sem_arquivo(conta_atual);	
    (*total_contas)++;

    printf("\nConta criada com sucesso!\n");
}
