#include <iostream>
using namespace std;

int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high + 1;
    int temp;

    while (1) {
        do {
            i++;
        } while (i <= high && A[i] < pivot);

        do {
            j--;
        } while (A[j] > pivot);

        if (i >= j)
            break;

        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int p = partition(A, low, high);
        quickSort(A, low, p - 1);
        quickSort(A, p + 1, high);
    }
}

int main() {
    int A[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    quickSort(A, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}
