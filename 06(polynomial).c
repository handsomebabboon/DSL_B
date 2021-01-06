// Polynomial using SLL

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
	int coeff;
	int power;
	struct node *next;
} node;

node *head = NULL;

node *newNode() {
	node *temp = (node *)malloc(sizeof(node));
	printf("power of the term: ");
	scanf("%d", &temp->power);
	printf("Coeffecient of the term: ");
	scanf("%d", &temp->coeff);
	return temp;
}

void insert() {
	if (head == NULL) {
		head = newNode();
		head->next = NULL;
	} else {
		node *inNode = newNode();
		if (inNode->power > head->power) {
			inNode->next = head;
			head = inNode;
		} else {
			node *s;
			for (s = head; s->next != NULL && s->power > inNode->power; s = s->next);
			if (s->power == inNode->power) {
				s->coeff += inNode->coeff;
			} else if (s->power < inNode->power) {
				node *t;
				for (t = head; t->next != s; t = t->next);
				t->next = inNode;
				inNode->next = s;
			} else {
				s->next = inNode;
				inNode->next = NULL;
			}
		}
	}
}

void eval() {
	int x, sum = 0;
	printf("Enter the value of x: ");
	scanf("%d", &x);
	for (node *i = head; i != NULL; i = i->next)
		sum += (i->coeff  *pow(x, i->power));
	printf("Answer = %d\n", sum);
}

void show() {
	if (head == NULL) {
		printf("The list is empty\n");
	} else {
		node *i;
		for (i = head; i->next != NULL; i = i->next)
			printf("(%d)x^%d + ", i->coeff, i->power);
		printf("(%d)x^%d\n", i->coeff, i->power);
	}
}

int main() {
	int choice;
	while (1) {
		printf("\n1.Insert\n2.Show\n3.Evaluate\n4.Exit\nEnterchoice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				insert();
				break;
			case 2:
				show();
				break;
			case 3:
				eval();
				break;
			case 4:
				return 0;
			default:
				printf("Undefined choice\n");
		}
	}
}
