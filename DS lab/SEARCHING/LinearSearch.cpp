#include<iostream>
using namespace std;

int LinearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

void showResult(int arr[], int n, int key) {
    int index = LinearSearch(arr, n, key);
    cout << "Search " << key << " -> Index: " << index << endl;
}

int main() {
    int arr[] = {5, 3, 1, 4, 2};
    int n = 5;
    cout << "Array elements: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nMore Searching Tests:\n";
    showResult(arr, n, 1);
    showResult(arr, n, 4);
    showResult(arr, n, 5);
    showResult(arr, n, 10);
    return 0;
}
