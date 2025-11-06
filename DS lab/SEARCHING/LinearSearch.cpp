#include<iostream>
#include<climits>
using namespace std;
int LinearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={5,3,1,4,2};
    int n=5;
    int key;
    cin>>key;
    int k=LinearSearch(arr,n,key);
    cout<<k;
}