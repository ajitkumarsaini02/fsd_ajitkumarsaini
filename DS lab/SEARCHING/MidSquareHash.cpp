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
    int d=pow(10,x);
    y/=d;
    int l=y%a;
    return l;
}
int main(){

    cout<<MidSquareHash(1692,100);
}