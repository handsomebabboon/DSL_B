// SLL with insert anywhere, delete and display

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int element;
	struct node *next;
} node;

node *newNode() {
	node *temp = (node *)malloc(sizeof(node));
	printf("Enter the element: ");
	scanf("%d", &temp->element);
	return temp;
}

node *insert(node *front) {
	if (front == NULL) {		//LL is empty
		front = newNode();
		front->next = NULL;
	} else {
		int pos, exist;
		node *temp, *s;
		printf("1.Insert before existing element\n2.Insert after existing element\nEnter choice: ");
		scanf("%d", &pos);
		printf("Enter the existing element: ");
		scanf("%d", &exist);
		switch(pos) {
			case 1://inserting before
				if (front->element == exist) {		//inserting at beginning
					temp = newNode();
					temp->next = front;
					front = temp;
				} else {	//inserting anywhere else
					for (s = front; s->next != NULL && s->next->element != exist; s = s->next);	// make pointer s poijnt to node before the one containing exist
					if (s->next == NULL) {
						printf("Element does not exist\n");
					} else {		//doing actual insertion
						temp = newNode();
						temp->next = s->next;
						s->next = temp;
					}
				}
				break;
			case 2:
				for (s = front; s != NULL && s->element != exist; s = s->next);  //make s point to node containing exist
				if (s == NULL) {		//element not found
					printf("Element does not exist\n");
				} else if (s->next == NULL){	//inserting after end
					s->next = newNode();
					s->next->next = NULL;
				} else {					//inserting anywhere else
					temp = newNode();
					temp->next = s->next;
					s->next = temp;
				}
				break;
			default:
				printf("Undefined choice\n");
		}
	}
	return front;
}

node *delete(node *front) {
	if (front == NULL) {		//list is empty
		printf("Underflow\n");
	} else if (front->next == NULL) {		//list has 1 element
		front = NULL;
	} else {		//any other case
		int exist;
		node *s;
		printf("Enter element to delete: ");
		scanf("%d", &exist);
		if (front->element == exist) {		//if element is at front
			front = front->next;
		} else {				//any other case
			for (s = front; s->next != NULL && s->next->element != exist; s = s->next);			//making s point to node before node containing element to delete(if deleting last node,s cannot point to last node)	
			if (s->next != NULL && s->next->element == exist) {									 
				s->next = s->next->next;
			} else {
				printf("Element does not exist\n");
			}
		}
	}
	return front;
}

void show(node *front) {
	if (front == NULL) {
		printf("Empty\n");
	} else {
		node *s;
		for (s = front; s->next != NULL; s = s->next)
			printf("%d->", s->element);
		printf("%d\n", s->element);
	}
}

int main() {
	int choice;
	node *front = NULL;
	while (1) {
		printf("\n1.Insert\n2.Delete\n3.Show\n4.Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				front = insert(front);
				break;
			case 2:
				front = delete(front);
				break;
			case 3:
				show(front);
				break;
			case 4:
				return 0;
			default:
				printf("Invalid choice\n");
		}
	}
}
