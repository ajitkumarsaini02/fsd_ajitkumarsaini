#include<iostream>
#include<vector>
using namespace std;

// Function to print repeated elements
void printRepeatedElements(vector<int>& A) {
    cout << "Repeated elements are: ";

    for(int i = 0; i < A.size(); i++){
        int count = 0;

        for(int j = 0; j < A.size(); j++){
            if(A[i] == A[j]){
                count++;
            }
        }

        int j;
        for(j = 0; j < i; j++){
            if(A[j] == A[i]){
                break;
            }
        }

        // If repeated and first time being printed
        if(count > 1 && j == i){
            cout << A[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    printRepeatedElements(A);

    return 0;
}
