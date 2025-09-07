#include<iostream>
#include<vector>
using namespace std;

// Function to display the array
void traverseArray(vector<int> &A){
    for(int i = 0; i < A.size(); i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

// Function to insert an element into a sorted array
void insertSortedArray(vector<int>& A, int x){
    int i = 0;
    // Find the correct position to insert x
    while(i <= A.size() - 1 && x >= A[i]){
        i++;
    }
    
    // Insert x at position i
    A.insert(A.begin() + i, x);
}

int main(){
    int n, x;
    
    cout << "Enter the size of the sorted array: ";
    cin >> n;
    
    cout << "Enter elements of the sorted array in increasing order: ";
    vector<int> A;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        A.push_back(t);
    }
    
    cout << "Enter the element to be inserted: ";
    cin >> x;
    
    insertSortedArray(A, x);
    
    cout << "After insertion, the sorted array is: ";
    traverseArray(A);
    
    return 0;
}
