#include<iostream>
#include<vector>
using namespace std;
void traverseArray(vector<int> &X){
    for(int i=0;i<X.size();i++){
        cout<<X[i]<<" ";
    }
    cout << endl;
}
void insertArray(vector<int>&A, int pos, int x){
    A.push_back(0);
    for(int i=A.size()-1;i>=pos;i--){
        A[i]=A[i-1];
    }
    A[pos-1]=x;
    
}
int main()
{
    int n,x,pos;
    cout<<"Enter the size of array: ";
    cin >>n;
    cout<<"Enter element of array: ";
    vector<int> A;
    for(int i=0;i<n;i++){
       int t;
       cin>>t;
       A.push_back(t);
    }
    cout<<"Enter the element to be insert in an array:";
    cin>>x;
    cout<<"Enter the position of element : ";
    cin>>pos;
    insertArray(A,pos,x);
    cout <<"After insertion in an array: ";
    
    traverseArray(A);

    return 0;
}