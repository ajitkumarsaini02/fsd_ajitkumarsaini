// Evaluate postfix expression
#include<iostream>
#define STACKSIZE 10
#include<math.h>
using namespace std;
struct stack{
    int item[STACKSIZE];
    int top;
}S;

void Initialize(){
    S.top=-1;
}
bool IsEmpty(){
    if (S.top==-1){
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
int Evaluate(int x, int y, char symbol){
    switch(symbol){
        case '+': return x+y;
        case '-': return x-y;
        case '*': return x*y;
        case '/': return x/y;
        case '^': return pow(x,y);
    }
}
 void postfixEvaluation(char postfix[]){
        int i=0;
        Initialize();
        while(postfix[i]!='\0'){
            char symbol=postfix[i];
            if(symbol>='0' && symbol<='9')
               push(symbol-'0');
            else{
                int y=pop();
                int x=pop();
                int value = Evaluate(x,y,symbol);
                push(value);
            }  
           i++;

        }
        cout<<pop()<<endl;
    }
int main(){
    char expression[100];
    cout<<"Enter expression:";
    cin>>expression;
    postfixEvaluation(expression);
    cout <<endl;
    return 0;
    
}