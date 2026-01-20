// Priority Queue (Array Implementation)

#include <iostream>
using namespace std;

#define MAX 10

struct PriorityQueue {
    int data[MAX];
    int front;
    int rear;
};

PriorityQueue PQ;

/* Initialize the queue */
void Initialize() {
    PQ.front = -1;
    PQ.rear  = -1;
}

/* Check if queue is empty */
int IsEmpty() {
    return (PQ.front == -1);
}

/* Check if queue is full */
int IsFull() {
    return (PQ.rear == MAX - 1);
}

/* EnQueue operation (ascending priority: smaller value = higher priority) */
void EnQueue(int x) {
    if (IsFull()) {
        cout << "Priority Queue Overflow" << endl;
        return;
    }

    // If queue is empty
    if (PQ.front == -1) {
        PQ.front = PQ.rear = 0;
        PQ.data[PQ.rear] = x;
        cout << "Inserted: " << x << endl;
        return;
    }

    // Insert element according to priority
    int i;
    for (i = PQ.rear; i >= PQ.front && PQ.data[i] > x; i--) {
        PQ.data[i + 1] = PQ.data[i];
    }

    PQ.data[i + 1] = x;
    PQ.rear++;

    cout << "Inserted: " << x << endl;
}

/* DeQueue operation (remove highest priority element) */
int DeQueue() {
    if (IsEmpty()) {
        cout << "Priority Queue Underflow" << endl;
        return -1;
    }

    int x = PQ.data[PQ.front];
    PQ.front++;

    // Reset when queue becomes empty
    if (PQ.front > PQ.rear) {
        PQ.front = PQ.rear = -1;
    }

    return x;
}

/* Display the queue */
void Display() {
    if (IsEmpty()) {
        cout << "Priority Queue is empty" << endl;
        return;
    }

    cout << "Priority Queue: ";
    for (int i = PQ.front; i <= PQ.rear; i++) {
        cout << PQ.data[i] << " ";
    }
    cout << endl;
}

/* Main Function */
int main() {
    Initialize();

    EnQueue(40);
    EnQueue(30);
    EnQueue(60);
    EnQueue(10);
    EnQueue(50);

    Display();

    cout << "Deleted: " << DeQueue() << endl;
    Display();

    cout << "Deleted: " << DeQueue() << endl;
    Display();

    return 0;
}
