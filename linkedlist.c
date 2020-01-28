#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book
{
 char title[50];
 int id;
};


struct Node
{
 struct Book data;
 struct Node *nextnode;
};


void printbook(struct Book* book)
{ 
 printf ("%s\n", book->title);
 printf ("%d\n", book->id);
}


struct Node* createnode (struct Node* node)
{
 
 struct Node node;
 book = malloc(sizeof(struct Book));
 book->id = 1;
 strcpy (book->title,"C Plus Plus");
 printbook (book);
 //free (book);
 return &node;
}



int main ()
{
 struct Node* head = NULL;
 struct Node* curr = NULL;
 struct Book* book1;
 struct Book* book2;
 struct Book* book3;

 int count = 0;
 head = createnode (&book1);
 curr = head;
 
 //for (int i=0; i<5; i++)
//{
 count++;
 curr->nextnode = createnode (&book2);
curr = 
 printf ("%d\n", count);
//}
 count++;
 curr->nextnode = createnode (&book3);
 printf ("%d\n", count);

 count++;
 curr->nextnode = createnode (&book);
 printf ("%d\n", count);
 
 /*for (int i=0; i<5; i++)
{
 free(book);
}*/

 return 0;
}
