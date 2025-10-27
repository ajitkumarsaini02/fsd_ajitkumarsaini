 // Linear Queue (Array Implementation)
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void EnQueue(int x) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = x;
}

int DeQueue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    int x = queue[front];
    front++;
    return x;
}

void Display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    EnQueue(10);
    EnQueue(20);
    EnQueue(30);

    printf("Queue before deletion:\n");
    Display();

    int deletedItem = DeQueue();  // store deleted item
    if (deletedItem != -1)
        printf("Deleted element: %d\n", deletedItem);

    printf("Queue after deletion:\n");
    Display();

    return 0;
}