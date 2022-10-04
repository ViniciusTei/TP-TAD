#Nome do programa
TARGET = app

#diretorios dos arquivos
SRC = .
OBJ = ./obj
BIN = ./bin

#compilador
CC = gcc

OBJS =	main.o DICIONARIO.o Letra.o lista_de_palavra.o nLinhas.o palavra.o

all: $(OBJS)
	$(CC) $(OBJ)/*.o -o $(BIN)/$(TARGET)

main.o: $(SRC)/main.c
	$(CC) -c $(SRC)/main.c -o $(OBJ)/main.o

DICIONARIO.o: $(SRC)/DICIONARIO.c
	$(CC) -c $(SRC)/DICIONARIO.c -o $(OBJ)/DICIONARIO.o

Letra.o: $(SRC)/Letra.c
	$(CC) -c $(SRC)/Letra.c -o $(OBJ)/Letra.o

lista_de_palavra.o: $(SRC)/lista_de_palavra.c
	$(CC) -c $(SRC)/lista_de_palavra.c -o $(OBJ)/lista_de_palavra.o

nLinhas.o: $(SRC)/nLinhas.c
	$(CC) -c $(SRC)/nLinhas.c -o $(OBJ)/nLinhas.o

palavra.o: $(SRC)/palavra.c
	$(CC) -c $(SRC)/palavra.c -o $(OBJ)/palavra.o

run:
	$(BIN)/$(TARGET)

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*