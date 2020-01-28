#include <stdio.h>
#include <string.h>

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


struct Book* updateinfo (struct Book* book)
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
 struct Book* book;
 head = updateinfo (&book);
 
 

 return 0;
}
