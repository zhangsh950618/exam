#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 10;
int t = 0;
string s;
int sa[maxn];
bool cmp(int a, int b){
    return s.substr(a) < s.substr(b);
}
int main(){
    while(cin >> s){
    int l = s.length();
    for(int i = 0 ; i < l ; i++) sa[i] = i;
    sort(sa, sa + t,cmp);
    for(int i = 0 ; i < l ; i++)
    cout << s.substr(sa[i]) << endl;
    }
    return 0;
}
