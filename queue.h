#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY 0
#define FULL 10000

typedef enum { false, true } boolean;

struct node
{
	int num;
	struct node *next;
};

typedef struct node node;

struct Queue
{
	int count;
	node *front;
	node *rear;
};

boolean isQEmpty(const Queue* q);
void init(Queue* q);
void que(int x, Queue* q);
int deq(Queue* q);
void printLines(Queue* q);
