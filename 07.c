// Insert into ordered DLL
//ascending order
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int element;
	struct node *prev;
	struct node *next;
} node;

node *front = NULL;

node *newNode() {
	node *temp = (node *)malloc(sizeof(node));
	printf("Enter the element: ");
	scanf("%d", &temp->element);
	getchar();
	return temp;
}

bool insert(node *insertNode) {
	if (insertNode == NULL)
		return false;
	if (front == NULL) {		//list is empty
		front = insertNode;
		front->next = NULL;
		front->prev = NULL;
		return true;
	}
	if (front->element > insertNode->element) {			//inserting before head
		insertNode->prev = NULL;
		insertNode->next = front;
		front->prev = insertNode;
		front = insertNode;
		return true;
	}
	node *s;
	for (s = front; s->element < insertNode->element && s->next != NULL; s = s->next);		//finding the first element in the list greater than the one to insert
	if (s->next == NULL && s->element < insertNode->element) {		//inserting  at end of list,insertnode is greater than  all the elements in list	
		insertNode->next = NULL; 
		insertNode->prev = s;
		s->next = insertNode;
		return true;
	}
	insertNode->next = s;			//inserting anywhere else	
	insertNode->prev = s->prev;
	s->prev->next = insertNode;
	s->prev = insertNode;
	return true;
}

bool show() {
	if (front == NULL)
		return false;
	node *s;
	for (s = front; s->next != NULL; s = s->next)
		printf("%d<-->", s->element);
	printf("%d\n", s->element);
	return true;
}

int main() {
	char choice;
	while (1) {
		printf("Enter an element? (y/n): ");
		scanf("%c", &choice);
		getchar();
		switch(choice) {
			case 'y':
			case 'Y':	if (!insert(newNode()))
						printf("Overflow\n");
					show();
					break;
			case 'n':
			case 'N':	return 0;
			default:	printf("Undefined choice\n");
		}
	}
}
