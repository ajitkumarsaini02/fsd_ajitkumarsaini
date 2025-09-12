#include<iostream>
#include<string>
using namespace std;
struct students{
    char name[100];
    int rollno;
    int marks[6];
}s[50];
int main(){
    int n;
    cout<<"Enter the no of students:";
    cin >>n;
    for(int i=0;i<n;i++){
        cout<<"Enter details of student:"<<i+1<<endl;
        cout<<"Enter name of student:";
        cin>>s[i].name;
        cout<<"Enter the roll number:";
        cin>>s[i].rollno;
        cout <<"Enter the marks of subject:";
        for(int j=0;i=j<6;j++){
            cout<<"Student:"<<i+1<<":";
            cin>>s[i].marks[j];
        }
        
        
        
        

    }

}