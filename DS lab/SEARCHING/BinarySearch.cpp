#include<iostream>
#include<climits>
using namespace std;
int BinarySearch(int arr[],int n,int key){
    int low=0;
    int high=n-1;
    while(low<=high){
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
int main() {
    int arr[6] = {2, 4, 6, 8, 12, 18};
    int n = 6;
    cout << "Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    cout << "Searching Tests:\n";
    cout << "Search 6  -> Index: " << BinarySearch(arr, n, 6) << endl;
    cout << "Search 18 -> Index: " << BinarySearch(arr, n, 18) << endl;
    cout << "Search 3  -> Index: " << BinarySearch(arr, n, 3) << endl;
    cout << "Search 20 -> Index: " << BinarySearch(arr, n, 20) << endl;
    cout << "Search 8  -> Index: " << BinarySearch(arr, n, 8) << endl;
    return 0;
}