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
 struct Node* nextnode;
};



void printbook(struct Book* book)
{ 
 printf ("%s\n", book->title);
 printf ("%d\n", book->id);
}


struct Book* createbook (int id)
{
 //struct Book book;
 struct Book* bookptr;

 bookptr = malloc(sizeof(struct Book));
 bookptr->id = id;
 strcpy (bookptr->title, "Book");
 printbook(bookptr);

 return bookptr;

}

struct Node* createnode (int id)
{
 //struct Book book;
 struct Node* nodeptr;
 struct Book* book;

 //nodeptr = malloc(sizeof(struct Node));
 book = createbook (id);
 nodeptr->data = *book;

 return nodeptr;

}

/*void traverselist(struct Node* head) 
{
    struct Node* curr = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}*/

struct Node* insertnode (int id2)
{
 
}

int main ()
{
    struct Node* head = NULL;
    struct Node* curr = NULL;
    struct Book* book;
    int i=0;

    for (i=0; i<5; i++)
    {
    	if (i=0)
    	{
    		curr = head = createnode (i);
    	}
    	else
    	{
    		curr->nextnode = createnode (i);
    	    curr = curr->nextnode;
    	}
    	
    }
    
	return 0;
}
