#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>




struct ACCE
{
	double x;
	double y;
	double z;
 	double avg;
};

struct Node
{
	struct ACCE data;
	struct Node* nextnode;
};

struct list
{
	
};

int main (int argc, char* args [])
{
	char buff[1024] = {0};

	if (argc > 2)
	{
		printf("Input file not specified.");
		return -1;
	}

	printf ("Input file: %s \n", args[1]);
	FILE* file = fopen(args[1],"r");

	while (fgets (buff,1024,file))
	{
		printf("%s",buff);
	}

	fclose(file);
return 0;
}
