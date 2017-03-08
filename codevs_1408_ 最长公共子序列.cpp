#include<iostream>
#include<iostream>
using namespace std;
const long long size = 3000 + 10;
long long n;
long long a[size], b[size];
long long dp[size][size];
int main(){
    while(cin >> n){
        for(long long i = 1 ; i <= n ; i++) cin >> a[i];
        for(long long i = 1 ; i <= n ; i++) cin >> b[i];

        for(long long i = 1 ; i <= n ; i++)
        for(long long j = 1 ; j <= n ; j++)
            if(a[i] == b[j]) {
                long long max_dp = 0;
            for(long long k = j - 1 ; k >= 1 ; k--){
                if(b[k] < b[j]){
                    max_dp = max(max_dp, dp[i - 1][k]);
                }
            }
            dp[i][j] = max_dp  + 1;
            }
            else
            dp[i][j] = dp[i - 1][j];
        long long ans = dp[n][1];
        for(long long i = 2 ; i <= n; i ++)
        ans = max(ans, dp[n][i]);
        cout << ans << endl;
    }
    return 0;
}
