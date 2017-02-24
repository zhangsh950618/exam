#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 10000 + 10;
int dp[maxn];
int c , w;
int main(){
  int v, n;
  while(cin >> v >> n){
    memset(dp, 0, sizeof(dp));
    for(int i = 0 ; i < n ; i++){
      cin >> c >> w;
      for(int j = c ; j <= v ; j++)
      dp[j] = max(dp[j], dp[j - c] + w);
    }
    cout << dp[v] << endl;
  }
  return 0;
}
