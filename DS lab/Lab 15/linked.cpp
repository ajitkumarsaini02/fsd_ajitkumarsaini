#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
    char info;
    struct Node *Next;
};
struct Node *Start;
Node *GetNode(){
    Node *p;
    p=(Node*)malloc(sizeof(struct Node));
    return p;
}
void InsBeg(char x){
    Node *p=GetNode();
    p->info=x;
    p->Next=Start;
    Start=p;
}
void Traverse() {   
    Node *p = Start;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->Next;
    }
    cout << endl;
}
int main(){
      Start=NULL;
      InsBeg('A');
      InsBeg('B');
      InsBeg('C');
      InsBeg('D');
      InsBeg('E');
      Traverse();

}
