#include<iostream>
#include<climits>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int nearestPrime(int n) {
    while (n > 1 && !isPrime(n))
        n--;
    return n;
}

int DivisionHash(int n, int size) {
    int p = nearestPrime(size);
    return n % p;
}

int main() {
    int key, size;

    cout << "Enter table size: ";
    cin >> size;

    cout << "Enter key to hash: ";
    cin >> key;

    int index = DivisionHash(key, size);

    cout << "Nearest prime used: " << nearestPrime(size) << endl;
    cout << "Hash index = " << index << endl;

    return 0;
}
