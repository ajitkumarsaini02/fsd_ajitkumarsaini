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
void reverseArray(vector<int> &A){
    int i=0;
    int j=A.size()-1;
    while(i<j){
        int t=A[i];
        A[i]=A[j];
        i++;
        j--;

    }
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
    
   
    
    reverseArray(A);
    
    cout << "After insertion, the sorted array is: ";
    traverseArray(A);
    
    return 0;
}
