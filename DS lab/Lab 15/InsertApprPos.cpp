#include<iostream>
#include<stdlib.h>
#include"LinkedListheader.h"
using namespace std;
int main(){
    Node *Start = NULL;
    InsBeg(&Start,'Z');
    orderedInsert(&Start,'D');
    orderedInsert(&Start,'B');  
    orderedInsert(&Start,'A');
    orderedInsert(&Start,'C');
    orderedInsert(&Start,'F');
    orderedInsert(&Start,'E');
    cout<<"Ordered Insertion: ";
    Traverse(Start);
    InsBeg(&Start,'X');
    cout<<"After Inserting at Beginning: ";
    Traverse(Start);
    cout<<"Count Nodes:"<<CountNode(Start);
    
    return 0;

}