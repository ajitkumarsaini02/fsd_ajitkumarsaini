#include <iostream>
using namespace std;

int IndexedSequentialSearch(int A[], int N, int x) {
    int low = 0;
    int high = N - 1;
    if (x < A[low] || x > A[high])
        return -1;
    int i = low;
    while (i < N && x > A[i]) {
        i = i + 4;
    }
    if (i < N && x == A[i])
        return i;
    int li=i-1;
    int fi=i-4+1;
    for (int j = fi; j <= li; j++) {
        if (A[j] == x)
            return j;
    }
    return -1;
}

int main() {
    int A[] = {2, 5, 7, 9, 12, 17, 21, 25, 29, 33};
    int N = sizeof(A) / sizeof(A[0]);
    cout << "Elements of the array: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    int x;
    cout << endl << "Enter the element to be searched: ";
    cin >> x;

    int index = IndexedSequentialSearch(A, N, x);

    if (index != -1)
        cout << "Element found at index: " << index;
    else
        cout << "Element not found";

    return 0;
}
