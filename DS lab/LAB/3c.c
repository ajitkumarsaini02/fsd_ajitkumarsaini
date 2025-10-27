// Priority Queue (Array Implementation)
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct PriorityQueue {
    int data[MAX];
    int front;
    int rear;
};

struct PriorityQueue PQ;

// Function to initialize the queue
void Initialize() {
    PQ.front = -1;
    PQ.rear = -1;
}

// Function to check if queue is empty
int IsEmpty() {
    return (PQ.front == -1);
}

// Function to check if queue is full
int IsFull() {
    return (PQ.rear == MAX - 1);
}

// Function to insert element in priority order (ascending)
void EnQueue(int x) {
    if (IsFull()) {
        printf("Priority Queue Overflow\n");
        return;
    }

    // If queue is empty
    if (PQ.front == -1) {
        PQ.front = PQ.rear = 0;
        PQ.data[PQ.rear] = x;
        return;
    }

    // Insert element according to priority
    int i;
    for (i = PQ.rear; i >= PQ.front && PQ.data[i] > x; i--) {
        PQ.data[i + 1] = PQ.data[i];
    }

    PQ.data[i + 1] = x;
    PQ.rear++;

    printf("Inserted: %d\n", x);
}

// Function to delete the element with highest priority (smallest number)
int DeQueue() {
    if (IsEmpty()) {
        printf("Priority Queue Underflow\n");
        return -1;
    }

    int x = PQ.data[PQ.front];
    PQ.front++;

    if (PQ.front > PQ.rear)
        PQ.front = PQ.rear = -1;  // Reset queue if empty

    return x;
}

// Function to display the queue
void Display() {
    if (IsEmpty()) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = PQ.front; i <= PQ.rear; i++) {
        printf("%d ", PQ.data[i]);
    }
    printf("\n");
}

int main() {
    Initialize();

    EnQueue(40);
    EnQueue(30);
    EnQueue(60);
    EnQueue(10);
    EnQueue(50);

    Display();

    printf("Deleted: %d\n", DeQueue());
    Display();

    printf("Deleted: %d\n", DeQueue());
    Display();

    return 0;
}