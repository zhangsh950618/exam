#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int size = 6;
const int INF = (1 << 30);
int m[size][size];
bool mark[size][size];
int under[size][size];
int n;
int si, sj, ei, ej;
int min_cost = INF;
int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool valid(int i, int j){
    return i >= 0 && i <= 5 && j >= 0 && j <= 5;
}
void dfs(int ci, int cj, int cost){
    if(cost >= min_cost) return;
    if(ci == ei && cj == ej){
        min_cost = min(cost, min_cost);
        return;
    }

    for(int i = 0 ; i < 4 ; i++){
        int ni = ci + d[i][0];
        int nj = cj + d[i][1];
        if(valid(ni, nj) && !mark[ni][nj]){
        int temp;
        temp = m[ni][nj];
        int c = m[ci][cj] * m[ni][nj];
//        if(cost + c < under[ni][nj]){
            under[ni][nj] = cost + c;
            mark[ni][nj] = true;
            m[ni][nj] = c % 4 + 1;
            dfs(ni, nj, cost + c);
            mark[ni][nj] = false;
            m[ni][nj] = temp;
//        }
        }
    }
}
int main(){
    cin >> n;
    while(n--){
    min_cost = INF;
    memset(mark, false, sizeof(mark));
    memset(m, 0, sizeof(m));
    for(int i = 0 ; i < size ; i++)
    for(int j = 0 ; j < size ; j++){
        cin >> m[i][j];
        under[i][j] = INF;
    }

    cin >> si >> sj >> ei >> ej;
    dfs(si, sj, 0);
    cout << min_cost << endl;
    }
    return 0;
}
