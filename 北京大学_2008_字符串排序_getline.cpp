#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 1000 + 10;
int t = 0;
int n;
string st[maxn];

bool cmp(string a, string b){

    int la = a.length();
    int lb = b.length();

    if(la != lb) return la < lb;
    return a < b;
}
int main(){

    while(cin >> n){
        getchar();
        t = 0;
        for(int i = 0 ;i < n ; i++){
            string temp;
            getline(cin, temp);
            if(temp == "stop") break;
            st[t++] = temp;
        }
        sort(st, st + t, cmp);
        for(int i = 0 ; i < t; i++)
        cout << st[i] << endl;
    }










}
