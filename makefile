CC = gcc
INC = -I./inc

all: folder server client 

server: calculadora.o server.o
	$(CC) obj/calculadora.o obj/server.o -o APP/server.bin

client: client.o
	$(CC) obj/client.o -o APP/client.bin

calculadora.o:
	$(CC) -o calculadora.o -c $(INC) src/calculadora.c -o obj/calculadora.o

server.o:
	$(CC) -o server.o -c $(INC) src/server.c -o obj/server.o

client.o:
	$(CC) -o client.o -c $(INC) src/client.c -o obj/client.o 

folder: 
	mkdir -p obj APP

clean:
	rm -rf obj APP