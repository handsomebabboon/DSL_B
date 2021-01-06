// CLL insert anywhere, delete & display

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int element;
	struct node *next;
} node;

node *front = NULL;
    
node *newNode() {
	node *temp = (node *)malloc(sizeof(node));
	printf("Enter the element: ");
	scanf("%d", &temp->element);
	return temp;
}

bool display() {
	if (front == NULL)
		return false;
	node *temp;
	for (temp = front; temp->next != front; temp = temp->next)
		printf("%d->", temp->element);
	printf("%d\n", temp->element);
	return true;
}

bool insert() {
	if (front == NULL) {
		front = newNode();
		front->next = front;
		return true;
	}
	int pos, search;
	node *searchPtr;
	printf("1.Insert before\n2.insert after\nEnter selection: ");
	scanf("%d", &pos);
	printf("Enter existing element to find: ");
	scanf("%d", &search);
	switch (pos) {
		case 1:	for (searchPtr = front; searchPtr->next != front && searchPtr->next->element != search; searchPtr = searchPtr->next);		//finding node bfore node continng element

				if (searchPtr->next->element == search)
					break;
				else
					return false;
		case 2:	for (searchPtr = front; searchPtr->next != front && searchPtr->element != search; searchPtr = searchPtr->next);
				if (searchPtr->element == search)
					break;
				else
					return false;
		default:	printf("Undefined choice\n");
				return true;
	}
	node *temp = newNode();
	temp->next = searchPtr->next;
	searchPtr->next = temp;
	return true;
}

bool delete() {
	if (front == NULL) {
		printf("Underflow\n");
		return true;
	}
	if (front->next == front) {
		front = NULL;
		return true;
	}
	int search;
	printf("Enter the element to delete: ");
	scanf("%d", &search);
	node *searchPtr;
	for (searchPtr = front; searchPtr->next->element != search && searchPtr->next != front; searchPtr = searchPtr->next);
	if (searchPtr->next->element == search) {
		if (searchPtr->next == front)
			front = front->next;
		searchPtr->next = searchPtr->next->next;
		return true;
	}
	return false;
}

int main() {
	int choice;
	while (1) {
		printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:	if (!insert())
						printf("Element does not exist\n");
					break;
			case 2:	if (!delete())
						printf("Element does not exist\n");
					break;
			case 3:	if(!display())
						printf("Empty\n");
					break;
			case 4:	return 0;
			default:	printf("Undefined choice\n");
		}
	}
}
