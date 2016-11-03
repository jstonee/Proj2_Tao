#include <ctype.h>
#include "list.h"

#define MAX 100
// Adds a character to the end of our current string
void append(char* old, const char c, int x);
// Will put data into the list and queue
void getInfo(FILE *f, List *l);


int main(int argc, char* argv[])
{
	List l;
	init(&l);
	FILE *fin, *fout;

	if (argc != 3)
	{
		printf("Usage: proj2 infile outfile\n");
		exit(1);
	}
	
	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	
	if (fin == NULL || fout == NULL)
	{
		printf("File could not be opened\n");
		exit(1);
	}
	
	getInfo(fin, &l);
	sort(&l);
	printList(fout, &l);
	fclose(fin);
	fclose(fout);
	
	return 0;
}

void append(char* old, const char c, int x)
{
	old[x] = c;
	old[x+1] = '\0';
}

void getInfo(FILE *f, List *l)
{
	char ch;
	int line = 1, count = 0;
	char *temp = (char*)malloc(sizeof(char) * MAX);
	while(fscanf(f, "%c", &ch) != EOF)
	{
		if(isalpha(ch))
		{
			append(temp, ch, count);
			count++;
		}
		if(!isalpha(ch) && count > 0)
		{
			push(temp, line, l);
			strcpy(temp, "");
			count = 0;
		}
		if(ch == '\n')
			line++;
		if (ch == '*')
		{
			fscanf(f, "%c", &ch);
			if(isalpha(ch))
			{
				append(temp, ch, count);
				count++;
			}
			else
			{
				while(ch != '\n')
				{
					fscanf(f, "%c", &ch);
				}
				line++;
			}
		}
		if(ch == '/')
		{
			while(ch != '\n')
			{
				fscanf(f, "%c", &ch);
			}
			line++;
		}
	}
}