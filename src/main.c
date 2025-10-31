#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define arquivo_clientes "data/clients.txt"
#define arquivo_movimentos "data/movimentos.txt"

//quando forem mudar alguma coisa, deixem organizado, por favor...
//Deixe o mais modular possível e quando for criar variaves/funçoes/registros, use nomes faceis de entender.
//atenção nas instruções de cada função, para evitar bugs futuros. e olhem a pagina 5 e 6 do documento do trabalho.
//Quando mudarem alguma coisa, comentem o que foi mudado e coloque seu nome. 

static void header(){
    printf("===========================================================================\n");
    printf("  ____                          __  __       _                _           \n");
    printf(" |  _ \\                        |  \\/  |     | |              | |          \n");
    printf(" | |_) | __ _ _ __   ___ ___   | \\  / | __ _| |_   ____ _  __| | ___ _ __ \n");
    printf(" |  _ < / _` | '_ \\ / __/ _ \\  | |\\/| |/ _` | \\ \\ / / _` |/ _` |/ _ \\ '__|\n");
    printf(" | |_) | (_| | | | | (_| (_) | | |  | | (_| | |\\ V / (_| | (_| |  __/ |   \n");
    printf(" |____/ \\__,_|_| |_|\\___\\___/  |_|  |_|\\__,_|_| \\_/ \\__,_|\\__,_|\\___|_|   \n");
    printf("                                                                           \n");
    printf("===========================================================================\n");
}

//Menus, dividos em funções para melhor organização
int menu(){
    int op;

    printf("1 - Gerenciar conta\n");
    printf("2 - Consultas\n");
    printf("3 - Operações\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
    scanf("%d", &op);

    return op;
}

int menu1(){
    int op1;

    printf("1 - Abrir conta\n");
    printf("2 - Excluir conta\n");
    printf("3 - Alterar dados\n");
    printf("4 - Consultar dados\n");
    printf("0 - Voltar\n");
    printf("Escolha: ");
    scanf("%d", &op1);

    return op1;
}

int menu2(){
    int op2;

    printf("1 - Consultar saldo\n");
    printf("2 - Consultar dados\n");
    printf("3 - Listar por nome\n");
    printf("4 - Listar por conta\n");
    printf("0 - Voltar\n");
    printf("Escolha: ");
    scanf("%d", &op2);

    return op2;
}

int menu3(){
    int op3;

    printf("1 - Depósito\n");
    printf("2 - Saque\n");
    printf("3 - Transferência\n");
    printf("0 - Voltar\n");
    printf("Escolha: ");
    scanf("%d", &op3);

    return op3;
}


int main(void){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    for(;;){
        system("clear || cls");
        header();
        int op = menu();

        switch(op){
            case 1:
                system("clear || cls");
                header();
                menu1();
                break;
            case 2:
                system("clear || cls");
                header();
                menu2();
                break;
            case 3:
                system("clear || cls");
                header();
                menu3();
                break;
            case 0:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        printf("Pressione Enter para continuar...");
        while(getchar() != '\n'); // Limpa o buffer
        getchar(); // Espera o Enter

    }
}