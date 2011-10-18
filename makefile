CC = gcc
RM = rm

ejecutables: lista.o nodo.o 
	$(CC) -o lista lista.o nodo.o


procesos.o: lista.c
	$(CC) -c lista.c lista.h

lector.o: nodo.c nodo.h
	$(CC) -c nodo.c

clean:
	$(RM) *.o   lista
