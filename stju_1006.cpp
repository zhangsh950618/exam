#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int maxn = 1000000 + 10;
int dp[maxn], num[maxn];
int main(){
  int n;
  while(cin >> n){
    memset(dp,0,sizeof(dp));
    memset(num,0,sizeof(num));
    for(int i = 1 ; i <= n ; i++) scanf("%d",&num[i]);
    for(int i = 1 ; i <= n ; i++){
      if(dp[i - 1] < 0) dp[i] = num[i];
      else dp[i] = dp[i - 1] + num[i];
    }
    int max_sum = dp[1];
    for(int i = 2 ; i <= n ; i++) max_sum = max(max_sum, dp[i]);
    if(max_sum > 0) cout << max_sum << endl;
    else cout << "Game Over" << endl;
  }

}
