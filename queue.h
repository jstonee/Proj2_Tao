#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define EMPTY 0

struct qNode
{
	int num;
	struct qNnode *next;
};

typedef struct qNode qNode;

struct Queue
{
	int count;
	qNode *front;
	qNode *rear;
};
typedef struct Queue Queue;

bool isQEmpty(const Queue* q);
void qInit(Queue* q);
void que(int x, Queue* q);
void printLines(FILE *f, Queue* q);
