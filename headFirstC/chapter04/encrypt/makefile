CFLAGS=-Wall -g

encrypt.o: encrypt.h encrypt.c
	gcc -c encrypt.c

dataFileHider.o: dataFileHider.c encrypt.h
	gcc -c dataFileHider.c

dataFileHider: encrypt.o dataFileHider.o
	gcc encrypt.o dataFileHider.o -o dataFileHider
