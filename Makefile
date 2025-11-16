CC = gcc
CFLAGS = -Wall -I./src -I./src/menus -I./src/clientes -I./src/operacoes -I./src/gerenciamento
SRC = $(wildcard src/*.c src/menus/*.c src/clientes/*.c src/operacoes/*.c src/gerenciamento/*.c)
OBJ = $(SRC:.c=.o)
EXEC = programa

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

