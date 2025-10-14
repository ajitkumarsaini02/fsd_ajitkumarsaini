#include<iostream>
#include<stdlib.h>
#define MAXQUEUE 10
using namespace std;
struct CQueue{
    char item[MAXQUEUE];
    int Rear;
    int Front;
};
CQueue CQ;
void Initialize(){
    CQ.Front=MAXQUEUE-1;
    CQ.Rear=MAXQUEUE-1;
}
bool IsEmpty(){
    if(CQ.Rear==CQ.Front){
        return true;
    }
    else{
        return false;   
    }
}
void EnQueue(char x){
    if((CQ.Rear+1)%MAXQUEUE==CQ.Front){
        cout<<"Queue Overflow";
        exit(1);
    }
    else{
        CQ.Rear=(CQ.Rear+1)%MAXQUEUE;
        CQ.item[CQ.Rear]=x;
    }
}
char DeQueue(){
    if(IsEmpty()){
       cout<<"Queue Underflow"; 
       exit(1);
    }
    else{
        CQ.Front=(CQ.Front+1)%MAXQUEUE;
        char x=CQ.item[CQ.Front];
        return x;
    }
}

int main(){
    Initialize();
    EnQueue('A');
    EnQueue('B');
    EnQueue('C');
    EnQueue('D');
    EnQueue('E');
    EnQueue('F');
    char x=DeQueue();
    cout<<"Deleted item :"<<x<<endl;
    x=DeQueue();
    cout<<"Deleted item :"<<x<<endl;
    x=DeQueue();
    cout<<"Deleted item :"<<x<<endl;
    x=DeQueue();
    cout<<"Deleted item :"<<x<<endl;
    x=DeQueue();
    cout<<"Deleted item :"<<x<<endl;
    x=DeQueue();
    cout<<"Deleted item :"<<x<<endl;
    x=DeQueue();
    cout<<"Deleted item :"<<x<<endl;
}