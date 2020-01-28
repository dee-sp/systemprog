#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*struct Book
{
 char title[50];
 int id;
};*/


struct Node
{
 //struct Book data;
 int index;
 struct Node* nextnode;
};


void printbook(struct Node* node)
{ 
 //printf ("%s\n", node->title);
 printf ("%d\n", node->index);
}


struct Node* createnode (int input)
{
 
 struct Node node;
 struct Node* nodeptr = &node;
 
 //book = malloc(sizeof(struct Book));
 //book->id = 1;
 //strcpy (book->title,"C Plus Plus");
 node.index = input;
 printbook (nodeptr);
 //free (book);
 return &node;
}

struct Node* insertnode(int input2)
{
 struct Node node, temp = head;
 struct Node* nodeptr = &node;

 for (int i=0; i<4; i++)
 {
  if(input2 == temp->index)
  {

  }
 }
}



int main ()
{
 struct Node* head;
 struct Node* curr;
 /*struct Book* book1;
 struct Book* book2;
 struct Book* book3;*/
 //int nodenum = 0;

 int count = 0;
 head = createnode (count);
 curr = head;
 
 //for (int i=0; i<5; i++)
//{
 count++;
 curr->nextnode = createnode (count);
 curr = curr->nextnode;
 
 count++;
 curr->nextnode = createnode (count);
 curr = curr->nextnode;

 count++;
 curr->nextnode = createnode (count);
 curr = curr->nextnode;
 
 /*for (int i=0; i<5; i++)
{
 free(book);
}*/

 return 0;
}
