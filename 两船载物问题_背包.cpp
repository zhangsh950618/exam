#include<iostream>
#include<cstring>
using namespace std;
const int size = 5000 + 100;
int n, c1, c2;
int dp[size];
int main(){
    while(cin >> n >> c1 >> c2){
        int temp = 0;
        int sum = 0;
        memset(dp, 0, sizeof(dp));
        for(int i = 0 ; i < n ; i++){
            cin >> temp;
            sum += temp;
            for(int j = c1 ; j >= temp ; j--){
                dp[j] = max(dp[j], dp[j - temp] + temp);
            }
        }
        if(sum - dp[c1] > c2) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
