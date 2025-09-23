#include<iostream>
#include<stdlib.h>
#include"LinkedListheader.h"
using namespace std;


int main() {
    Node *Start = NULL;
    InsBeg(&Start,'A');
    InsBeg(&Start,'B');
    InsBeg(&Start,'C');
    InsBeg(&Start,'F');
    InsBeg(&Start,'G');
    InsBeg(&Start,'H');
    cout << "List after InsBeg: ";
    Traverse(Start);

    InsAfter(&Start, Start->Next,'D');
    InsAfter(&Start, Start->Next,'E');
    InsAfter(&Start, Start->Next,'F');

    cout << "Linked List: ";
    Traverse(Start);

    return 0;
}