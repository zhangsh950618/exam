#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
string t;
const int maxn = 256 + 10;
int c[maxn],t1[maxn], t2[maxn], sa[maxn], rank[maxn];
int l;
void da(){
    int *x  = t1, *y = t2;
    int i;
    l = t.length();
    //clear button
    memset(c, 0, sizeof(c));
    for(i = 0 ; i < l ; i++) c[x[i] = t[i]]++;

    for(i = 1 ; i < maxn ; i++) c[i] += c[i - 1];


    for(i = l - 1 ; i >= 0 ; i--) sa[--c[x[i]]] = i;


    for(int k = 1 ; k <= l ; k <<= 1){
        int p = 0;

        //sort the second key word first;
        for(i = l - k ; i < l ; i++) y[p++] = i;

        for(i = 0 ; i < l ; i++) if(sa[i] >= k) y[p++] = sa[i] - k;

        memset(c , 0, sizeof(c));

        for(i = 0 ; i < l ; i++) c[x[y[i]]]++;
        for(i = 1 ; i < maxn ; i++) c[i] += c[i - 1];
        for(i = l - 1 ; i >= 0 ; i--) sa[--c[x[y[i]]]] = y[i];

        swap(x, y);


        x[sa[0]] = 0;
        p = 0;
        for(i = 1 ; i < l ; i++){
            if(y[sa[i]] != y[sa[i - 1]] || y[sa[i] + k] != y[sa[i - 1] + k]) p++;
            x[sa[i]] = p;
        }

        if(p == l) break;




    }
}


void get_height(){

    for(int i = 0 ; i < l ; i++) rank[sa[i]] = i;




}
int main(){

    t = "aabaaaabb";
    da();
    get_height();


    for(int i = 0 ; i < l ; i++){
        for(int j = sa[i] ; j < l ; j++)
        cout << t[j];
        cout << endl;
    }





    return 0;
}
