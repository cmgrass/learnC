elliptical.o: elliptical.c
	gcc -Wall -g -I../../includes -c elliptical.c -o elliptical.o

elliptical: elliptical.o
	gcc elliptical.o -L../../libs -lhfcal -o elliptical
