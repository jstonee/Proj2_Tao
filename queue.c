#include "queue.h"

// Checks if the queue is empty
boolean isQEmpty(const Queue* q)
{
	return ((boolean)(q->count == EMPTY));
}
// Initalizes the queue
void init(Queue* q)
{
	q->count = 0;
	q->front = NULL;
	q->rear = NULL;
}
// Adds a number to the current queue if there one, else it will create a new queue
void que(int x, Queue* q)
{
	node *temp;
	if(rear == NULL)
	{
		rear = malloc(sizeof(node));
		rear->num = x;
		rear->next = NULL;
		front = rear;
	}
	else
	{
		temp = malloc(sizeof(node));
		rear->next = temp;
		temp->num = x;
		temp->next = NULL;
		rear = temp;
	}
	q->count++;
}
// Used to empty list??
int deq(Queue* q)
{
	
}
// Prints the line numbers 
void printLines(FILE *f, Queue* q)
{
	node *temp = q->front;
	
	while(temp != rear)
	{
		fprintf(f, "%d ", temp->num);
		temp = temp->next;
	}
	if (temp == rear)
		fprintf(f, "%d", temp->num);
}