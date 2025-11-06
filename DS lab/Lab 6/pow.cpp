#include<iostream>
using namespace std;
int pow(int a, int b){
    if(b==0) return 1;
    else return a*pow(a,b-1);
}
int main(){
    int a,b;
    cout<<"Enter base number:";
    cin>>a;
    cout<<"Enter power number:";
    cin>>b;
    cout<<pow(a,b);
    return 0;
}