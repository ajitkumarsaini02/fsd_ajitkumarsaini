#include<iostream>
#define STACKSIZE 10
using namespace std;

struct twoStack {
    int arr[STACKSIZE];
    int top1, top2;
} s;   

void Initialize() {
    s.top1 = -1;
    s.top2 = STACKSIZE;
}

void push1(int x) {
    if (s.top1 == s.top2 - 1) {
        cout << "Stack Overflow in Stack 1\n";
        exit(1);
    } else {
        s.top1++;
        s.arr[s.top1] = x;
    }
}

void push2(int x) {
    if (s.top1 == s.top2 - 1) {
        cout << "Stack Overflow in Stack 2\n";
        exit(1);
    } else {
        s.top2--;
        s.arr[s.top2] = x;
    }
}

int pop1() {
    if (s.top1 == -1) {
        cout << "Stack Underflow in Stack 1\n";
        exit(1);
    } else {
        int x = s.arr[s.top1];
        s.top1--;
        return x;
    }
}

int pop2() {
    if (s.top2 == STACKSIZE) {
        cout << "Stack Underflow in Stack 2\n";
        exit(1);
    } else {
        int x = s.arr[s.top2];
        s.top2++;
        return x;
    }
}

int main() {
    Initialize(); 

    push1(5);
    push2(10);
    push2(15);
    push1(11);
    push2(7);

    cout << "Popped from stack 1: " << pop1() << endl;
    push2(40);
    cout << "Popped from stack 2: " << pop2() << endl;

    return 0;
}
