#include<iostream>
#include<vector>
using namespace std;
struct height{
    int feet, inches;

};
int main(){

    height t1;
    height t2;
     
    height t3;
    cout <<"Enter the height of tower:";
    cin>>t1.feet>>t1.inches;
    cout <<"Enter the height of tower:";
    cin>>t2.feet>>t2.inches;
    t3.inches=t1.inches+t2.inches;
    t3.feet=t1.feet+t2.feet+(t3.inches)/12;
    t3.inches=(t3.inches)%12;
    cout<<t3.feet<<"-"<<t3.inches;
}