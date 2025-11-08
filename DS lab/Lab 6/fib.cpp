#include<iostream>
using namespace std;
int fib(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    return fib(n-1)+fib(n-2);
}
int main(){
    int a,b;
    cout<<"Enter number:";
    cin>>a;
    cout<<fib(a);
    return 0;
}