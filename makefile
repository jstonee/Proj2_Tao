proj2: proj2.o
	gcc proj2.c list.c queue.c -g -o proj2
proj2.o: proj2.c
exec: 
	./proj2 date.c date.out