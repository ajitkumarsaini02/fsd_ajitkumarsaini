#include<iostream>
#define STACKSIZE 10
using namespace std;

struct stack {
    int item[STACKSIZE];
    int top;
} S;

void Initialize() {
    S.top = -1;
}

bool IsEmpty() {
    if (S.top == -1) {
        return true;
    } else {
        return false;
    }
}

void push(int x) {
    if (S.top == STACKSIZE - 1) {
        cout << "Stack overflow" << endl;
        exit(1);
    } else {
        S.top += 1;
        S.item[S.top] = x;
    }
}

int pop() {
    if (IsEmpty()) {
        cout << "Stack underflow" << endl;
        exit(1);
    } else {
        int x = S.item[S.top];
        S.top -= 1;
        return x;
    }
}

int stackTop() {
    if (IsEmpty()) {
        cout << "Stack is empty" << endl;
        exit(1);
    }
    return S.item[S.top];
}

void decimalToOctal(int n) {
    Initialize();
    
    while (n != 0) {
        int r = n % 8;
        n /= 8;
        push(r);
    }
    while (!IsEmpty()) {
        int x = pop();
        cout<<x;
    }
}

int main() {
    int number = 123;
    cout << "Decimal " << number << " in  " << 8<< " is: ";
    decimalToOctal(number);
    cout << endl;

    number = 255;
    cout << "Decimal " << number << " in  " << 8<< " is: ";
    decimalToOctal(number);
    cout << endl;

    return 0;
}
