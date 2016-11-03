#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define EMPTY 0

typedef enum { false, true } boolean;
typedef char data;

struct node
{
	data	d;
	Queue	lines;
	struct node* next;
};

typedef struct node node;

struct List
{
	int count;
	node *top;	
};
typedef struct List List;

boolean isEmpty(const List* lst);
void init(List* lst);
boolean push(data d, int num, List* lst);
data pop(List* lst);
void sort(List* lst);
void printList(List* lst);