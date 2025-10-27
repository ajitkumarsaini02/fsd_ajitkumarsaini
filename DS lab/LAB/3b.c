//  Circular Queue using Array
#include <stdio.h>
#include <stdlib.h>
#define MAX 5   

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

// Function to insert an element
void EnQueue(int x) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)  
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    printf("Inserted -> %d\n", x);
}

// Function to delete an element
int DeQueue() {
    int x;
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    x = queue[front];
    if (front == rear) {  
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return x;
}

// Function to display the queue
void Display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main() {
    EnQueue(10);
    EnQueue(20);
    EnQueue(30);
    EnQueue(40);
    EnQueue(50);
    Display();

    printf("Deleted -> %d\n", DeQueue());
    printf("Deleted -> %d\n", DeQueue());
    Display();

    EnQueue(60);
    EnQueue(70);
    Display();

    return 0;
}