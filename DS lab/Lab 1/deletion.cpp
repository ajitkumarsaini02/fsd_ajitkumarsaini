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
    int x=A[pos];
    for(int i=pos-1;i<A.size()-1;i++){
        A[i]=A[i+1];
    }
    A.pop_back();
    
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
    cout<<"Enter the position where the element is deleted :";
    cin>>pos;
    if(pos<1 || pos>A.size()){
        cout<<"Invalid position:" <<endl;
        return 0;
    }
    deleteArray(A,pos);
    cout<<"After deletion of an array: ";
    traverseArray(A);
    return 0;

}