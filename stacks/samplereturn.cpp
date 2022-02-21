#include <iostream>
using namespace std;
int i=5; //global variable update if local is not there in a program 
int function(int i){
    return ++i;
}
int main()
{
    // cout<<function(1)<<endl;
    // cout<<function(2)<<endl;
    string st = "12";
    // int num1 = int();
    // cout<<num1<<endl;
    cout<<int(st[3])<<endl;
    return 0;
}