#include<iostream>
#include<cstring>
using namespace std;
const int size = 5000 + 100;
int tot_cost, n;
int dp[size];
int main(){
    int cost, value;
    while(cin >> tot_cost >> n){
        memset(dp, 0, sizeof(dp));
        for(int i = 0 ; i < n ; i++){
            cin >> cost >> value;
            for(int j = tot_cost ; j >= cost ; j--)
            dp[j] = max(dp[j], dp[j - cost] + value);
        }
        cout << dp[tot_cost] << endl;

    }
    return 0;
}
