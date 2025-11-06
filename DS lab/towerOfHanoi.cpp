#include<iostream>
#include<vector>
using namespace std;
void TOH(int n,char s,char m, char d){
    if(n==1)
        cout<<s<<"-->"<<d<<endl;
    else{
        TOH(n-1,s,d,m);
        cout<<s<<"-->"<<d<<endl;
        TOH(n-1,m,s,d);
    }    
}
int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    TOH(n,'S','M','D');
}