#ifndef MENU_H
#define MENU_H

void limpar_tela();
void header();
void limpar_buffer_entrada();
void pausar_tela();

int menu_inicial();

int menu_principal();
int menu_gerenciar();
int menu_consultas();
int menu_operacoes();

void submenu_gerenciar();
void submenu_consultas();
void submenu_operacoes();

#endif