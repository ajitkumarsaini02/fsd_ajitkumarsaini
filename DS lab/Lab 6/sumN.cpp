#include<iostream>
using namespace std;
int sum(int n){
    if(n==0) return 0;
    return n+sum(n-1);
}
int main(){
    int a;
    cout<<"Enter number:";
    cin>>a;
    cout<<sum(a);
    return 0;
}