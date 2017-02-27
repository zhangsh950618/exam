#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
const int maxn = 256;
ifstream fin("1.in");
string st;
char trank[maxn];
int  sa[maxn], c[maxn], rank[maxn];
int main(){
    while( fin >> st ){
        cout << st << endl;
        int p;
        int l = st.length();


        //the first build of sa and rank
        for(int i = 0 ; i < l ; i++) c[trank[i] = st[i]]++;

        for(int i = 0 ; i < maxn ; i++) c[i] += c[i - 1];

        for(int i = l - 1 ; i >= 0 ; i--)sa[--c[trank[i]]] = i;

        rank[sa[0]] = 0;

        for(int i = 0, p = 1; i < l ; i++){
            if(trank[sa[i]] != trank[sa[i - 1]]) p++;
            rank[sa[i]] = p;
        }


        for(int i = 0 ;i < l ; i++) cout << rank[i] << endl;


        for(int k = 1 ; k <= l ; k <<= 1){

            sorting(k);

            trank[sa[0]] = 0;p = 0;
            for(int i = 1 ,p = 0; i < l ; i++){
                if(rank[sa[i]] != rank[sa[i - 1]] || rank[sa[i] + j] != rank[sa[i - 1] + j]) p++;
                trank[sa[i]] = p;
            }
            for(int i = 0 ; i < l ; i++) rank[i] = trank[i];
        }








    }



    return 0;
}
