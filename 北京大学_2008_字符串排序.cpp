#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 1000 + 10;
string st[maxn];
char temp[maxn];
int n;

bool cmp(string a, string b){
    if(a.length() != b.length()) return a.length() < b.length();
    return a < b;
}
int main(){

    while( cin >> n ){
        getchar();
        string s;
        int t = 0;
        for(int i = 0 ; i < n ; i++) {
            gets(temp);
            s = temp;
            if(s == "stop") break;
            else st[t++] = s;
        }


        sort(st, st + t, cmp);

        for(int i = 0 ;i < t ; i++){
            cout << st[i] << endl;
        }


    }









    return 0;
}
