#include<iostream>
#include<string.h>
using namespace std;
string s;
int main(){
    while(cin >> s){
    cout << s << endl;
    cout << s.length() << endl;
    s += '\0';
    cout << s << endl;
    cout << s.length() << endl;


    }







}
