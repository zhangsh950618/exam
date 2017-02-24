#include<iostream>
using namespace std;
const int maxn = 1000000;
int dp[maxn],num[maxn];
int main(){
  int n;
  while(cin >> n){
    cin >> num[0];
    dp[0] = num[0];
    for(int i = 1 ; i < n ; i++){
      cin >> num[i];
      if(dp[i - 1] < 0)
      dp[i] = num[i];
      else
      dp[i] = num[i] + dp[i - 1];
    }
    for(int i = 0 ; i < n ; i++)
    cout << num[i] << " ";
    cout << endl;
    for(int i = 0 ; i < n ; i++)
    cout << dp[i] << " ";
    cout << endl;
  }
  return 0;
}
