#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string st;
bool classify(string s){
    int len = s.length();
    int i = 0;
    while(s[i] == 'o') i++;
    string t = s.substr(i);
    cout << "t = " << t << endl;
    reverse(t.begin(), t.end());
    cout << "t = " << t << endl;
    int j = 0;
    while(s[j] == 'o') j++;
    string k = t.substr(j);
    if(k == "zoj" && i == j)
    return true;
    return false;
}
bool decide(string s){
    bool flag = classify(s);
    if(flag) return true;
    else{
    int i = 0;
    while(s[i] == 'o') i++;
    string a = s.substr(0, i);
    int j = 0;
    while(s[j] != 'j') j++;
    s.erase(j, i);
    i = 0;
    while(s[i] != 'z') i++;
    if(i + 1 < s.length() && s[i + 1] == 'o')
    s.erase(i + 1);
    if(decide(s)) return true;
    else return false;
    }
}
int main(){
    while(cin >> st){
        if(decide(st)) cout << "Accepted" << endl;
        else cout << "Wrong Answer" << endl;
    }
    return 0;
}
