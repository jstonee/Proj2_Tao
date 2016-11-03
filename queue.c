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
	if(q->rear == NULL)
	{
		q->rear = (struct node*)malloc(sizeof(node));
		q->rear->num = x;
		q->rear->next = NULL;
		q->front = q->rear;
	}
	else
	{
		temp = (struct node*)malloc(sizeof(node));
		q->rear->next = temp;
		q->temp->num = x;
		q->temp->next = NULL;
		q->rear = temp;
	}
	q->count++;
}
// Used to empty list??
void deq(Queue* q)
{

}
// Prints the line numbers 
void printLines(FILE *f, Queue* q)
{
	node *temp = q->front;
	
	while(temp != q->rear)
	{
		fprintf(f, "%d ", temp->num);
		temp = temp->next;
	}
	if (temp == q->rear)
		fprintf(f, "%d", temp->num);
}