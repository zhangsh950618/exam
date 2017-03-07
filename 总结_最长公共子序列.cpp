#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int size = 1000;
string s1, s2;
int dp[size][size];
int main(){
    while(cin >> s1 >> s2){
        memset(dp, 0, sizeof(dp));
        int l1 = s1.length();
        int l2 = s2.length();
        for(int i = 1 ; i <= l1 ; i++)
            for(int j = 1 ; j <= l2 ; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[l1][l2] << endl;
    }

    return 0;
}
