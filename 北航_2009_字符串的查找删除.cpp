#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int size = 10000 + 10;
char p[size], t[size];
bool eq(char a, char b){
    if(a < b) swap(a, b);
    return a == b || a - b == 32;
}
int main(){
    scanf("%s", p);
    while(~scanf("%s", t)){
        int lt = strlen(t);
        int lp = strlen(p);
        for(int pos = 0 ; pos < lt ;){
            if(eq(p[0],t[pos])){
                int k = 0;
                while(k < lp && eq(p[k], t[pos + k])) k++;
                if(k == lp) pos += lp;
            }else if(t[pos] - ' ' == 0){
                pos++;
                continue;
            }else{
                printf("%c", t[pos]);
                pos++;
            }
        }
        cout << endl;

    }


    return 0;
}
