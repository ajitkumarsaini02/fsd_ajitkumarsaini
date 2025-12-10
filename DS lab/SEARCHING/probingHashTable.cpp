#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int findNearestPrime(int n) {
    for(int num = n; num > 1; num--) {
        bool ok = true;
        for(int i = 2; i * i <= num; i++)
            if(num % i == 0) {
                ok = false;
                break; 
            }
        if(ok) return num;
    }
    return 2;
}

int DivisionHash(int key, int size) {
    int p = findNearestPrime(size);
    if(key < 0) key = -key;
    return key % p;
}

long long MidSquareHash(long long key, int size) {
    if(key < 0) key = -key;
    long long sq = key * key;
    return (sq / 100) % size;
}

int FoldingHash(int key, int size) {
    if(key < 0) key = -key;
    int sum = 0;
    while(key > 0) {
        sum += key % 100;
        key /= 100;
    }
    return sum % size;
}

int ReverseFoldingHash(int key, int size) {
    if(key < 0) key = -key;
    string s = to_string(key);
    reverse(s.begin(), s.end());
    int num = stoi(s);
    return num % size;
}
int main() {
    int size, key;

    cout << "Enter table size: ";
    cin >> size;

    cout << "Enter key: ";
    cin >> key;

    int table[size];
    for(int i = 0; i < size; i++) table[i] = INT_MIN;

    int h1 = DivisionHash(key, size);
    int h2 = MidSquareHash(key, size);
    int h3 = FoldingHash(key, size);
    int h4 = ReverseFoldingHash(key, size);

    cout << "Division Hash index: " << h1 << endl;
    cout << "Mid Square Hash index: " << h2 << endl;
    cout << "Folding Hash index: " << h3 << endl;
    cout << "Reverse Folding Hash index: " << h4 << endl;

    return 0;
}