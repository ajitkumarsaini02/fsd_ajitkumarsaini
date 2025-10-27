// Array implementation on stack 
#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10

// Stack structure
struct stack {
    int item[STACKSIZE];
    int top;
} S;

// Initialize stack
void Initialize() {
    S.top = -1;
}

// Check if stack is empty
int IsEmpty() {
    if (S.top == -1)
        return 1;
    else
        return 0;
}

// Push operation
void push(int x) {
    if (S.top == STACKSIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    } else {
        S.top += 1;
        S.item[S.top] = x;
    }
}

// Pop operation
int pop() {
    if (IsEmpty()) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        int x = S.item[S.top];
        S.top -= 1;
        return x;
    }
}

// Return top element
int stackTop() {
    return S.item[S.top];
}

int main() {
    Initialize();

    push(100);
    push(200);
    push(300);
    push(400);
    push(500);
    push(600);
    push(700);
    push(800);
    push(900);
    push(1000);

    printf("Stack elements:\n");
    for (int i = 0; i < STACKSIZE; i++) {
        printf("%d\n", S.item[i]);
    }

    printf("Pop: %d\n", pop());
    printf("Pop: %d\n", pop());

    return 0;
}
