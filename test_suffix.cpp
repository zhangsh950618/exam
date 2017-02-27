#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 10;
string st;
int t;
string sub[maxn];
bool cmp(string a, string b){
     return a < b;
}
int main(){
    while(cin >> st){
//        cout << st << endl;
        int l = st.length();
        t = 0;
        while(t < l){
            sub[t++] = st.substr(t);
        }
        sort(sub, sub + t, cmp);

        for(int i = 0 ;i < t ; i++)
        cout << sub[i] << endl;
    }
    return 0;
}
