#include "list.h"

// Checks if the linked list is empty
bool isEmpty(const List* lst)
{
	return ((bool)(lst->count == EMPTY));
}
// Initalizes the linked list
void init(List* lst)
{
	lst->count = 0;
	lst->top->next = NULL;
}
// Pushes an identifier and it's line number to the linked list, it also checks if it is in the list first and if it is then it just ques the line number
void push(data* d, int num, List* lst)
{
	node *temp = lst->top;
	if(temp->next == NULL)
	{
		printf("INSIDE PUSH(NULL)\n");
		temp->next = (struct node*)malloc(sizeof(node));
		temp->next->d = d;
		qInit(temp->lines);
		que(num, temp->next->lines);
		temp->next->next = NULL;
		lst->count++;
		return;
	}
	while(temp->next != NULL)
	{
		printf("INSIDE PUSH\n");
		if(temp->d == d)
		{
			if(isQEmpty(temp->lines) == 0)
			{
				qInit(temp->lines);
				que(num, temp->lines);
				return;
			}
			else
			{
				que(num, temp->lines);
				return;	
			}
		}
		temp = temp->next;
	}
	temp->next = (struct node*)malloc(sizeof(node));
	temp->next->d = d;
	que(num, temp->next->lines);
	temp->next->next = NULL;
	lst->count++;
	
	return;
}
// Possibly used to empty the linked list? Not sure if this function is needed yet
void empty(List* lst)
{
	
}
// Sorts the linked list to be in alphabetical order
void sort(List* lst)
{
	int i, j, k;
	data tempD;
	Queue* tempQue;
	int size = lst->count;
	k = size;
	node *current;
	node *next;
	
	for( i = 0; i < size - 1; i++, k--) 
	{
		printf("INSIDE SORT\n");
		current = lst->top;
		next = current->next;
		for ( j = 1; j < k; j++)
		{
			if(strcmp(current->d, next->d) > 0)
			{
				tempD = current->d;
				current->d = next->d;
				next->d = tempD;
				
				tempQue = current->lines;
				current->lines = next->lines;
				next->lines = tempQue;
			}
			current = current->next;
			next = next->next;
		}
	}
}
// Prints the linked list and it's line numbers
void printList(FILE *f, List* lst)
{
	node *temp = lst->top;
	
	while(temp != NULL)
	{
		printf("INSIDE PRINTLIST\n");
		fprintf(f, "%s: ", temp->d);
		printLines(f, temp->lines);
		printf("\n");
		temp = temp->next;
	}
}