#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 256 + 10;
string t, p;
int mark[maxn];
int main(){
    while(getline(cin, p)){
        if(p == "#") break;
        memset(mark, 0 , sizeof(mark));
        getline(cin, t);
        for(int i = 0 ;i < t.length() ; i++) mark[t[i]]++;
        for(int i = 0 ;i < p.length() ; i++)
            cout << p[i] << " " << mark[p[i]] << endl;
    }
    return 0;
}
