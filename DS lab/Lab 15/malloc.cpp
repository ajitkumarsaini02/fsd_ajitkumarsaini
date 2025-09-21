#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
    int *ptr;
    int x=10;
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    ptr = (int*)malloc(sizeof(int) *n);
    for(int i=0;i<n;i++){
        *(ptr+i) = x;
        x=x+10;
    }
    for(int i=0;i<n;i++){
        cout<<*(ptr+i)<<" ";
    }
    
}