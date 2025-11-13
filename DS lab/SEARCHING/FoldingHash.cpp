#include <iostream>
using namespace std;

int pow10(int d){
    int p = 1;
    while(d--) p *= 10;
    return p;
}

int digit(int n){
    int c = 0;
    while(n > 0){
        n /= 10;
        c++;
    }
    return c;
}

int FoldingHash(int N, int TS){
    int d = digit(TS - 1);
    int m = pow10(d);
    int s = 0;
    int n = N;
    while(n != 0){
        int r = n % m;
        s = s + r;
        n = n / m;
    }
    int L = s % TS;
    return L;
}

int main(){
    int N, TS;
    cout << "Enter key (N): ";
    cin >> N;
    cout << "Enter table size (TS): ";
    cin >> TS;
    cout << "Folding Hash index: " << FoldingHash(N, TS);
    return 0;
}
