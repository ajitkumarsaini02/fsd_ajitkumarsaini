// Evaluate  Infix to prefix expression
#include<iostream>
#include<vector>
#define STACKSIZE 10
#include<algorithm>
#include<math.h>
using namespace std;
struct stack{
    char item[STACKSIZE];
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
void push(char x){
    if(S.top==STACKSIZE-1){
        cout<<"Stack overflow";
        exit(1);
    }
    else{
        S.top+=1;
        S.item[S.top]=x;
    }
}
char pop(){
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
char stackTop(){
    return S.item[S.top];
}
bool prcd(char op1, char op2){
    if(op1=='^' || op1=='*' || op1=='/' || op1=='%'){
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
            return false ;
        }
    }
}

string infixToPrefix(string infix){
    Initialize();
    reverse(infix.begin(), infix.end());
    
    int i=0;
    
    vector<char>prefix;
    while(infix[i]!='\0'){
        char symb = infix[i];
        
        if(symb>='a' && symb<='z'){
            prefix.push_back(symb);
        }
        else{
            while(!IsEmpty() && !prcd(symb, stackTop())){
                char x=pop();
                prefix.push_back(x);
            }
            push(symb);
        }
        i++;
    }
    while(!IsEmpty()){
        char x= pop();
        prefix.push_back(x);
    }
    reverse(infix.begin(), infix.end());
    cout<<"PreFix Expression: ";
   for(int i=prefix.size()-1;i>=0;i--){
    cout<<prefix[i];
   }
   
}
int main(){
    char prefix[100];
    cout<<"Enter expression:";
    cin>>prefix;
    infixToPrefix(prefix);
    cout <<endl;
    return 0;
    
}