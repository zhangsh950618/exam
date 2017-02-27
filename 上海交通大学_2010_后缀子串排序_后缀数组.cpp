#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
const int maxn = 256;
int t1[maxn], t2[maxn], c[maxn],sa[maxn], heght[maxn];
string s;
int i, l;
void build_sa(int m){
    int *x = t1,*y = t2;
    memset(c, 0,sizeof(c));
    for(i = 0 ;i < l ; i++) c[x[i] = s[i]]++;
    for(i = 1 ; i < m ; i++) c[i] += c[i - 1];
    for(i = l -1 ; i >= 0; i--) sa[--c[x[i]]] = i;

    for(int k = 1 ; k < l ; k <<= 1){
        int p = 0;
        for(i = l - k ; i < l ; i++)y[p++] = i;
        for(i = 0 ;i < l ; i++)if(sa[i] >= k) y[p++] = sa[i] - k;


        memset(c, 0,sizeof(c));

        for(i = 0 ; i < l ; i++) c[x[y[i]]]++;
        for(i = 1 ; i < m ; i++) c[i] += c[i - 1];
        for(i = l - 1 ; i >= 0 ; i--) sa[--c[x[y[i]]]] = y[i];

        swap(x,y);

        x[sa[0]] = 0;
        p = 0;
        for(i = 1 ; i < l ; i++){
            if(y[sa[i]] != y[sa[i - 1]] || y[sa[i] + k] != y[sa[i - 1] + k])p ++;
            x[sa[i]] = p;
        }
        if(p == l) break;
        m = ++p;
    }
}

void get_height(){




}
int main(){

    while(cin >> s){
        l = s.length();
        build_sa(maxn);
        for(i = 0 ; i < l ; i++)
        cout << s.substr(sa[i]) << endl;
    }


    return 0;
}
