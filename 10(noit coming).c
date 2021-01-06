// Expression tree and evaluation

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 20
typedef struct tree {
	char data;
	struct tree *left, *right;
} tree;

tree *stack[MAX];
int top = -1;

void push(tree *node) {
	stack[++top] = node;
}

tree *pop() {
	return stack[top--];
}

void operand(char ch) {
	tree *node = (tree *)malloc(sizeof(tree));
	node->data = ch;
	node->left = NULL, node->right = NULL;
	push(node);
}

void operator(char ch) {
	tree *node = (tree*)malloc(sizeof(tree));
	node->data = ch;
	node->left = pop();
	node->right = pop();
	push(node);
}

bool isoperator(char ch) {
	switch (ch) {
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
			return true;
		default:
			return false;
	}
}

int eval(tree *node) {
	if (!isoperator(node->data)) {
		return node->data - '0';
	} else {
		switch(node->data) {
			case '+':
				return eval(node->left) + eval(node->right);
			case '-':
				return eval(node->left) - eval(node->right);
			case '*':
				return eval(node->left)  *eval(node->right);
			case '/':
				return eval(node->left) / eval(node->right);
			case '%':
				return eval(node->left) % eval(node->right);
			case '^':
				return pow(eval(node->left), eval(node->right));
		}
	}
}

void inorder(tree *node) {
	if (node != NULL) {
		inorder(node->left);
		printf("%c", node->data);
		inorder(node->right);
	}
}

int main() {
	char postfix[MAX];
	printf("Enter the postfix expression:\n");
	scanf("%s", postfix);
	for (int i = 0; postfix[i] != '\0'; ++i) {
		if (isoperator(postfix[i]))
			operator(postfix[i]);
		else
			operand(postfix[i]);
	}
	printf("Inorder traversal:\n");
	inorder(stack[top]);
	int result = eval(stack[top]);
	printf("\nAnswer = %d\n", result);
	return 0;
}
