#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;
map<string, string> m;
int main(){
    m["123"] = "456";
    string s;
    while(cin >> s){
    string k = m[s];
    cout << "k = " << k << endl;
    }
    return 0;
}
