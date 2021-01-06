// Create and traverse binary tree

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int element;
	struct node *left;
	struct node *right;
} node;

node *root = NULL;

node *binTree() {
	node *temp = (node *)malloc(sizeof(node));
	printf("Enter element: ");
	scanf("%d", &temp->element);
	getchar();
	printf("Enter a left child for %d? (y/n): ", temp->element);
	char a;
	scanf("%c", &a);
	getchar();
	if (a == 'y')
		temp->left = binTree();
	else
		temp->left = NULL;
	printf("Enter a right child for %d? (y/n): ", temp->element);
	scanf("%c", &a);
	getchar();
	if (a == 'y')
		temp->right = binTree();
	else
		temp->right = NULL;
	return temp;
}

void inorder(node *a) {
	if (a == NULL)
		return;
	inorder(a->left);
	printf("%d ", a->element);
	inorder(a->right);
}

void preorder(node *a) {
	if (a == NULL)
		return;
	printf("%d ", a->element);
	preorder(a->left);
	preorder(a->right);
}

void postorder(node *a) {
	if (a == NULL)
		return;
	postorder(a->left);
	postorder(a->right);
	printf("%d ", a->element);
}

int main() {
	int choice;
	while (1) {
		printf("\n1.Create\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\nEnter choice: ");
		scanf("%d", &choice);
		getchar();
		switch (choice) {
			case 1:	root = binTree();
					break;
			case 2:	inorder(root);
					printf("\n");
					break;
			case 3:	preorder(root);
					printf("\n");
					break;
			case 4:	postorder(root);
					printf("\n");
					break;
			case 5:	printf("Exiting\n");
					return 0;
			default:	printf("Undefined choice\n");
		}
	}
	return 0;
}
