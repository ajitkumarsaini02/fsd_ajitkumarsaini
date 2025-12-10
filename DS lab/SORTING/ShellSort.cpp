#include <iostream>
using namespace std;

void shellSort(int a[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j = i;
            while (j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
}

int main() {
    int a[] = {23, 12, 1, 8, 34, 54, 2, 3};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    shellSort(a, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << (i+1==n ? "\n" : " ");
    return 0;
}
