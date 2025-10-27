// Array Implementation of Double-Ended Queue (Deque)
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Function to check if deque is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// Function to check if deque is empty
int isEmpty() {
    return (front == -1);
}

// Insert element at the front
void insertFront(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) { // Empty deque
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = x;
    printf("Inserted %d at front\n", x);
}

// Insert element at the rear
void insertRear(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) { // Empty deque
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
    printf("Inserted %d at rear\n", x);
}

// Delete element from the front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted %d from front\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Delete element from the rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted %d from rear\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Display all elements in deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main() {
    insertRear(10);
    insertRear(20);
    insertRear(30);
    display();

    insertFront(5);
    insertFront(2);
    display();

    deleteFront();
    deleteRear();
    display();

    insertRear(40);
    display();

    return 0;
}