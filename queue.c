#include "queue.h"

// Checks if the queue is empty
bool isQEmpty(const Queue* q)
{
	return ((bool)(q->count == EMPTY));
}
// Initalizes the queue
void qInit(Queue* q)
{
	q->count = 0;
	q->front = NULL;
	q->rear = NULL;
}
// Adds a number to the current queue if there one, else it will create a new queue
void que(int x, Queue* q)
{
	qNode *temp;
	if(q->rear == NULL)
	{
		temp = (struct qNode*)malloc(sizeof(qNode));
		temp->num = x;
		temp->next = NULL;
		q->rear = temp;
		q->front = q->rear;
		q->count++;
		return;
	}
	else
	{
		temp = (struct qNode*)malloc(sizeof(qNode));
		q->rear->next = temp;
		temp->num = x;
		temp->next = NULL;
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
	qNode *temp = q->front;
	
	while(temp != q->rear)
	{
		fprintf(f, "%d ", temp->num);
		temp = temp->next;
	}
	if (temp == q->rear)
		fprintf(f, "%d", temp->num);
}