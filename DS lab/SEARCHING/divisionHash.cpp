#include<iostream>
#include<climits>
using namespace std;

int findNearestPrime(int n) {
    for (int num = n; num > 1; num--) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            return num;
    }
    return 2;
}

int DivisionHash(int n, int size) {
    int p = findNearestPrime(size);
    return n % p;
}

int main() {
    int key, size;

    cout << "Enter table size: ";
    cin >> size;

    cout << "Enter key to hash: ";
    cin >> key;

    int index = DivisionHash(key, size);

    cout << "Nearest prime used: " << findNearestPrime(size) << endl;
    cout << "Hash index = " << index << endl;

    return 0;
}
