#include<iostream>
#define STACKSIZE 10
using namespace std;
struct stack{
    char item[STACKSIZE];
    int top;
}s;
void initialize(){
    s.top=-1;
}
bool isEmpty(){
    if(s.top==-1){
        return true;
    }
    else{
        return false;
    }
}
void push(char x){
    if(s.top==STACKSIZE-1){
        cout<<"Under overflow"<<endl;
        exit(1);
    }
    else{
        s.top+=1;
        s.item[s.top]=x;
    }
}
char pop() {
    if (isEmpty()) {
        cout << "Stack underflow" << endl;
        exit(1);
    } else {
        char x = s.item[s.top];
        s.top -= 1;
        return x;
    }
}
char stackTop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        exit(1);
    }
    return s.item[s.top];
}
void palindromeString(char str[]){
    initialize();
    int i=0;
    while(str[i]!='\0'){
          push(str[i]);
          i+=1;
    }
    i=0;
    while(!isEmpty()){
        char topChar = pop();
        if(topChar==str[i]){
            
            i+=1;
        }
        else{
            break;
        }
    }
    if(isEmpty()){
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