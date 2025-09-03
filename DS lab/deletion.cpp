#include<iostream>
#include<vector>
using namespace std;
void traverseArray(vector<int> &X){
    for(int i=0;i<X.size();i++){
        cout<<X[i]<<" ";
    }
    cout << endl;
}
void deleteArray(vector<int>&A, int pos){
    int x=A[pos]
    for(int i=A.size()-1;i>=pos;i--){
        A[i]=A[i-1];
    }
    A[pos-1]=x;
    
}