#include<iostream>
using namespace std;
int binary(int a, int n){
    if(n==0) return 1;
    else{
        int x=binary(a,n/2);
        if(n%2==0) return x*x;
        else return a*x*x;
    }
}
int main(){
    int a,b;
    cout<<"Enter base number:";
    cin>>a;
    cout<<"Enter power number:";
    cin>>b;
    cout<<binary(a,b);
    return 0;
}