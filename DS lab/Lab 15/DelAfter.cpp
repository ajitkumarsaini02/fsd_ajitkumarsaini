#include<iostream>
#include<stdlib.h>
#include"LinkedListheader.h"
using namespace std;

int main() {
    
    Node *Start = NULL;
   

    // Insert nodes at beginning
    InsBeg(&Start,'A');
    InsBeg(&Start,'B');
    InsBeg(&Start,'C');
    InsBeg(&Start,'D');
    InsBeg(&Start,'E'); 
    cout << "List after InsBeg: ";
    Traverse(Start);

    // Insert nodes at end
    InsEnd(&Start,'X');
    InsEnd(&Start,'Y');
    InsEnd(&Start,'Z'); 
    cout << "List after InsEnd: ";
    Traverse(Start);
    cout<<"Deleted Element is: "<<DelAfter(&Start,Start)<<endl;
     Traverse(Start);
    cout<<"Deleted Element is: "<<DelBeg(&Start)<<endl;
     Traverse(Start);
    return 0;
} 