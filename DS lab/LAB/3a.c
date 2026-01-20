// Linear Queue using Array
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

/* EnQueue Operation */
void EnQueue(int x) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = x;
    printf("%d inserted into queue\n", x);
}

/* DeQueue Operation */
int DeQueue() {
    int item;

    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }

    item = queue[front];
    front++;

    return item;
}

/* Display Operation */
void Display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

/* Main Function */
int main() {
    int deletedItem;

    EnQueue(10);
    EnQueue(20);
    EnQueue(30);

    printf("\nQueue before deletion:\n");
    Display();

    deletedItem = DeQueue();
    if (deletedItem != -1) {
        printf("Deleted element: %d\n", deletedItem);
    }

    printf("\nQueue after deletion:\n");
    Display();

    return 0;
}
