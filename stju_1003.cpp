#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 100 + 10;
int n , t;
int map[maxn][maxn],mark[maxn][maxn];
int dir[4][4] = {{1,0},{-1,0},{0,1},{0,-1}};
int valid(int i,int j){
  return i >= 1 && i <= n && j >= 1 && j <= n;
}
int main(){
  while( cin >> n ){
    int ans = 0;
    t = 0;
    for(int i = 1 ; i <= n ; i++){
      for(int j = 1 ; j <= n ; j++){
        cin >> map[i][j];
        if(map[i][j] > 0) t++;
      }
  }
  while(t < n * n){
    ans ++;
    //初始化mark数组
    memset(mark,0,sizeof(mark));
    for(int i = 1 ; i <= n ; i++)
      for(int j = 1 ; j <= n ; j++)
        //如果不是该轮刚刚更新的并且有传播能力
        if(!mark[i][j] && map[i][j] == 1){
          for(int k = 0 ; k < 4 ; k++){
            //判定位置合法并且还没有被传播
            int ii = i + dir[k][0];
            int jj = j + dir[k][1];
            if(valid(ii,jj) && map[ii][jj] == 0){
              map[ii][jj] = 1;
              t++;
              mark[ii][jj] = 1;
            }
          }
        }

    // for(int i = 1 ; i <= n ; i++){
    //   for(int j = 1 ; j <= n ; j++)
    //   cout << map[i][j] << " ";
    //   cout << endl;
    // }
  }
  cout << ans << endl;
  }
  return 0;
}
