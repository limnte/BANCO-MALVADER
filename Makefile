CC = gcc
CFLAGS = -Wall -I./src -I./src/menus -I./src/clientes
SRC = $(wildcard src/*.c src/menus/*.c src/clientes/*.c)
OBJ = $(SRC:.c=.o)
EXEC = programa

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(SRC_DIR)\*.o $(MENU_DIR)\*.o $(OUT_DIR)\*.exe 2>nul || echo Nada para limpar.
