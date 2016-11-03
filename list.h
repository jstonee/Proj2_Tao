#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define EMPTY 0

typedef char data;

struct node
{
	data	d;
	Queue*	lines;
	struct node* next;
};

typedef struct node node;

struct List
{
	int count;
	node *top;	
};
typedef struct List List;

bool isEmpty(const List* lst);
void init(List* lst);
void push(data d, int num, List* lst);
void empty(List* lst);
void sort(List* lst);
void printList(FILE *f, List* lst);