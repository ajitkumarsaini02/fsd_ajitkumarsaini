#include<iostream>
#define STACKSIZE 10
using namespace std;

struct stack {
    char item[STACKSIZE];
    int top;
} S;

void Initialize() {
    S.top = -1;
}

bool IsEmpty() {
    if (S.top == -1) {
        return true;
    } else {
        return false;
    }
}

void push(char x) {
    if (S.top == STACKSIZE - 1) {
        cout << "Stack overflow" << endl;
        exit(1);
    } else {
        S.top += 1;
        S.item[S.top] = x;
    }
}

char pop() {
    if (IsEmpty()) {
        cout << "Stack underflow" << endl;
        exit(1);
    } else {
        char x = S.item[S.top];
        S.top -= 1;
        return x;
    }
}

char stackTop() {
    if (IsEmpty()) {
        cout << "Stack is empty" << endl;
        exit(1);
    }
    return S.item[S.top];
}
void balanceBracket(char exp[]){
    Initialize();
    int i=0,flag=0;
    while(exp[i]!='\0'){
        if(exp[i]=='['){
            push(exp[i]);
        }
        else{
            if(!IsEmpty()){
                pop();
            }
            else{
                flag=1;
                break;
            }
        }
        i+=1;
    }
    if(IsEmpty()){
        if(flag==1){
            cout<<"Invalid Expression:"<<endl;
        }
        else{
            cout<<"Valid expression:"<<endl;
        }
    }
    else{
        cout<<"Invalid Expression:"<<endl;
    }
}
int main(){
    char exp[100];
    cout<<"Enter the expression:";
    cin>>exp;
    balanceBracket(exp);
    return 0;

}