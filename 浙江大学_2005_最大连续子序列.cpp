#include<iostream>
#include<cstring>
using namespace std;
const int size = 10000 + 100;
const int INF = -(1 << 30);
int n;
int number[size];
int dp[size], start[size];
int main(){
    while(cin >> n){
        if(n == 0) break;
        memset(number, 0 ,sizeof(number));
        memset(dp, 0, sizeof(dp));
        memset(start, 0, sizeof(start));
        bool all_minus = true;
        for(int i = 0 ; i < n ; i++){
            cin >> number[i];
            if(number[i] >= 0) all_minus = false;
        }
        if(all_minus){
            cout << 0 << " " << number[0] << " " << number[n - 1] << endl;
            continue;
        }
        dp[0] = number[0];
        start[0] = 0;
        for(int i = 1 ; i < n ; i++){
            if(dp[i - 1] < 0){
                dp[i] = number[i];
                start[i] = i;
            }else{

                dp[i] = number[i] + dp[i -1];
                start[i] = start[i -1];
            }
        }
        int max_sum = dp[0];
        int pos = 0;
        for(int i = 1 ; i < n ; i++){
            if(dp[i] > max_sum){
                max_sum = dp[i];
                pos = i;
            }
        }

        cout << dp[pos] << " " << number[start[pos]] << " " << number[pos] << endl;
    }
    return 0;
}
