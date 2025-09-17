#include <iostream>
using namespace std;

#define MAX 50  
#define M 3      

struct MultiStack {
    int arr[MAX];   
    int top[M];     
    int n, m;       
} s;  


void Initialize() {
    for (int i = 0; i < s.m; i++) {
        s.top[i] = i * (s.n / s.m) - 1;  
    }
}


void Push(int i, int x) {
    if (s.top[i] == (i + 1) * (s.n / s.m) - 1) {
        cout << "Stack Overflow in stack " << i << endl;
        return;
    } else {
        s.top[i]++;
        s.arr[s.top[i]] = x;
    }
}


int Pop(int i) {
    if (s.top[i] == i * (s.n / s.m) - 1) {
        cout << "Stack Underflow in stack " << i << endl;
        return -1;
    } else {
        int x = s.arr[s.top[i]];
        s.top[i]--;
        return x;
    }
}

int main() {
    s.n = MAX;  
    s.m = M;    

    Initialize();

    // Example usage
    Push(0, 10);
    Push(0, 20);
    Push(1, 100);

    cout << "Popped from stack 0: " << Pop(0) << endl;
    cout << "Popped from stack 1: " << Pop(1) << endl;

    return 0;
}
