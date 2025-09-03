#include<iostream>
#include<vector>
using namespace std;
void traverseArray(vector<int> &X){
    for(int i=0;i<X.size();i++){
        cout<<X[i]<<" ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin >>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin >>A[i];
    }
    cout <<"Traverse of an array:";
    traverseArray(A);

    return 0;
}