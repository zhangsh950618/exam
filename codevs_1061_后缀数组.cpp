#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int size = 3 * 100000 + 10;
const int INF = (1 << 30);
int t1[size], t2[size];
int c[size],w[size],sa[size],height[size],rank[size];
void get_sa(int len, int up){
    int *x = t1, *y = t2;
    for(int i = 0 ; i < up ; i++) c[i] = 0;
    for(int i = 0 ; i < len ; i++) c[x[i] = w[i]]++;
    for(int i = 1 ; i < up ; i++) c[i] += c[i - 1];
    for(int i = len - 1 ; i >= 0 ; i--) sa[--c[x[i]]] = i;
    for(int k = 1 ; k <= len ; k <<= 1){
        int p = 0;
        for(int i = len - k ; i < len ; i++) y[p++] = i;
        for(int i = 0 ; i < len ; i++) if(sa[i] >= k) y[p++] = sa[i] - k;
        for(int i = 0 ; i < up ; i++) c[i] = 0;
        for(int i = 0 ; i < len ; i++) c[x[y[i]]]++;
        for(int i = 1 ; i < up ; i++) c[i] += c[i -1];
        for(int i = len -1 ; i >= 0 ; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x,y);

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
    int j, k = 0;
    for(int i = 0 ; i < len ; i++) rank[sa[i]] = i;
    height[0] = 0;
    for(int i = 0 ; i < len - 1 ; i++){
        if(k) k--;
        j = sa[rank[i] - 1];
        while(i + k < len && j + k < len && w[i + k] == w[j + k])
        k++;
        height[rank[i]]= k;
    }
}
void get_suffix(string s){
    int len = s.length(),up = 0;
    for(int i = 0 ; i < len ; i++){
        w[i] = s[i];
        up = max(w[i], up);
    }
    w[len++] = 0;
    get_sa(len, up + 1);
    get_height(len);
}
string s;
bool is_number(char c){
    return c >= '0' && c <= '9';
}
int sa_start = INF;
int max_k = 0;
bool check(int k, int len){
    int flag = false;
    int sa_min = sa[1], sa_max = sa[1];
    int j = 1;
    for( j = 1 ; j <= len ; j++){
        if(!is_number(w[sa[j]])){
            sa_min = sa[j];
            sa_max = sa[j];
            break;
        }
    }
//    cout << "k = " << k << endl;
//    cout << "j = " << j  << "  " << char(w[sa[j]]) << endl;
    for(int i = j ; i <= len ; i++){
        if(height[i] < k){
            sa_min = sa[i];
            sa_max = sa[i];
        }else{
            sa_min = min(sa_min, sa[i]);
            sa_max = max(sa_max, sa[i]);
            if(sa_max - sa_min == k){
                if(k >= max_k){
                    max_k = k;
                    sa_start = min(sa_start, sa_min);
                }
                flag = true;
            }
        }
    }

    if(k == 6) cout << "when k = 6 flag =" << flag <<endl;

    if(flag) return true;
    return false;
}
int main(){

    while(cin >> s){
//        cout << s << endl;
        get_suffix(s);

//        for(int i = 1 ; i <= s.length() ; i++)
//        cout << s.substr(sa[i])  << "sa : " << sa[i] << "height : " << height[i] <<  endl;

        if(max_length) cout << s.substr(max_start, max_length) << endl;
    }
    return 0;
}
