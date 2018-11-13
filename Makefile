# Write this Makefile

myas: trans.o check.o main.o
	gcc -o myas trans.o check.o main.o

trans.o: trans.c
	gcc -c trans.c

check.o: check.c
	gcc -c check.c

main.o: main.c
	gcc -c main.c


