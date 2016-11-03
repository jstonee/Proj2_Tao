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
	
	while(!feof(fin))
	{
		getInfo(fin, &l);
	}
	
	sort(&l);
	printList(fout, &l);
	fclose(fin);
	fclose(fout);
	
	return 0;
}

void getInfo(FILE *f, List *l)
{
	
}