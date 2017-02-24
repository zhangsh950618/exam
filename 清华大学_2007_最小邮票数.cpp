#include<iostream>
using namespace std;
int dp[100 + 10];
int stamp;
int m,n;
int main(){
  while(cin >> m){
    for(int i = 1  ; i <= m ; i++)
    dp[i] = 21;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
      cin >> stamp;
      for(int j = m ; j >= stamp ; j--){
        if(dp[j] > dp[j - stamp] + 1) dp[j] = dp[j - stamp] + 1;
      }
    }
    int ans = dp[m] == 21 ? 0 : dp[m];
    cout << ans << endl;
  }
  return 0;
}
