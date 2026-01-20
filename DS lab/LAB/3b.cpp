// Circular Queue using Array

#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

/* Check if Queue is Full */
int isFull() {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return 1;
    else
        return 0;
}

/* Check if Queue is Empty */
int isEmpty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

/* EnQueue Operation */
void EnQueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow" << endl;
        return;
    }
    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = x;
    cout << "Inserted -> " << x << endl;
}

/* DeQueue Operation */
int DeQueue() {
    int x;
    if (isEmpty()) {
        cout << "Queue Underflow" << endl;
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

/* Display Operation */
void Display() {
    int i;
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    i = front;
    while (1) {
        cout << queue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

/* Main Function */
int main() {
    EnQueue(10);
    EnQueue(20);
    EnQueue(30);
    EnQueue(40);
    EnQueue(50);
    Display();

    cout << "Deleted -> " << DeQueue() << endl;
    cout << "Deleted -> " << DeQueue() << endl;
    Display();

    EnQueue(60);
    EnQueue(70);
    Display();

    return 0;
}
