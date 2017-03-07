#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int size = 200000 * 2 + 10;
string t, st;
int dp[size];
int pos, max_right;
void manacher(string st){
    int len = st.length();
    for(int i = 0 ; i  < len ; i++){
        dp[i] = i < max_right ? min(dp[2 * pos - i], max_right - i) :1;
        while(st[i + dp[i]] == st[i - dp[i]]) dp[i] ++;
        if(i + dp[i] > max_right){
            pos = i;
            max_right = i + dp[i];
        }
    }
}
int main(){
    while(cin >> t){
        st = "$";
        for(int i = 0 ; i < t.length() ; i++){
            st += '#';
            st += t[i];
        }
        st += "#";
        pos = 0;
        max_right = 0;
//        cout << st << endl;
        memset(dp, 0, sizeof(dp));
        manacher(st);
        int max_r = 0;
        for(int i = 0 ;i < st.length() ; i++){
//            cout << "dp" << i << " " << dp[i] << endl;
            max_r = max(max_r, dp[i]);
        }
        cout << max_r - 1 << endl;
    }
    return 0;
}
