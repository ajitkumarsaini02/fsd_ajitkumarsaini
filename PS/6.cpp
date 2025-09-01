// even numbers in decending order then odd number in ascending order
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
static bool cmp(int x, int y){
    if(x%2==0 && y%2!=0)
    return true;
    if(x%2!=0 && y%2==0)
    return false;
    if(x%2==0 && y%2==0)
    return x>y;
    if(x%2!=0 && y%2!=0)
    return x<y;
}
int main(){
    vector<int> v{10,5,9,12,32,6,4,1,14,7};
    sort(v.begin(),v.end(),cmp);
    for(auto x:v)
    cout<<x<<" ";
    return 0;
}