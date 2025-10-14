#include<iostream>
#include<stdlib.h>
#include"FirstStackHeader.h"
using namespace std;
int FindMax(){
    if(S.top==-1){
        cout<<"Stack is Empty:";
        exit(1);
    }
    else{
        int max=S.item[0];
        for(int i=0;i<S.top;i++){
            if(S.item[i]>max){
                max=S.item[i];
            }
        }
        return max;
    }
}

int FindMin(){
    if(S.top==-1){
        cout<<"Stack is Empty:";
        exit(1);
    }
    else{
        int min=S.item[0];
        for(int i=0;i<S.top;i++){
            if(S.item[i]<min){
                min=S.item[i];
            }
        }
        return min;
    }
}

int main() {
    Initialize();

    push(12);
    push(5);
    push(20);
    push(8);
    push(15);

    Traverse();
    cout << "Maximum element in stack: " << FindMax() << endl;
    cout << "Minimum element in stack: " << FindMin() << endl;

    cout << "Popped element: " << pop() << endl;
    Traverse();

    cout << "Maximum element in stack: " << FindMax() << endl;
    cout << "Minimum element in stack: " << FindMin() << endl;

    return 0;
}