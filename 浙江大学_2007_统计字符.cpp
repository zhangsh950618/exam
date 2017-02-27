#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int maxn = 256 + 10;
string text,pattern;
char t[maxn], p[maxn];
int mark[maxn];
int main(){

    while(gets(p)){

        if(strcmp(p,"#") == 0) break;
        memset(mark, 0, sizeof(mark));
        gets(t);
        for(int i = 0 ; i < strlen(t) ; i++) mark[t[i]] ++;
        for(int i = 0 ; i < strlen(p) ; i++){
            printf("%c %d\n",p[i], mark[p[i]]);
        }
    }

    return 0;
}
