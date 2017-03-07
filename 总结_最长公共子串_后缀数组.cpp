#include<iostream>
using namespace std;
const int size = 100000 * 2 + 10;
int t1[size], t2[size], sa[size], height[size], c[size], w[size], rk[size];
string s, t;


void get_sa(int len, int up){
    int *x = t1, *y = t2;
    for(int i = 0 ; i < up ; i++) c[i] = 0;
    for(int i = 0 ; i < len ; i++) c[x[i] = w[i]]++;
    for(int i = 1 ; i < up ; i++) c[i] += c[i -1];

    for(int i = len - 1 ; i >= 0 ; i--) sa[--c[x[i]]] = i;

    for(int k = 1 ; k <= len ; k <<= 1){
        int p = 0;
        for(int i = len - k ; i < len ; i++)y[p++] = i;
        for(int i = 0 ; i < len ; i++) if(sa[i] >= k) y[p++] = sa[i] - k;

        for(int i = 0 ; i < up ; i++) c[i] = 0;
        for(int i = 0 ; i <len ; i++) c[x[y[i]]]++;
        for(int i = 1 ; i < up ; i++) c[i] += c[i - 1];
        for(int i = len - 1 ; i >= 0 ; i--) sa[--c[x[y[i]]]] = y[i];

        swap(x, y);

        x[sa[0]] = 0;
        p = 0;
        for(int i = 1 ; i < len ; i++){
            if(y[sa[i]] != y[sa[i -1]] || y[sa[i] + k] != y[sa[i - 1] + k])
            p++;
            x[sa[i]] = p;
        }


        if(p == len) break;
        up = p + 1;

    }

}
void get_height(int len){
    for(int i = 0 ; i < len ; i++) rk[sa[i]] = i;
    height[0] = 0;
    int j, k= 0;
    for(int i = 0 ; i < len - 1 ; i++){
        if(k) k--;
        j = sa[rk[i] - 1];
        while(w[i + k] == w[j + k])k++;
        height[rk[i]] = k;
    }

}
void get_suffix(string s){
    int len = s.length();
    int up = 0;
    for(int i = 0 ; i < len ; i++){
        w[i]  =s[i];
        up = max(up, w[i]);
    }
    w[len++] = 0;
    get_sa(len, up + 1);
    get_height(len);
}
int main(){
    while(cin >> s){
        int la = s.length();
        s += '$';
        cin >> t;
        s += t;
        get_suffix(s);
//        for(int i = 1 ; i <= s.length() ; i++)
//        cout << s.substr(sa[i]) << " " << height[i] << endl;
        int max_height = 0;
        for(int i = 2 ; i <= s.length() ; i++){
            if((sa[i - 1] < la) ^ (sa[i] < la)){
                max_height = max(max_height, height[i]);
            }
        }
        cout << max_height << endl;

    }
    return 0;
}
