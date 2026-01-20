#include <iostream>
using namespace std;

/* Heapify function */
void heapify(int A[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != i) {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        heapify(A, n, largest);
    }
}

/* Heap Sort */
void heapSort(int A[], int n) {
    int i, temp;

    /* Build Max Heap */
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);

    /* Extract elements */
    for (i = n - 1; i > 0; i--) {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        heapify(A, i, 0);
    }
}

int main() {
    int A[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    heapSort(A, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}

