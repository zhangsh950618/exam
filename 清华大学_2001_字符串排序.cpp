#include<iostream>
#include<set>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int size = 100;
char st[size];
int main(){
    while(~scanf("%s", st)){
        int len = strlen(st);
        sort(st, st + len);
        printf("%s\n", st);
    }

    return 0;
}
