#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int size = 100 + 2;
int n, t;
bool mark[size], is_prime[size];
int ans[size], prime[size];
bool flag = false;
void dfs(int step){
    if(step == n + 1){
        if(!is_prime[ans[1] + ans[n]])return;
        flag = true;
        int i = 0;
        for(i = 1 ; i < n; i++) cout << ans[i] << " ";
        cout << ans[i] << endl;
        return ;
    }

    for(int i = 2 ; i <= n ; i++){
        // if is available
        if(!mark[i] && is_prime[ans[step - 1] + i]){
            mark[i] = true;
            ans[step] = i;
            dfs(step + 1);
            mark[i] = false;
        }
    }


}
void elur(){
    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = is_prime[0] =false;
    for(int i = 2 ; i < size ; i++){
        if(is_prime[i]) prime[t++] = i;
        for(int j = 0 ; j < t ; j++){
            if(i * prime[j] >= size) break;
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0) break;
        }
    }
}
int main(){
    elur();
//    for(int i = 0 ; i < t ; i++) cout << prime[i] << endl;
    while(cin >> n){
        ans[1] = 1;
        flag = false;
        if(n == 1){
            cout << "no" << endl;
            continue;
        }
        dfs(2);
        if(!flag) cout << "no" << endl;
    }

    return 0;
}
