// Pre-Processor Directives
#include <stdio.h> // Required for printf
#include <stdlib.h> // Required for memory allocation

// Global Variables
struct Node * head = NULL;
int globalBookID = 1; // This will auto-increment

struct Book
{
	char * title; // Pointer required to accept any number of characters in the string
	int id;
};

struct Node
{
 struct Book data;
 struct Node * nextnode;
};

void addBook(char * title) // Get the Book Name as a parameter
{
	struct Node * tempNode = (struct Node *) malloc(sizeof(struct Node));
	tempNode->data.title = title; // Give Title of parameter to the new node
	tempNode->data.id = globalBookID++; // Give auto increment ID to the new node
	tempNode->nextnode = head; // New node will point to the previous node
	head = tempNode; // Head will now point to the current node
}

void displayBooks()
{
	struct Node * tempNode;
	tempNode = head; // Iteration starts from the head

	while(tempNode != NULL) // Iterate the linked list till node is null
	{
		printf("%i. %s\n", tempNode->data.id, tempNode->data.title);
		tempNode = tempNode->nextnode;
	}
}

struct Node * reverseBooks( struct Node * node) // Recursive Function
{
	if (node == NULL)
		return NULL; // Function starts dying when node becomes NULL
	if (node->nextnode == NULL)
	{
		head = node;
		return node;
	}
	struct Node * tempNode = reverseBooks(node->nextnode); // All nodes go through this function
	tempNode->nextnode = node;
	node->nextnode = NULL; 
	return node;
}

int main ()
{
	addBook("Harry Potter");
	addBook("Lord of the Rings");
	addBook("The Book Thief");
	addBook("The Shining");
	addBook("Black Beauty");
	addBook("Tom Sawyer");
	addBook("Around the World in Eighty Days");
	addBook("Arabian Nights");

	printf("\nLinked List Before Reversing:\n");
	displayBooks();
	reverseBooks(head);
	printf("\nLinked List After Reversing:\n");
	displayBooks();

 	return 0;
}
