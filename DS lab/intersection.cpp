#include<iostream>
#include<vector>
using namespace std;

void traverseArray(vector<int> &X){
    for(int i=0;i<X.size();i++){
        cout<<X[i]<<" ";
    }
    cout << endl;
}
vector<int> intersectionArray(vector<int>& A, vector<int>& B, int m, int n){
    int i=0, j=0;
    vector<int> C;
    while(i<m && j<n){
        if(A[i] < B[j]){
            i++;
        }
        else if (B[j] <A[i]){
            j++;
        }
        else{
            C.push_back(A[i]);
            i++;
            j++;
        }
    }
   
    return C;
}
int main()
{
    int m,n;
    cout<<"Enter the size of first array: ";
    cin >> m;
    vector<int> A(m);
    for(int i=0;i<m;i++){
        cin >> A[i];
    }
    cout <<"Enter the size of second array: ";
    cin >> n;
    vector<int> B(n);
    for(int j=0;j<n;j++){
        cin >> B[j];
    }

    vector<int> C = intersectionArray(A,B,m,n);
    cout << "Intersection array: ";
    traverseArray(C);

    return 0;
}