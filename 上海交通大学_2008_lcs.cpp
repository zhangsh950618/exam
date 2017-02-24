#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 1000;
int dp[maxn][maxn];
int main() {
  string a,b;
  int t;
  while (cin >> a >> b) {
    memset(dp,0,sizeof(dp));
    int len_a = a.length();
    int len_b = b.length();
    for(int i = 0 ; i < len_a  ; i++)
    for(int j = 0; j < len_b ; j++){
      if(a[i] == b[j]){
        dp[i][j] = dp[i-1][j-1] + 1;
      }else{
        dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
      }
    }
    // for(int i = 0 ; i < len_a ; i++){
    // for(int j = 0 ; j < len_b ; j++){
    //   cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    cout << dp[len_a - 1][len_b -1] << endl;
  }
  return 0;
}
