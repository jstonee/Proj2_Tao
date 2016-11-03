#include "list.h"

// Checks if the linked list is empty
boolean isEmpty(const List* lst)
{
	return ((boolean)(lst->count == EMPTY))
}
// Initalizes the linked list
void init(List* lst)
{
	lst->count = 0;
	lst->top = NULL;
}
// Pushes an identifier and it's line number to the linked list, it also checks if it is in the list first and if it is then it just ques the line number
boolean push(data d, int num, List* lst)
{
	node *temp = lst->top;
	
	while(temp->next != NULL)
	{
		if(temp->d == d)
		{
			que(num, temp->lines);
			return true;
		}
		temp = temp->next;
	}
	temp->next = malloc(sizeof(node));
	temp->next->d = d;
	que(num, temp->next->lines);
	temp->next->next = NULL;
	lst->count++;
	
	return true;
}
// Possibly used to empty the linked list? Not sure if this function is needed yet
data pop(List* lst)
{
	
}
// Sorts the linked list to be in alphabetical order
void sort(List* lst)
{
	
}
// Prints the linked list and it's line numbers
void printList(List* lst)
{
	
}