#include<iostream>
using namespace std;
const int maxn = 5000 + 10;
int num[maxn],dp[maxn];
int t;
int main(){
  while (cin >> t) {
    for(int i = 0 ; i < t ; i++) {
      cin >> num[i];
      dp[i] = 1;
    }
    for(int i = 0 ; i < t ; i++){
      for(int j = 0 ; j < i ; j++){
        if(num[j] < num[i]){
          dp[i] = max(dp[j] + 1, dp[i]);
        }
      }
    }
    int len = 0;
    for(int i = 0 ; i < t ; i++) len = max(len,dp[i]);
    cout << len << endl;
  }
  return 0;
}
