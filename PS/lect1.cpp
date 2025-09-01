/*
    cout<< v.size()<< "\n";
    v.push_back(10);
    v.push_back(20);
    cout<<v.capacity()<<"\n";
    v.push_back(30);
    v.push_back(40);
    cout<<v.capacity()<<"\n";
    v.push_back(50);
    cout<<v.capacity()<<"\n";
    v.push_back(60);
    v.push_back(65);
    cout<<v.capacity()<<"\n";
    v.push_back(70);
    cout<<v.capacity()<<"\n";
    cout << v.size() << "\n"; 
    for(int i = 0; i<v.size();i++){
        cout << v[i]<< "\t";
    }
    v.pop_back();
    cout<<"\n";
    for(auto j:v)
     cout << j<< "\t";

      for(auto i:v)
    cout << i << " ";
    return 0;
*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
static bool cmp(int x, int y)
{
    if(x<y) return true;
    if(x>y) return false;
}
int main(){

    vector<int>v;
    v.push_back(6);
    v.push_back(7);
    v.push_back(2);
    v.push_back(3);
    v.push_back(12);
    v.push_back(97);
    v.push_back(15);
    sort(v.begin(),v.end(),cmp);
    for(auto i:v)
    cout<<i<<" ";

/*int n;
cout << "Enter the no of element";
cin >> n;
vector<int>v(n);
cout<< "Enter the elements: ";
for(int i=0 ;i<n; i++)
    cin>> v[i];

cout<< "Array elements are:=> ";
for(int i=0 ;i<n; i++)
    cout<<v[i]<<" ";*/
    return 0;
}



