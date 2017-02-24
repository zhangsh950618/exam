#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 100;
int n;
int mark[maxn],map[maxn][maxn];
int row[maxn],col[maxn],odd,even;
int lim;
bool success;
int judge(int r,int c,int n){
  if(row[r] + n > lim) return 0;
  if(col[c] + n > lim) return 0;
  if(r == c && odd + n > lim) return 0;
  if(r + c == n - 1 && even > lim) return 0;
  return 1;
}
void dfs(int step){
  if(success) return;
  if(step == n * n){
    //print the map
    for(int i = 0 ; i < n ; i++) if(row[i] != lim || col[i] != lim) return;
    if(odd != lim || even != lim) return;
    success = true;
    for(int i = 0 ; i < n ; i++){
      for(int j = 0 ; j < n ; j++)
      cout << map[i][j] << " ";
      cout << endl;
    }
    cout << endl;
    return;
  }
  int r = step / n;
  int c = step % n;
  for(int i = 1 ; i <= n * n ; i++){
    if(!mark[i]){
      map[r][c] = i;
      mark[i] = 1;
      if(judge(r , c , i)){//如果成功了才可以下一步，大量减枝
        row[r] += i;
        col[c] += i;
        if(r == c) odd += i;
        if(r + c == n -1) even += i;
        dfs(step + 1);
        row[r] -= i;
        col[c] -= i;
        if(r == c) odd -= i;
        if(r + c == n -1) even -= i;
        map[r][c] = 0;
        mark[i] = 0;
      }else{
        map[r][c] = 0;
        mark[i] = 0;
        break;
      }

    }
  }
}
int main(){
  while(cin >> n){
    memset(map,0,sizeof(map));
    memset(mark,0,sizeof(mark));
    cin >> map[0][0];
    lim = (1 + n * n) * n / 2;
    row[0] += map[0][0];
    col[0] += map[0][0];
    odd += map[0][0];
    mark[map[0][0]] = 1;
    dfs(1);
    if(success) cout << "Yes" << endl;
  }
  return 0;
}
