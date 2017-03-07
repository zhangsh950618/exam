#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int size = 2000000 + 10;
const int INF = (1 << 30);
int sa[size], c[size], t1[size], t2[size],rk[size], height[size], w[size];
void get_sa(int len, int up){
    int * x = t1, * y = t2;
    for(int i = 0 ; i < up ; i++) c[i] = 0;
    for(int i = 0 ; i < len ; i++) c[x[i] = w[i]] ++;
    for(int i = 1 ; i < up ; i++) c[i] += c[i -1];
    for(int i = len - 1 ; i >= 0 ; i--) sa[--c[x[i]]] = i;

    for(int k = 1;  k <= len ; k <<= 1){
        int p = 0 ;
        for(int i = len - k ; i < len ; i++) y[p++] = i;
        for(int i = 0 ; i < len ; i++) if(sa[i] >= k) y[p++] = sa[i] - k;
        for(int i = 0 ; i < up ; i++) c[i] = 0;
        for(int i = 0 ; i < len ; i++) c[x[y[i]]]++;
        for(int i = 1 ; i < up ; i++) c[i] += c[i - 1];
        for(int i = len - 1 ; i >= 0 ; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x ,y);
        x[sa[0]] = 0;p = 0;
        for(int i = 1 ; i < len ; i++){
            if(y[sa[i]] != y[sa[i  -1]] || y[sa[i] + k] != y[sa[i - 1] + k])
            p++;
            x[sa[i]] = p;
        }
        if(p == len) break;
        up = p + 1;
    }


}
void get_height(int len){
    int j, k = 0;
    for(int i = 0 ; i < len ; i++) rk[sa[i]] = i;
    height[0] = 0;
    for(int i = 0 ; i < len - 1 ; i++){
        if(k)k--;
        j = sa[rk[i] - 1];
        while(w[i + k] == w[j + k]) k++;
        height[rk[i]] = k;
    }


}
void get_suffix(string s){
    int len = s.length(), up = 0;
    for(int i = 0 ; i < len ; i++){
        w[i] = s[i];
        up = max(up, w[i]);
    }
    w[len++] = 0;
    get_sa(len, up + 1);;
    get_height(len);
}
string s, temp;
int main(){
    int n;
    cin >> n;
        while(n --){
        cin >> temp;
        int len = temp.length();
        s = temp;
        reverse(temp.begin(), temp.end());
        s += "$" + temp;
        get_suffix(s);
        int max_length = 0;
        for(int i = 0 ; i < len ; i++){
            //处理奇数回文串
            int rk1 = rk[i];
            int rk2 = rk[2 * len - i];
            if(rk1 > rk2) swap(rk1, rk2);
            int h = INF;
            for(int j = rk1 + 1 ; j <= rk2 ; j++){
                h = min(h, height[j]);
            }
            max_length = max(max_length, 2 * h -1);
            //处理偶数回文串
            rk1 = rk[i];
            rk2 = rk[2 * len - i + 1];
            if(rk1 > rk2) swap(rk1, rk2);
            h = INF;
            for(int j = rk1 + 1 ; j <= rk2 ; j++){
                h = min(h, height[j]);
            }
            max_length = max(max_length, 2 * h);
        }
        cout << max_length << endl;
    }

    return 0;
}
