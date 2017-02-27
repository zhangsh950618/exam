#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 100000 + 10;
int t1[maxn], t2[maxn], sa[maxn],c[maxn], height[maxn], rank[maxn];
int i, l1 ,l2, l;
string st , a1 , a2;

void build_sa(int m){
    int *x = t1, *y = t2;
    for(i = 0 ; i < m ; i++) c[i] = 0;
    for(i = 0 ; i < l ; i++) c[x[i] = st[i]]++;
    for(i = 1 ; i < m ; i++) c[i] += c[i - 1];
    for(i = l - 1 ; i >= 0 ; i--) sa[--c[x[i]]] = i;


    for(int k = 1 ; k <= l ; k <<= 1){
        int p = 0;
        for(i = l - k ; i < l ; i++)y[p++] = i;
        for(i = 0 ; i < l ; i++) if(sa[i] >= k) y[p++] = sa[i] - k;

        for(i = 0 ; i < m ; i++) c[i] = 0;
        for(i = 0 ; i < l ; i++) c[x[y[i]]]++;
        for(i = 1 ; i < m ; i++) c[i] += c[i - 1];
        for(i = l - 1 ; i >= 0 ; i--) sa[--c[x[y[i]]]] = y[i];

        swap(x, y);
        x[sa[0]] = 0;
        p = 0;

        for(i = 1 ;i < l ; i++){
            if(y[sa[i]] != y[sa[i -1]] || y[sa[i] + k] != y[sa[i - 1] + k])
            p++;
            x[sa[i]] = p;

        }

        if(p == l) break;
        m = p + 1;

    }
}

void get_height(){
    int j, k = 0;
    for(i = 1 ; i <= l ; i++) rank[sa[i]] = i;
    for(i = 0 ; i < l ; i++) height[rank[i]] = k;
    for(i = 0 ; i < l ; i++){
        if(k) k--;
        j = sa[rank[i] -1];
        while(st[i + k] == st[j + k]) k++;
        height[rank[i]] = k;
    }
}
int main(){

    while(cin >> a1 >> a2){
        l1 = a1.length();
        l2 = a2.length();
        st = a1 + '0' + a2 + '#';
        l = st.length();
        build_sa(maxn);
        get_height();

//        for(i = 0 ; i < l ; i++)
//        cout << st.substr(sa[i]) << " " << height[i] << endl;

        int max_length = 0;
        for(i = 1 ; i < l ; i++){
            if((sa[i -1] - l1) * (sa[i] - l1)< 0){
                max_length = max(max_length, height[i]);
            }
        }

        cout << max_length << endl;
    }










    return 0;
}
