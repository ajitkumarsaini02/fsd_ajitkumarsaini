#include<iostream>
#include<stdlib.h>
#include"LinkedListheader.h"
using namespace std;


int main() {
    Node *Start = NULL;
    InsBeg(&Start, 'X');
    InsBeg(&Start, 'Y');
    InsBeg(&Start, 'Z');
    cout << "Linked List: ";
    Traverse(Start);
    cout << "After inserting at the end: ";
    InsEnd(&Start, 'A');
    InsEnd(&Start, 'B');    
    InsEnd(&Start, 'C');
    InsEnd(&Start, 'D');
    cout << "Linked List: ";
    Traverse(Start);

    return 0;
}
