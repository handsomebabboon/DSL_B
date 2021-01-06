// Delete every other node of SLL

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int element;
	struct node *next;
} node;

node *front = NULL;
node *rear = NULL;

node *newNode() {
	node *temp = (node *)malloc(sizeof(node));
	printf("Enter the element: ");
	scanf("%d", &temp->element);
	getchar();
	return temp;
}

void insert(node *inNode) {
	if (front == NULL) {
		front = inNode;
		rear = front;
		front->next = NULL;
		return;
	}
	rear->next = inNode;
	rear = rear->next;
	rear->next = NULL;
}

void show() {
	if (front == NULL) {
		printf("\n");
		return;
	}
	node *s;
	for (s = front; s->next != NULL; s = s->next)
		printf("%d->", s->element);
	printf("%d\n", s->element);
}

void deleteSec() {
	if (front != NULL && front != rear)
		for (node *s = front; s != NULL && s->next != NULL; s = s->next)
			s->next = s->next->next;
}

int main() {
	char choice;
	while (1) {
		printf("Enter element? (y/n): ");
		scanf("%c", &choice);
		getchar();
		switch (choice) {
			case 'y':
			case 'Y':
				insert(newNode());
				printf("List: ");
				show();
				break;
			case 'n':
			case 'N':
				printf("Deleting every other node\n");
				deleteSec();
				printf("List: ");
				show();
				return 0;
			default:
				printf("Undefined choice\n");
		}
	}
}
