#include<iostream>
#include<climits>
using namespace std;
int BinarySearch(int arr[],int n,int key){
    int low=0;
    int high=n-1;
    while(low<=low){
        int mid=low+(high-low)/2;
        if(arr[mid]==key){
            return mid;
        }
        else{
            if(key<arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }
    return -1;
}
int main(){
    int even[6] = {2, 4, 6, 8, 12, 18};
    int evenIndex = BinarySearch(even, 6, 6);
    cout << " Index of 6 is " << evenIndex << endl;
    int Index = BinarySearch(even, 6, 3);
    cout << " Index of 3 is " << Index << endl;
    return 0;
}