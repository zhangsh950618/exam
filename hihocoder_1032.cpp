#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int size = 1000000 + 10;
int sa[size], t1[size], t2[size], height[size], c[size], rank[size], w[size];
string st;
void get_sa(int len, int up){
    int * x = t1 , * y = t2;
    for(int i = 0 ; i < up ; i++) c[i] = 0;
    for(int i = 0 ; i < len ; i++) c[x[i] = w[i]]++;
    for(int i = 1 ; i < up ; i++) c[i] += c[i - 1];
    for(int i = len - 1 ; i >= 0; i--) sa[--c[x[i]]] = i;
    for(int k = 1 ; k <= len ; k <<= 1){
        int p = 0;
        for(int i = len - k ; i < len ; i++) y[p++] = i;
        for(int i = 0 ; i < len ; i++) if(sa[i] >= k) y[p++] = sa[i] - k;


        for(int i = 0 ; i < up ; i++) c[i] = 0;
        for(int i = 0 ; i < len ; i++) c[x[y[i]]]++;
        for(int i = 1 ; i < up ; i++) c[i] += c[i -1];
        for(int i = len - 1 ; i >= 0 ; i--) sa[--c[x[y[i]]]] = y[i];

        swap(x ,y);


        x[sa[0]] = 0;
        p = 0;
        for(int i = 1 ; i < len ; i++){
            if(y[sa[i]] != y[sa[i - 1]] || y[sa[i] + k] != y[sa[i - 1] + k])
            p++;
            x[sa[i]] = p;
        }
        if(p == len) break;
        up = p + 1;
    }
}
void get_height(int len){
    for(int i = 0 ; i < len ; i++) rank[sa[i]] = i;
    height[0] = 0;
    int j, k = 0;
    for(int i = 0 ; i < len - 1; i++){
        if(k) k --;
        j = height[rank[i] - 1];
        while(w[i + k] == w[j + k]) k++;
        height[rank[i]] = k;
    }
}

void get_suffix(string s){
    int len = s.length(), up = 0;
    for(int i = 0; i < len ; i++){
        w[i] = s[i];
        up = max(w[i], up);
    }
    w[len++] = 0;
    get_sa(len, up + 1);
    get_height(len);
}
int main(){
    while(cin >> st){
        get_suffix(st);

        for(int i = 1 ; i <= st.length() ; i++)
        cout << st.substr(sa[i]) << " " << height[i] << endl;

    }
    return 0;


}

