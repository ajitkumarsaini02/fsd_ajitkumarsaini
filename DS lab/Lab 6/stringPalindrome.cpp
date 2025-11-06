#include<iostream>
using namespace std;
int palindrome(string s,int i, int j){
    if(i>=j) return true;
    if(s[i]!=s[j]) return false;
    return palindrome(s,i+1,j-1);
}
int main(){
    string s;
    cout<<"Enter string:";
    getline(cin,s);
    if(palindrome(s,0,s.length()-1)){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }
    return 0;
}