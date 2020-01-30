#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

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
	struct Node* head;
	struct Node* last;
	int count; 
};

struct Node* addNewNode(struct list* list, int pos)
{
	struct Node* node  = malloc(sizeof(struct Node));
	node->nextnode = NULL;

	if(list->head == NULL)
	{
		node->nextnode = list->head;
		list->head = node;
 	}
	else
	{
		if(pos == 0)
		{
			list->head = node;
			list->last = node;
		}
		else 
		{
			list->last->nextnode = node;
			list->last = node;
		}
	}
		list->count++;	
}

/*struct Node* addNewNode(struct list* list)
{
	addNewNode(list,-1);//adding new node at the end
}*/

void printlist(struct list* list)
{
	struct Node* temp = list->head;
	while(temp!=NULL)
	{
		printf("%f \n",temp->data.avg);
		temp = temp->nextnode;
	}
}

void reverselist(struct list* list)
{
	struct Node* curr = list->head;
	struct Node* temp = NULL;
	list->last = curr;

	while(curr!=NULL)
	{
		temp = curr;
		curr = curr->nextnode;
		temp->nextnode = list->head;
		list->head = temp;
	}
	list->last->nextnode = NULL;
}


int main (int argc, char* args [])
{
	char buff[1024] = {0};
	char* temp;
	char* token;

	if (argc > 3)
	{
		printf("Input file not specified.");
		return -1;
	}

	printf ("Input file: %s \n", args[1]);

	struct list* ACCElist;
	ACCElist->head=NULL;
	ACCElist->last=NULL;
	ACCElist->count=0;

	FILE* file = fopen(args[1],"r");

	

	while (fgets (buff,1024,file))
	{
		temp = strdup(buff);
                token = strtok (temp,";");

		if(strcmp(token,args[2])==0)
			{
				struct Node* node = addNewNode (ACCElist,-1);

				token = strtok(NULL,";");
				token = strtok(NULL,";");
				token = strtok(NULL,";");
				node->data.x = strtod(token,NULL);
				token = strtok(NULL,";");
				node->data.y = strtod(token,NULL);
				token = strtok(NULL,";");
				node->data.z = strtod(token,NULL);
				
				node->data.avg = (node->data.x+node->data.y+node->data.z)/3.0;
				
			}
		free(temp);
		temp = NULL;
	}
	printlist(ACCElist);

	fclose(file);
return 0;
}
