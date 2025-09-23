#include <iostream>
#include <stdlib.h>
#include"LinkedListheader.h"
using namespace std;


int main(){
    Node *Start = NULL;

    InsBeg(&Start,'A');
    InsBeg(&Start,'B');
    InsBeg(&Start,'C');  

    InsEnd(&Start,'X');
    InsEnd(&Start,'Y');
    InsEnd(&Start,'Z');

    Traverse(Start);
    cout << "Number of nodes: " << CountNode(Start) << endl;

    return 0;
}