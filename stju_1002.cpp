#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int maxn = 1000 + 10;
int map[maxn][maxn],dp[maxn][maxn],row[maxn][maxn],col[maxn][maxn];
int ans;
int a , b , l , w;
int main(){
  while(cin >> a >> b){
    memset(map,0,sizeof(map));
    memset(dp,0,sizeof(dp));
    for(int i = 1 ; i <= a ; i++)
    for(int j = 1 ; j <= b ; j++)
    scanf("%d",&map[i][j]);
    for(int i = 1 ; i <= a ; i++){
      for(int j = 1 ; j <= b ; j++){
        row[i][j] = row[i][j - 1] + map[i][j];
      }
    }
    for(int j = 1 ; j <= b ; j++)
    for(int i = 1 ; i <= a ; i++){
      col[i][j] = col[i - 1][j] + map[i][j];
    }
    cin >> l >> w;

    for(int i = 1 ; i <= l ; i++)
    for(int j = 1 ; j <= w ; j++)
      dp[l][w] += map[i][j];

      ans = dp[l][w];
    for(int i = 1 ; i <= a ; i++)
    for(int j = 1 ; j <= b ; j++){
      if(i >= l && j >= w && !dp[i][j]){ //可以计算dp[i][j]
        if(j - 1 >= w){// 由dp[i][j - 1]向右移动
          dp[i][j] = dp[i][j - 1];
          dp[i][j] += col[i][j] - col[i - l][j];
          dp[i][j] -= col[i][j - w] - col[i - l][j - w];
        }else{
          dp[i][j] = dp[i - 1][j];
          dp[i][j] += row[i][j] - row[i][j - w];
          dp[i][j] -= row[i - l][j] - row[i - l][j - w];
        }
        ans = max(ans,dp[i][j]);
      }
    }
    // for(int i = 1 ; i <= a ; i++){
    //   for(int j = 1 ; j <= b ; j++)
    //   cout << dp[i][j] << " ";
    //   cout << endl;
    // }
    cout << ans << endl;
  }
  return 0;
}
