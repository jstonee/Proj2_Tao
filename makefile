proj2: proj2.o
	gcc proj2.o -g -o proj2
proj2.o: proj2.c

exec:
	./proj2 data.c data.out