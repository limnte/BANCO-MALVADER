#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define arquivo_clientes "data/clientes.txt"
#define arquivo_movimentos "data/movimentos.txt"
#include "menus/menu.h"
#include "clientes/io.h"
#include "clientes/verificacao.h"

Conta *nova = NULL; //ponteiro, começa como null
int capacidade_contas = 0;
int total_contas = 0; //declaração da variavel global de total de contas
int i_contalogada = -1; //variavel global que guarda o indice da conta logada, -1 = ninguem estiver logado

void liberar_memoria(){
    free(nova);
    nova = NULL;
}

void loop_menu_principal(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int op;

    do{
        limpar_tela();
        header();
        op = menu_principal();

        switch(op){
            case 1:
                submenu_gerenciar();
                break;
            case 2:
                submenu_consultas();
                break;
            case 3:
                submenu_operacoes();
                break;
            case 0:
                printf("Fazendo logout...\n");
                i_contalogada = -1;
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                pausar_tela();
        }

        if (i_contalogada == -1) op = 0;

    }while(op != 0);
}

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int op_inicial;

    //Bloco de alocação de memoria
    capacidade_contas = 10; //começa com espaço para 10 contas.
    nova = (Conta*) malloc(capacidade_contas*sizeof(Conta));
    if(nova==NULL){
        printf("ERRO FATAL: Falha ao alocar memoria.\n");
        return 1; //termina o programa se não houver memoria.
    }


    ler_contas(&total_contas);//carrega as contas ao inciar o programa
    
    do{
        limpar_tela();
        header();
        op_inicial = menu_inicial();

        switch(op_inicial){
            case 1:
                i_contalogada = fazer_login(nova, total_contas);

                if(i_contalogada != -1){
                    printf("Login realizado com sucesso! Bem-vindo, %s.\n", nova[i_contalogada].Nome);
                    pausar_tela();
                    loop_menu_principal();
                }
                break;
            case 2:
                criar_conta(&total_contas);
                pausar_tela();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                pausar_tela();
        }
    }while(op_inicial != 0);

    liberar_memoria();

    return 0;
}

