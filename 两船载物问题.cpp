#include<iostream>
#include<algorithm>
using namespace std;
const int size = 200;
int n, c1, c2;
int item[size];
bool flag;
bool cmp(int a, int b){
    return a > b;
}

void dfs(int step, int cc1, int cc2){
    if(flag) return ;
    if(cc1 > c1 || cc2 > c2) return;
    if(step == n){
        flag = true;
        return ;
    }
    dfs(step + 1, cc1 + item[step], cc2);
    dfs(step + 1, cc1, cc2 + item[step]);
}
int main(){
    while(cin >> n >> c1 >> c2){
        flag = false;
        for(int i = 0 ; i < n ; i++) cin >> item[i];
        sort(item, item + n, cmp);
        dfs(0, 0, 0);
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
