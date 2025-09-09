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
void palindromeString(char str[]){
    Initialize();
    int i=0;
    while(str[i]!='\0'){
          push(str[i]);
          i+=1;
    }
    i=0;
    while(!IsEmpty()){
        char topChar = pop();
        if(topChar==str[i]){
            
            i+=1;
        }
        else{
            break;
        }
    }
    if(IsEmpty()){
        cout<<str<<" is Palindrome" << endl;
    }
    else{
        cout<<str<<" is Not palindrome:"<<endl;
    }
}
int main(){
    char str[100];
    cout<<"Enter the string:";
    cin>>str;
    palindromeString(str);
    return 0;

}