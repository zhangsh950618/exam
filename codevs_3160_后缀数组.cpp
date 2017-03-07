#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int size = 2 * 100000 + 10;
int rank[size],t1[size], t2[size],sa[size],height[size], c[size],w[size];
void get_sa(int len, int up){
    int *x = t1, *y = t2;
    //clear the button
    for(int i = 0 ; i < up ; i++) c[i] = 0;

    //map
    for(int i = 0 ; i < len ; i++) c[x[i] = w[i]]++;

    for(int i = 1 ; i < up ; i++) c[i] += c[i - 1];

    //reduce, finish the first sort
    for(int i = len - 1 ; i >= 0 ; i--) sa[--c[x[i]]] = i;
    for(int k = 1 ; k <= len ; k <<= 1){

        int p = 0;
        for(int i = len - k ; i < len ; i++)  y[p++] = i;

        for(int i = 0 ; i < len ; i++) if(sa[i] >= k) y[p++] = sa[i] - k;


        for(int i = 0 ; i < up ; i++) c[i] = 0;
        for(int i = 0 ; i < len ; i++)c[x[y[i]]] ++;
        for(int i = 1 ; i < up ; i++) c[i] += c[i - 1];
        for(int i = len - 1 ; i >= 0 ; i--) sa[--c[x[y[i]]]] = y[i];

        swap(x, y);
        x[sa[0]] = 0;
        p = 0;
        for(int i = 1 ; i < len  ; i++){
            if(y[sa[i]] != y[sa[i -1]] || y[sa[i] + k] != y[sa[i - 1] + k])
            p++;

            x[sa[i]] = p;
        }
        if(p >= len) break;
        up = p + 1;
    }
}

void get_height(int len){
    for(int i = 0 ;i < len ; i++) rank[sa[i]] = i;
    height[0] = 0;
    int j, k = 0;
    for(int i = 0 ;i < len - 1 ; i++){
        if(k) k--;
        j = sa[rank[i] - 1];
        while(w[i + k] == w[j + k]) k++;
        height[rank[i]] = k;
    }



}
void get_suffix(string s){
    int len = s.length(), up = 0;
    for(int i = 0 ; i < len ; i++){
        w[i] = s[i];
        up = max(up, w[i]);
    }
    w[len++] = 0;

    get_sa(len, up + 1);
    get_height(len);

}
string s1, s2,st;
int main(){

    while(cin >> s1 >> s2){
        int l1 = s1.length();
        st = s1 + '$' + s2;
        get_suffix(st);
        int max_length = 0;

        for(int i = 2 ; i <= st.length() ; i++){
            if((sa[i] < l1)^(sa[i -1] < l1)) max_length = max(max_length, height[i]);
        }
//        for(int i = 1 ; i <= st.length() ; i++) cout << st.substr(sa[i]);
        if(max_length) cout << max_length << endl;
    }

    return 0;
}
