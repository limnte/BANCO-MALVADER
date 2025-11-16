# 🏦 Projeto Banco Malvader

Simulador de sistema bancário simples escrito em C, como projeto acadêmico. O programa simula as operações básicas de um caixa eletrônico, com foco em modularização, gerenciamento de memória e persistência de dados.

[cite_start]O projeto cumpre os requisitos de alocação dinâmica [cite: 13] (usando `malloc`/`realloc` para um vetor de contas) [cite_start]e persistência em arquivos [cite: 18] (salvando contas em `clientes.txt` e extratos em arquivos `.bin` individuais).

## 🚀 Funcionalidades Principais

* **Autenticação:** Login seguro por CPF e Senha.
* **Gerenciamento de Contas:** Criação, consulta, alteração e exclusão de contas de clientes.
* **Operações Financeiras:** Depósito, Saque e Transferência entre contas.
* **Consultas:** Saldo, extrato de operações e listagem de todos os clientes.
* [cite_start]**Ordenação:** A listagem de clientes é ordenada usando um **Quicksort** implementado manualmente[cite: 15, 122].
* **Validação:** Validação de formato para CPF (11 dígitos) e CEP (8 dígitos).

## ⚙️ Como Compilar e Executar

Este projeto usa `make` para compilação.

```bash
# 1. Compilar o programa
make

# 2. abrir programa
start programa.exe no windows ou ./programa no macOS/Linux