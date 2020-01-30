#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node * head = NULL;

struct Book
{
char title[50]; 
int id;
};

struct Node
{
struct Book data;
struct Node * nextnode;
};

struct Node* createNode(int id) 
{
struct Node * tempNode = malloc(sizeof(struct Node));
strcpy(tempNode->data.title,"Name"); 
tempNode->data.id = id; 

return tempNode;
}

void displaylist()
{
struct Node * tempNode;
tempNode = head; 
while(tempNode != NULL) 
{
printf("%i. %s\n", tempNode->data.id, tempNode->data.title);
tempNode = tempNode->nextnode;
}
}

void insertnodeafter (int id)
{
int i=0;
struct Node * tempNode;
struct Node * tempnode2;
tempNode = head; 
while(tempNode != NULL) 
{
printf("%i. %s\n", tempNode->data.id, tempNode->data.title);
//printf("here");
if (tempNode->data.id=id)
{ 
tempnode2 = createNode (10);
tempnode2->nextnode = tempNode->nextnode;
tempNode->nextnode = tempnode2;
}
tempNode = tempNode->nextnode;
}


}

int main ()
{

struct Node *curr = NULL;
int count = 0;
int j = 0;
int i=0;

for(j=0;j<8;j++)
{
if (count == 0)
 {
curr = createNode(count);
count++;
head = curr;
}
else
{
curr->nextnode = createNode(count);
count++;
curr = curr->nextnode;
}
}
curr = head;

displaylist();

insertnodeafter(2);

displaylist();

for(i=0;i<count;i++)
{
head = curr->nextnode;
free(curr);
curr = head;
}

return 0;
}
