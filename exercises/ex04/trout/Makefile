
trout: trout.o main.o util.o
	gcc -g -Wall trout.o main.o util.o -o trout

trout.o: trout.c trout.h
	gcc -c trout.c

util.o: util.c util.h
	gcc -c util.c

main.o: main.c util.h trout.h
	gcc -c main.c
