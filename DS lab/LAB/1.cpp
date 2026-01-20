// EXPERIMENT: 1
// ARRAY INSERTION, DELETION, TRAVERSAL

#include <iostream>
using namespace std;

void traverseArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void deleteArray(int A[], int &n, int pos) {
    for (int i = pos - 1; i < n - 1; i++) {
        A[i] = A[i + 1];
    }
    n--;   // reduce size by 1
}

void insertArray(int A[], int &n, int pos, int x) {
    for (int i = n; i >= pos; i--) {
        A[i] = A[i - 1];
    }
    A[pos - 1] = x;
    n++;   // increase size by 1
}

int main() {
    int n, x, pos, delPos;
    int A[100];   // static array

    cout << "Enter the size of array: ";
    cin >> n;

    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "\nEnter the element to be inserted in the array: ";
    cin >> x;

    cout << "Enter the position of element: ";
    cin >> pos;

    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position!" << endl;
        return 0;
    }

    insertArray(A, n, pos, x);
    cout << "After insertion: ";
    traverseArray(A, n);

    cout << "\nEnter the position to delete: ";
    cin >> delPos;

    if (delPos < 1 || delPos > n) {
        cout << "Invalid position!" << endl;
        return 0;
    }

    deleteArray(A, n, delPos);
    cout << "After deletion: ";
    traverseArray(A, n);

    return 0;
}
