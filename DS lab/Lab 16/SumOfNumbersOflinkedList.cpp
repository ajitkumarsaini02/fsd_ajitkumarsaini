#include<iostream>
#include<stdlib.h>
#include"LinkedListheader.h"
using namespace std;

Node* createListFromString(string n) {
    Node* Start1 = NULL;
    int i = 0;

    while (i < n.size()) {
        int digit = n[i] - '0';   
        InsBeg(&Start1, digit);   
        i++;
    }

    ReverseList(&Start1); 
    return Start1;
}

int SumNumber(Node **S1, Node **S2){
    Node *p = *S1;
    Node *q = *S2;
    Node *S3 = NULL;
    int carry =0;
    int total, sum;
    while(p!=NULL && q!=NULL){
        total = p->info + q->info + carry;
        sum = total%10;
        carry =total/10;
        InsBeg(&S3, sum);
        p=p->Next;
        q=q->Next;
    }
    while (p!=NULL){
        total = p->info + carry;
        sum = total%10;
        carry = total/10;
        InsBeg(&S3, sum);
        p=p->Next;
    }
    while (q!=NULL){
        total = q->info + carry;
        sum = total%10;
        carry = total/10;
        InsBeg(&S3, sum);
        q=q->Next;
    }
    if(carry==1){
        InsBeg(&S3, carry);
    }
    ReverseList(&S3);
    return S3;
} 
int main(){
    Node *Start1 = NULL, *S1 = NULL, *S2 = NULL;
    cout<<"Enter string"

    

}