# Write this Makefile

main.o:
	gcc -c main.c

trans.o:
	gcc -c trans.c

check.o:
	gcc -c check.c

myas:
	gcc -o myas main.o check.o trans.o
