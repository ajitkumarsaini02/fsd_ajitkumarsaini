#include <iostream>
#include <stdlib.h>
#include<vector>
using namespace std;
void insertSortedArray(vector<int>& A, int x) {
    int i = 0;
    while (i < A.size() && x >= A[i]) {
        i++;
    }
    A.insert(A.begin() + i, x);
}
void traverseArray(vector<int> &X) {
    for (int i = 0; i < X.size(); i++) {
        cout << X[i] << " ";
    }
    cout << endl;
}
void EnQueue(vector<int>& A,int n, int x) {
    
    insertSortedArray(A, x);
}
int DeQueue(vector<int>& A,int n) {
    if (A.empty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int x = A[n-1];
    n=n-1;
    return x;
}

int main() {
    vector<int> A;
    int n, x;

    cout << "Enter number of elements: ";
    if (!(cin >> n)) return 0;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> x;
        EnQueue(A, (int)A.size(), x);   
        cout << "After EnQueue: ";
        traverseArray(A);
    }

    cout << "\nDequeuing elements (highest priority first):\n";
    while (!A.empty()) {
        int curSize = (int)A.size();
        int val = DeQueue(A, curSize); 
        A.pop_back();                 
        cout << "Dequeued: " << val << "\n";
        cout << "Queue now: ";
        traverseArray(A);
    }

    return 0;
}
