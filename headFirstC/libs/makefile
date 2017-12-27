hfcal.o: hfcal.c
	gcc -Wall -g -I../includes -fPIC -c hfcal.c -o hfcal.o

libhfcal.a: hfcal.o
	ar -rcs ./libhfcal.a hfcal.o

libhfcal.so: hfcal.o
	gcc -shared hfcal.o -o libhfcal.so
