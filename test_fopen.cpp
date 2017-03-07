#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int size = 1000;
char st[size];
int main(){
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    while(~scanf("%s", st)){
        printf("%s\n", st);
    }
    while(gets(st)) puts(st);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
