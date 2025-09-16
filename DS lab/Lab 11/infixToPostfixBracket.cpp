// Evaluate infix to postfix parenthesis expression
#include<iostream>
#include<vector>
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
int push(char x){
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
        char x=S.item[S.top];
        S.top-=1;
        return x;
    }
}
int stackTop(){
    return S.item[S.top];
}
bool prcd(char op1, char op2){
    if(op1=='(' || op2=='('){
        return false;
    }
    else if(op2==')'){
        return true;
    }
    else if(op1=='^' || op1=='*' || op1=='/' || op1=='%'){
        if(op2=='^'){
            return false;
        }
        else{
            return true;
        }
    }
    else if(op1=='+' || op1=='-'){
        if(op2=='+' || op2=='-'){
            return true;
        }
        else{
            return false;
        }
    }
}

void infixToPostfix(char infix[]){
    Initialize();
    int i=0;
    vector<char>postfix;
    while(infix[i]!='\0'){
        char symb = infix[i];
        i++;
        if(symb>='a' && symb<='z' || symb>='A' && symb<='B' || symb>='0' && symb<='9'){
            postfix.push_back(symb);
        }
        else{
            while(!IsEmpty() && prcd(stackTop(), symb)){
                char x=pop();
                postfix.push_back(x);
            }
            if(symb!=')'){
               push(symb);
            }
            else{
                pop();
            }
            
        }  
    }
    while(!IsEmpty()){
        char x= pop();
        postfix.push_back(x);
    }
    cout<<"PostFix Expression: ";
   for(int i=0;i<postfix.size();i++){
    cout<<postfix[i];
   }
}
int main(){
    char postfix[100];
    cout<<"Enter expression:";
    cin>>postfix;
    infixToPostfix(postfix);
    cout <<endl;
    return 0;
    
}