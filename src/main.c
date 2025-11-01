#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define arquivo_clientes "data/clientes.txt"
#define arquivo_movimentos "data/movimentos.txt"
#include "menus/menu.h"

//quando forem mudar alguma coisa, deixem organizado, por favor...
//Deixe o mais modular possível e quando for criar variaves/funçoes/registros, use nomes faceis de entender.
//atenção nas instruções de cada função, para evitar bugs futuros. e olhem a pagina 5 e 6 do documento do trabalho.
//Quando mudarem alguma coisa, comentem o que foi mudado e coloque seu nome. ESPECIALMENTE SE CRIAR PASTAS NOVAS

int main(void){
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
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                system("pause");
        }

    }while(op != 0);

    return 0;
}

//pra compilar com todos os arquivos, use: Ctrl + j e escreva make lembre-se de baixar o https://sourceforge.net/projects/gnuwin32 se ainda não tiver o make instalado.
//para rodar o programa, use: Ctrl + j e escreva programa.exe ou va no diretorio no seu explorador de arquivos e clique duas vezes no programa.exe