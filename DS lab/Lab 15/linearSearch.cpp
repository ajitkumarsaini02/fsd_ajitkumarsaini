 //     AJIT KUMAR SAINI     ROLL: 2400320100114
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node {
    char info;
    Node *Next;
};
Node *Start = NULL;
Node* GetNode() {
    Node *p = (Node*) malloc(sizeof(Node));
    return p;
}
void InsBeg(Node **Start,char x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = *Start;
    *Start = p;
}
void Traverse(Node *Start) {
    Node *p = Start;
    while (p != NULL) {
        cout << p->info<<" " ;
        p = p->Next;
    }
    cout<<endl;  
}
void InsEnd(Node **Start,char x) {
    Node *p = GetNode();
    p->info = x;
    p->Next = NULL;
    if (*Start == NULL) {
        *Start = p;
        return ;
    }
    Node *q = *Start;
    while (q->Next != NULL) {
       q = q->Next;
    }
    q->Next = p;
}
int LinearSearch(Node* Start, int key) {
    int pos = 0;
    while (Start) {
        if (Start->info== key) return pos; 
        Start = Start->Next;
        pos++;
    }
    return -1; 
}

int main(){
    InsBeg(&Start,'A');
    InsBeg(&Start,'B');
    InsBeg(&Start,'C');
    InsBeg(&Start,'D');
    InsBeg(&Start,'E'); 
    cout << "List after InsBeg: ";
    Traverse(Start);
    InsEnd(&Start,'X');
    InsEnd(&Start,'Y');
    InsEnd(&Start,'Z'); 
    cout << "List after InsEnd: ";
    Traverse(Start);
    char key;
    cout << "Enter value to search: ";
    cin >> key;
    cout << ((LinearSearch(Start, key) != -1) ? "Found" : "Not Found") << endl;
}