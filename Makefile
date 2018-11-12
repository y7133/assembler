# Write this Makefile
main.o: main.c
	gcc -c main.c
trans.o: trans.c 
	gcc -c trans.c
check.o: check.c
	gcc -c check.c
myas: main.o check.p trans.o
	gcc -o myas main.o check.o trans.o

