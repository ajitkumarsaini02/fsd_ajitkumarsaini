#include<iostream>
#define STACKSIZE 10
#include "CharStackHeader.h"
using namespace std;


void balanceParenthesis(char exp[]){
    Initialize();
    int i=0,flag=0;
    while(exp[i]!='\0'){
        if(exp[i]=='('){
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
    balanceParenthesis(exp);
    return 0;
}