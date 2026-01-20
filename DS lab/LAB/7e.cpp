#include <iostream>
using namespace std;

void countingSortByDigit(int A[], int n, int exp) {
    int *B = new int[n];
    int C[10] = {0};

    for (int j = 0; j < n; j++)
        C[(A[j] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        C[i] += C[i - 1];

    for (int j = n - 1; j >= 0; j--) {
        int d = (A[j] / exp) % 10;
        B[C[d] - 1] = A[j];
        C[d]--;
    }

    for (int i = 0; i < n; i++)
        A[i] = B[i];

    delete[] B;
}

int getMax(int A[], int n) {
    int mx = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > mx) mx = A[i];
    return mx;
}

void radixSort(int A[], int n) {
    int mx = getMax(A, n);
    for (int exp = 1; mx / exp > 0; exp *= 10)
        countingSortByDigit(A, n, exp);
}

int main() {
    int A[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";

    radixSort(A, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << "\n";

    return 0;
}
