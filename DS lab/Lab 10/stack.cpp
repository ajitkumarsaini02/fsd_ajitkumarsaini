#include<iostream>
#define STACKSIZE 10
using namespace std;
struct stack{
    int item[STACKSIZE];
    int top;
}S;

void Initialize(){
    S.top=-1;
}
bool IsEmpty(){
    if (S.top=-1){
        return true;
    }
    else{
        return false;
    }
}
int push(int x){
    if(S.top==STACKSIZE-1){
        cout<<"Stack overflow";
        exit(1);
    }
    else{
        S.top+=1;
        S.item[S.top]=x;
    }
}
int pop(){
    if(IsEmpty()){
        cout<<"Stack underflow";
        exit(1);
    }
    else{
        int x=S.item[S.top];
        S.top-=1;
        return x;
    }
}
int stackTop(){
    return S.item[S.top];
}
int main(){
    
    Initialize();
    push(100);
    push(200);
    push(300);
    push(400);
    push(500);
    push(600);
    push(700);
    push(800);
    push(900);
    push(1000);

    for(int i=0;i<STACKSIZE;i++){
        cout<<S.item[i]<<endl;

    }
   


    return 0;
}