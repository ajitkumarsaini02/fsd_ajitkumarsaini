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

void decimalToHexaDecimal(int n, int b) {
    Initialize();
    char dat[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    while (n != 0) {
        int r = n % b;
        n /= 16;
        push(r);
    }
    while (!IsEmpty()) {
        
        int x = pop();
        cout<<dat[x];
    }
}

int main() {
    int n = 1956;
    int b;
    cout<<"Enter base :";
    cin>>b;
    cout << "Decimal " << n << " in  " << b<< " is: ";
    decimalToHexaDecimal(n, b);
    cout << endl;

    n = 255;
    cout << "Decimal " << n<< " in  " << b<< " is: ";
    decimalToHexaDecimal(n, b);
    cout << endl;

    return 0;
}
