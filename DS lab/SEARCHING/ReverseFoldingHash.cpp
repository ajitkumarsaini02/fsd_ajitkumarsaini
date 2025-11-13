#include <iostream>
using namespace std;

int pow10(int d){
    int p = 1;
    while(d--) p *= 10;
    return p;
}

int digitCount(long long n){
    if(n == 0) return 1;
    int c = 0;
    if(n < 0) n = -n;
    while(n > 0){
        n /= 10;
        c++;
    }
    return c;
}

int ReverseFoldingHash(long long N,int TS){
    int d = digitCount(TS - 1);
    if(d <= 0) d = 1;
    long long n = N < 0 ? -N : N;
    int total = digitCount(n);
    int s = 0;
    while(total > 0){
        int blockSize = (total % d == 0) ? d : (total % d);
        int powRight = pow10(total - blockSize);
        int block = int(n / powRight);
        s += block;
        n = n % powRight;
        total -= blockSize;
        if(n == 0) break;
    }
    return s % TS;
}

int main(){
    long long N;
    int TS;
    cout<<"Enter key (N): ";
    cin>>N;
    cout<<"Enter table size (TS): ";
    cin>>TS;
    cout<<"Reverse Folding Hash index: "<<ReverseFoldingHash(N,TS);
    return 0;
}
