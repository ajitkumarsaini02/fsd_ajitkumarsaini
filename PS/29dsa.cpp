#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v1(3,1);
    vector<int> v2(4,2);
    vector<int> v3(7,3);
    vector<int> v4(9,4);
    vector<int> v5(2,5);

    vector<vector<int>> vv;
    vv.push_back(v1);
    vv.push_back(v2);   
    vv.push_back(v3);
    vv.push_back(v4);
    vv.push_back(v5);
    for(int i=0; i<vv.size(); i++){ 
        for(int j=0;j<vv[i].size();j++){ // to access each element of inner vector
            cout<< vv[i][j]<<" ";
        }
         cout<<"\n";
    }
 return 0;
}