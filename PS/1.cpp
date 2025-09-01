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
    vector <int> v{6,7,2,3,12,97,15};
    sort(v.begin(), v.end(), cmp);
    for(auto i:v)
    cout<<i<<" ";
    return 0;

}