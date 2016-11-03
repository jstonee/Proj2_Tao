#include <ctype.h>
#include "list.h"
#include "queue.h"

// Will put data into the list and queue
void getInfo(FILE *f, List *l);

int main(int argc, char* argv[])
{
	List l;
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

void getInfo(FILE *f, List *l)
{
	char ch;
	int line = 1;
	char *temp = (char*)malloc(sizeof(char));
	while(fscanf(f, "%c", &ch) != EOF)
	{
		if(isalpha(ch))
		{
			strcat(temp, ch);
		}
		if(!isalpha(ch) && strlen(temp) > 0)
		{
			if(push(temp, line, &l))
				strcpy(temp, "");
			else
				printf("ERROR: Did not push %s", temp);
		}
		if(ch == '/')
		{
			while(fscanf(f, "%c", &ch) != '\n')
				fscanf(f, "%c", &ch);
			line++;
		}
		if(ch == '\n')
			line++;
	}
}