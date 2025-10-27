#include <iostream>
#include <vector>
using namespace std;

void traverseArray(vector<int> &X) {
    for (int i = 0; i < X.size(); i++) {
        cout << X[i] << " ";
    }
    cout << endl;
}

void deleteArray(vector<int>& A, int pos) {
    for (int i = pos; i < A.size() - 1; i++) {
        A[i] = A[i + 1];
    }
    A.pop_back();
}

void insertSortedArray(vector<int>& A, int x) {
    int i = 0;
    while (i < A.size() && x >= A[i]) {
        i++;
    }
    A.insert(A.begin() + i, x);
}

void EnQueue(vector<int>& A, int x) {
    insertSortedArray(A, x);
}

int DeQueue(vector<int>& A) {
    if (A.empty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int x = A[0];
    deleteArray(A, 0);
    return x;
}

int main() {
    vector<int> A;
    int n, x;

    cout << "Enter the size of array: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        EnQueue(A, x);
        cout << "After EnQueue: ";
        traverseArray(A);
    }

    cout << "\nDequeuing elements: " << endl;
    while (!A.empty()) {
        cout << "Dequeued: " << DeQueue(A) << endl;
        cout << "Queue: ";
        traverseArray(A);
    }
}
