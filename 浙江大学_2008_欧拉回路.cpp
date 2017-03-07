#include<iostream>
#include<cstring>
using namespace std;
const int size = 1000 + 10;
int n, m;
bool matrix[size][size];
bool flag = false;

int main(){
    while(cin >> n >> m && n){
        flag = false;
        int s, e;
        memset(matrix, false, sizeof(matrix));
        for(int i = 0 ; i < m ; i++){
            cin >> s >> e;
            matrix[s][e] = matrix[e][s] = true;
        }
        for(int i = 1 ; i <= n ; i++){
            if(!flag) dfs(i, 0);
        }
        if(flag == false) cout << 0 << endl;
        else cout << 1 << endl;
    }
    return 0;
}
