#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,x;
  
     
   cout<<"Enter the size of array:";
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<A.size();i++){
        cin >> A[i];
    }
    int max=0;
    int sum=0;
    for(int i=0;i<A.size();i++){
        if(A[i]>max){

        
          max=A[i];
          i+=1;
          x=max;
        }
    }
    
    
    for(int i=0;i<A.size();i++){
        sum=sum+A[i];
    }
    int total = x*(x+1)/2;
    int ans=total-sum;
    cout<<"Missing element:"<<ans;

    
    return 0;
}
// {
//     cout<<"Enter the size of array:";
//     cin>>n;
//     vector<int> A(n);
//      int max=-100000;
//      int min=100000;
//     for(int i=0;i<A.size();i++){
//         cin >> A[i];
//         if(A[i]>max)
//           max=
//     }
    

//     int sum=0;
//     for(int i=0;i<A.size();i++){
//         if(A[i]>max){

        
//           max=A[i];
//           i+=1;
//           x=max;
//         }
//     }
//     vector<int>DAT(x+1);
//     for(int i=0;i<DAT.size();i++){
//         DAT[A[i]]++;
//     }
//     for(int i=0;)


// }