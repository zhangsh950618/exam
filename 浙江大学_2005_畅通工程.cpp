#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//ifstream cin("1.in");
//ofstream cout("1.out");
const int size = 1000 + 10;
bool matrix[size][size];
bool mark[size];
int n, m, s, e;
void dfs(int step){
    for(int i = 1 ; i <= n ; i++){
        if(!mark[i] && matrix[step][i]){
            mark[i] = true;
            dfs(i);
        }
    }
}
int main(){
    while(cin >> n){
        if(n == 0) break;
        memset(matrix, false, sizeof(matrix));
        memset(mark, false, sizeof(mark));
        cin >> m;
        for(int i =  0 ; i < m ; i++){
            cin >> s >> e;
            matrix[s][e] = matrix[e][s] = true;
        }
        int sum = 0;
        for(int i = 1 ; i <= n ; i++){
            if(!mark[i]){
                dfs(i);
                sum ++;
             }
        }
        cout << sum - 1 << endl;
    }
    return 0;
}
