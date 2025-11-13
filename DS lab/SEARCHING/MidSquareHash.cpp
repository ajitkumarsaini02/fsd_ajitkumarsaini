#include<iostream>
#include<climits>
#include<math.h>
#include<algorithm>
using namespace std;

int pow(int a,int x){
    int power=1;
    for(int i=1;i<=x;i++){
        power*=a;
    }
    return power;
}

int digit(int k){
    if(k==0) return 1;
    int count=0;
    while(k>0){
        k/=10;
        count++;
    }
    return count;
}

int MidSquareHash(int k,int size){
    int y;
    int m=digit(size-1);
    int a=pow(10,m);
    y=k*k;
    int n=digit(k);
    int x=(2*n-m)/2;
    if(x<0) x=0;
    int d=pow(10,x);
    y/=d;
    int l=y%a;
    return l;
}

int main(){
    int key,size;

    cout<<"Enter table size: ";
    cin>>size;

    cout<<"Enter key: ";
    cin>>key;

    cout<<"Mid-Square Hash: "<<MidSquareHash(key,size)<<endl;

    return 0;
}
