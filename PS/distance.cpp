#include<iostream>
#include<vector>
using namespace std;
struct distance{
    int km, m;

};
int main(){

    struct distance d1={10,600};
    struct distance d2={50,800};
     
    struct distance d3;
    d3.m=d1.m+d2.m;
    d3.km=d1.km+d2.km+(d3.m)/1000;
    d3.m=(d3.m)%1000;
    cout<<d3.km<<"-"<<d3.m;

}
