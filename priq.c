#include<stdio.h>
#define SIZE 20

int arr[SIZE];
int front = 0;
int rear = -1;

void insert(int a){
    if(front > rear){
        arr[++rear] = a;
        return;
    }
    if(rear == SIZE - 1){
        printf("Array is full!\n");
        return;
    }
    int i;
    for(i=rear;i>=front && a<arr[i];i--){
        arr[i+1]= arr[i];

    }
    arr[i+1] = a;
    rear++;
}

void delete(){

      if(front > rear){
        printf("Queue is empty!\n");
        return;
    }

    if(front == rear){
        front = 0;
        rear = -1;
        return;
    }

    ++front;
}

void show(){

    for(int i=front;i<=rear ;i++){
        printf("%d\t",arr[i]);
    }
}

int main(){

    int choice;
    int ele;

    while(1){

        printf("\nenter 1-insert 2-delete 3-exit 4-show\n");
        scanf(" %d",&choice);
        switch(choice){
            case 1:
                printf("Ente rthe element to insert\n");
                scanf(" %d",&ele);
                insert(ele);
                printf("\n");
               
                break;
            case 2:
                delete();
                break;

            case 3:
                return 0;

            case 4:
            show();
            break;
            default:
                printf("invalide option\n");
        }
    }
    return 0;
}