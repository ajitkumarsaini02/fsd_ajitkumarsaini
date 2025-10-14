#include<iostream>
#include<stdlib.h>
#define MAXQUEUE 10
using namespace std;
struct Queue{
    char item[MAXQUEUE];
    int Rear;
    int Front;
};

void Initialize(Queue *Q){
    Q->Front=0;
    Q->Rear=-1;
}
bool IsEmpty(Queue *Q){
    if(Q->Rear-Q->Front+1==0){
        return true;
    }
    else{
        return false;   
    }
}
void EnQueue(Queue *Q,char x){
    if(Q->Rear==MAXQUEUE-1){
        cout<<"Queue Overflow";
        exit(1);
    }
    else{
        Q->Rear=Q->Rear+1;
        Q->item[Q->Rear]=x;
    }
}
char DeQueue(Queue *Q){
    if(IsEmpty(Q)){
       cout<<"Queue Underflow"; 
       exit(1);
    }
    else{
        char x=Q->item[Q->Front];
        Q->Front=Q->Front+1;
        return x;
    }
}
