// Priority queue using arrays

#include <stdio.h>

#define MAX 20

int queue[MAX];
int front = 0;
int rear = -1;

int getElement() {
	int a;
	printf("Enter element: ");
	scanf("%d", &a);
	return a;
}

int pInsert(int element) {
	
	if (rear == MAX - 1)		//array full
		return -1;
	if (rear == -1) {				//no elements
		queue[++rear] = element;
		return 0;
	}
	int i;
	for (i = rear; queue[i] > element && i >= 0; --i)
		queue[i + 1] = queue[i];	//shifting all elements greater than element to the right
	queue[i + 1] = element;			//element inserted
	++rear;
	return 0;
}

int delete() {
	if (rear < front)		//array empty
		return -1;
	if (rear == front) {				//only 1 element in array
		rear = -1, front = 0;
		return 0;
	}
	++front;		//more than one element
	return 0;
}

int show() {
	if (rear < front)		//array empyt
		return -1;
	for (int i = front; i <= rear; ++i)		//printing
		printf("%d ", queue[i]);
	printf("\n");
}

int main() {
	int choice, temp;
	while (1) {
		printf("\n1.Insert\n2.Delete\n3.Show\n4.Exit\nEnter choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:	temp = pInsert(getElement());
					if (temp == -1)
						printf("Overflow\n");
					break;
			case 2:	temp = delete();
					if (temp == -1)
						printf("Underflow\n");
					break;
			case 3:	temp = show();
					if (temp == -1)
						printf("Empty\n");
					break;
			case 4:	return 0;
			default:	printf("Undefined choice\n");
		}
	}
}
