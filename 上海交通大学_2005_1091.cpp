#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int size = 10;
const int INF = (1 << 30);
int map[size][size];
bool mark[size][size];
int min_cost[size][size];
int n;
int ans = INF;
int si,sj,ei,ej;
int dir[2][2] = {{1, 0}, {0, 1}};
bool valid(int i, int j){
    return i >= 0 && i < 6 && j >= 0 && j < 6;
}
void dfs(int ci, int cj, int cost){
    if(ci == ei && cj == ej){
        ans = min(ans, cost);
        return ;
    }
    for(int i = 0 ; i < 2 ; i++){
        int ni = ci + dir[i][0];
        int nj = cj + dir[i][1];
        if(!mark[ni][nj] && valid(ni, nj)){
            int temp = map[ni][nj];
            int c = map[ci][cj] * map[ni][nj];
//            cout << "c : " << c << endl;
            mark[ni][nj] = true;
            map[ni][nj] += c % 4;
            dfs(ni, nj, cost + c);
            map[ni][nj] = temp;
            mark[ni][nj] = false;
        }
    }
}
int main(){
    cin >> n;
    while(n --){
        ans = INF;
        memset(mark, false, sizeof(mark));
        memset(map, 0, sizeof(map));

        for(int i = 0 ; i < 6 ; i++)
        for(int j = 0 ; j < 6 ; j++)
        cin >> map[i][j];

        cin >> si >> sj >> ei >> ej;
        map[si][sj] = true;

        dfs(si, sj, 0);

        cout << ans << endl;
    }

    return 0;
}
