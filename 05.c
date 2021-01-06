// DLL with insert anywhere, delete & display

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int element;
	struct node *next;
	struct node *prev;
} node;

node *front = NULL;

node *newNode() {
	node *temp = (node *)malloc(sizeof(node));
	printf("Enter the element: ");
	scanf("%d", &temp->element);
	return temp;
}

void insert() {
	if (front == NULL) {
		front = newNode();
		front->prev = NULL;
		front->next = NULL;
		return;
	}
	int search, pos;
	printf("1.Insert before existing element\n2.Insert after existing element\nenter choice: ");
	scanf("%d", &pos);
	if (pos != 1 && pos != 2) {
		printf("Invalid choice\n");
		return;
	}
	printf("Enter the existing element: ");
	scanf("%d", &search);
	node *searchPtr, *temp;
	for (searchPtr = front; searchPtr->element != search && searchPtr->next != NULL; searchPtr = searchPtr->next);
	if (searchPtr->element == search) {
		switch (pos) {
			case 1:	if (searchPtr == front) {		//inserting before front
						temp = newNode();
						temp->prev = NULL;
						temp->next = front;
						front->prev = temp;
						front = temp;
						return;
					}
					temp = newNode();				//inserting before anyhwere else;
					temp->prev = searchPtr->prev;
					temp->next = searchPtr;
					searchPtr->prev->next = temp;
					searchPtr->prev = temp;
					return;
			case 2:	if (searchPtr->next == NULL) {				//inserting after end
						searchPtr->next = newNode();
						searchPtr->next->prev = searchPtr;
						searchPtr->next->next = NULL;
						return;
					}
					temp = newNode();							//insertin after anywhere else9
					temp->next = searchPtr->next;
					searchPtr->next->prev = temp;
					temp->prev = searchPtr;
					searchPtr->next = temp;
					return;
		}
	}
	printf("Element does not exist\n");
}

void delete() {
	if (front == NULL) {
		printf("Underflow\n");
		return;
	}
	if (front->next == NULL) {
		front = NULL;
		return;
	}
	int search;
	printf("Enter the element to delete: ");
	scanf("%d", &search);
	node *searchPtr;
	for (searchPtr = front; searchPtr->element != search && searchPtr->next != NULL; searchPtr = searchPtr->next);
	if (searchPtr->element == search) {
		if (searchPtr == front) {		//deleting front node
			front = front->next;
			front->prev = NULL;
			return;
		}
		if (searchPtr->next == NULL) {				//deleting end node
			searchPtr->prev->next = NULL;
			return;
		}
		searchPtr->next->prev = searchPtr->prev;				//deleting anything else
		searchPtr->prev->next = searchPtr->next;
		return;
	}
	printf("Element does not exist\n");
}

void show() {
	if (front == NULL) {
		printf("Underflow\n");
		return;
	}
	node *temp;
	for (temp = front; temp->next != NULL; temp = temp->next)
		printf("%d->", temp->element);
	printf("%d\n", temp->element);
}

int main() {
	int choice;
	while (1) {
		printf("\n1.Insert\n2.Delete\n3.Show\n4.Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:	insert();
					break;
			case 2:	delete();
					break;
			case 3:	show();
					break;
			case 4:	return 0;
			default:	printf("Invalid choice\n");
		}
	}
}	
