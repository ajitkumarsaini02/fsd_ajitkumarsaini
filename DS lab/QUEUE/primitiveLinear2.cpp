#include<iostream>
#include<stdlib.h>
#include"QueueHeader.h"
#define MAXQUEUE 10
using namespace std;
int main(){
    Queue Q;
    Initialize(&Q);
    EnQueue(&Q,'A');
    EnQueue(&Q,'B');
    EnQueue(&Q,'C');
    EnQueue(&Q,'D');
    EnQueue(&Q,'E');
    EnQueue(&Q,'F');
    char x=DeQueue(&Q);
    cout<<"Deleted item :"<<x<<endl;
    x=DeQueue(&Q);
    cout<<"Deleted item :"<<x<<endl;
    x=DeQueue(&Q);
    cout<<"Deleted item :"<<x<<endl;
    x=DeQueue(&Q);
    cout<<"Deleted item :"<<x<<endl;
    x=DeQueue(&Q);
    cout<<"Deleted item :"<<x<<endl;
    x=DeQueue(&Q);
    cout<<"Deleted item :"<<x<<endl;
    x=DeQueue(&Q);
    cout<<"Deleted item :"<<x<<endl;
}