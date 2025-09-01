#include<iostream>
#include<vector>
using namespace std;

void traverseArray(vector<int> &X){
    for(int i=0;i<X.size();i++){
        cout<<X[i]<<" ";
    }
    cout << endl;
}
vector<int> unionArray(vector<int>& A, vector<int>& B, int m, int n){
    int i=0, j=0;
    vector<int> C;
    while(i<m && j<n){
        if(A[i] < B[j]){
            C.push_back(A[i]);
            i++;
        }
        else if(A[i] > B[j]){
            C.push_back(B[j]);
            j++;
        }
        else{
            C.push_back(A[i]);
            i++;
            j++;
        }
    }
    // Push remaining elements
    while(i<m){
        C.push_back(A[i]);
        i++;
    }
    while(j<n){
        C.push_back(B[j]);
        j++;
    }
    return C;
}