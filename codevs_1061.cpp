#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
const int maxn = 100000 + 10;
string s;
int t1[maxn], t2[maxn], x[maxn],c[maxn],sa[maxn];
int i, l;
void build_sa(int m){
    int *x = t1 , * y = t2;
    for(i = 0 ; i < m ; i++) c[i] = 0;
    for(i = 0 ; i < l ; i++) c[x[i] = s[i]]++;
    for(i = 1 ; i < m ; i++) c[i] += c[i - 1];
    for(i = l - 1 ; i >=0 ; i--)sa[--c[x[i]]] = i;


    for(int k = 1 ; k <= l ; k <<= 1){

        int p = 0;
        for(i = l - k ; i < l ; i++) y[p++] = i;
        for(i = 0 ; i < l ; i++) if(sa[i] >= k) y[p++] = sa[i] - k;

        for(i = 0 ; i < m ; i++) c[i] = 0;
        for(i = 0 ; i < l ; i++) c[x[y[i]]]++;
        for(i = 1 ; i < m ; i++) c[i] += c[i - 1];
        for(i = l - 1 ; i >= 0 ; i--) sa[--c[x[y[i]]]] = y[i];


        swap(x, y);

        x[sa[0]] = 0;
        p = 0;
        for(i = 1 ; i < l ; i++){
            if(y[sa[i]] != y[sa[i - 1]] || y[sa[i] + k] != y[sa[i -  1] + k])
            p++;
            x[sa[i]] = p;
        }

        if(p == l) break;
        m = p + 1;
    }
}
int rank[maxn], height[maxn];
void get_height(){
    int j, k = 0;
    for(i = 1 ; i <= l ; i++) rank[sa[i]] = i;
    for(i = 0 ; i < l ; i++) height[rank[i]] = 0;
    for(i = 0 ; i < l ; i++){
        if(k) k--;
        j = sa[rank[i] - 1];
        while(s[i + k] == s[j + k]) k++;
        height[rank[i]] = k;
    }


}

bool is_number(char c){
    return c >= '0' && c <= '9';
}
int sa_start;

bool check(int k){
    int sa_min = sa[0],sa_max = sa[0];
    bool flag = false;
    for(i = 1 ; i < l ; i++){
        if(height[i] >= k && !is_number(s[sa[i]])){
            sa_min = min(sa_min, sa[i]);
            sa_max = max(sa_max, sa[i]);
            if(sa_max - sa_min > k){
                sa_start = min(sa_start, sa_min);
                flag = true;
            };
        }else{
            sa_min = sa[i];
            sa_max = sa[i];
        }
    }
    if(flag) return true;
    return false;


}
int main(){

    while(cin >> s){
        s += '0';
        l = s.length();
        build_sa(256);
        get_height();
        int sl = 0 ,e = l / 2, mid = (sl + e) / 2;
        sa_start = l;
        while(sl <= e){
            mid = (sl + e) / 2;
            if(check(mid)) sl = mid +1;
            else e = mid - 1;
        }
//        cout << "mid = " << mid << "sa_start" << sa_start << endl;
        if(mid == 0) cout << "NO" << endl;
        else cout << s.substr(sa_start, mid) << endl;


    }
    return 0;
}
