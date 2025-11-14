#include <stdlib.h>
#include <stdio.h>
#include "io.h"
#include <string.h>
#include "menus/menu.h"


int cpf_existe(const char *cpf, const Conta nova[], int total_contas){
    for(int i = 0; i < total_contas; i++){
        if(strcmp(nova[i].Cpf, cpf) == 0){
            return 1; // CPF encontrado
        }
    }
    return 0; // CPF não encontrado
}

int conta_existe(int numero_conta, const Conta nova[], int total_contas){
    for(int i = 0; i < total_contas; i++){
        if(nova[i].Conta == numero_conta){
            return 1; // Conta encontrada
        }
    }
    return 0; // Conta não encontrada
}

int fazer_login(const Conta nova[], int total_contas){
    char cpf_tentativa[20];
    char senha_tentativa[10];

    printf("\n=== Login ===\n");
    printf("CPF (Apenas numeros): ");
    scanf("%11s", cpf_tentativa);
    limpar_buffer_entrada();

    printf("Senha: ");
    scanf("%9s", senha_tentativa);
    limpar_buffer_entrada();

    //compara cpf e senha com todas as contas
    for(int i = 0; i < total_contas; i++){
        if(strcmp(nova[i].Cpf, cpf_tentativa) == 0 && strcmp(nova[i].Senha, senha_tentativa) == 0){
            return i; // Retorna o índice da conta logada
        }
    }

    printf("\nCPF ou senha incorretos.\n");
    pausar_tela();
    
    return -1; // Login falhou
}


