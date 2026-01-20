// Linear Queue using Array

#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

/* EnQueue Operation */
void EnQueue(int x) {
    if (rear == SIZE - 1) {
        cout << "Queue Overflow" << endl;
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = x;
    cout << x << " inserted into queue" << endl;
}

/* DeQueue Operation */
int DeQueue() {
    int item;

    if (front == -1 || front > rear) {
        cout << "Queue Underflow" << endl;
        return -1;
    }

    item = queue[front];
    front++;

    return item;
}

/* Display Operation */
void Display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

/* Main Function */
int main() {
    int deletedItem;

    EnQueue(10);
    EnQueue(20);
    EnQueue(30);

    cout << "\nQueue before deletion:" << endl;
    Display();

    deletedItem = DeQueue();
    if (deletedItem != -1) {
        cout << "Deleted element: " << deletedItem << endl;
    }

    cout << "\nQueue after deletion:" << endl;
    Display();

    return 0;
}
