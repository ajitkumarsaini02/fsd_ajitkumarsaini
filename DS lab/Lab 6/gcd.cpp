#include<iostream>
using namespace std;
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int a,b;
    cout<<"Enter base number:";
    cin>>a;
    cout<<"Enter power number:";
    cin>>b;
    cout<<gcd(a,b);
    return 0;
}