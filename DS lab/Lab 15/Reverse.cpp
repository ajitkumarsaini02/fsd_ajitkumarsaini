#include<iostream>
#include<stdlib.h>
#include"LinkedListheader.h"
using namespace std;

int main(){
    Node *Start=NULL;
    InsBeg(&Start,'A');
    InsBeg(&Start,'B');
    InsBeg(&Start,'C');
    InsEnd(&Start,'X');
    InsEnd(&Start,'Y');
    InsEnd(&Start,'Z');
    cout<<"Original List: ";
    Traverse(Start);
    ReverseList(&Start);
    cout<<"Reversed List: ";
    Traverse(Start);
    return 0;
}