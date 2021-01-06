// Infix to postfix

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 50
char stack[SIZE], infix[SIZE];
int top = -1;

void push(char element) {
	stack[++top] = element;
}

char pop() { 
	return stack[top--];
}

int level(char a) {
	switch(a) {
		case ')':
			return -1;
		case '(':
			return 0;
		case '+':
			return 1;
		 case '-':
		 	return 1;
		case '*': 
			return 2;
		case '%':
			return 2;
		 case '/':
		 	return 2;
		case '^':
			return 3;
	}
}

bool ishigh(char a, char b) {
	return (level(a) > level(b));
}

int main() {
	printf("Enter infix expression: ");
	scanf("%s", infix);
	printf("Postfix expression: ");
	int i;
	char ch;
	for (i = 0, ch = infix[i]; ch != '\0'; ++i, ch = infix[i]) {
		if (isalpha(ch))
			printf("%c", ch);
		else if (ch == ')')
			for (char popped = pop(); popped != '('; popped = pop())
				printf("%c", popped);
		else if (ch == '(' || top == -1 || stack[top] == '(' || ishigh(ch, stack[top]))
			push(ch);
		else {
			for (char next = stack[top]; !ishigh(ch, stack[top]); next = stack[top])
				printf("%c", pop());
			push(ch);
		}
	}
	while (top != -1)
		printf("%c", pop());
	printf("\n");
	return 0;
}
