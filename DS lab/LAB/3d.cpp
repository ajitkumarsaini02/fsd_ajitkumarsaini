// Array Implementation of Double-Ended Queue (Deque)

#include <iostream>
using namespace std;

#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

/* Check if deque is full */
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

/* Check if deque is empty */
int isEmpty() {
    return (front == -1);
}

/* Insert element at the front */
void insertFront(int x) {
    if (isFull()) {
        cout << "Deque Overflow" << endl;
        return;
    }
    if (front == -1) {           // Empty deque
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = x;
    cout << "Inserted " << x << " at front" << endl;
}

/* Insert element at the rear */
void insertRear(int x) {
    if (isFull()) {
        cout << "Deque Overflow" << endl;
        return;
    }
    if (front == -1) {           // Empty deque
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
    cout << "Inserted " << x << " at rear" << endl;
}

/* Delete element from the front */
void deleteFront() {
    if (isEmpty()) {
        cout << "Deque Underflow" << endl;
        return;
    }
    cout << "Deleted " << deque[front] << " from front" << endl;

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

/* Delete element from the rear */
void deleteRear() {
    if (isEmpty()) {
        cout << "Deque Underflow" << endl;
        return;
    }
    cout << "Deleted " << deque[rear] << " from rear" << endl;

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

/* Display all elements */
void display() {
    if (isEmpty()) {
        cout << "Deque is empty" << endl;
        return;
    }
    cout << "Deque elements: ";
    int i = front;
    while (1) {
        cout << deque[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

/* Main Function */
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
