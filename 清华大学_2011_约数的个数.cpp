#include<iostream>
#include<cstring>
using namespace std;
const int size = 100000 + 10;
bool is_prime[size];
int prime[size];
int c[size];
int tot_prime;
void elur(){
    tot_prime = 0;
    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = false;
    for(int i = 2 ; i < size ; i++){
        if(is_prime[i]) prime[tot_prime++] = i;
        for(int j = 0 ; j < tot_prime ; j++){
            if(i * prime[j] >= size) break;
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0) break;
        }
    }
}
int n;
int solve(int num){
    memset(c, 0, sizeof(c));
    int t = 0;
    bool flag = false;
    while(num != 1){
        while(num % prime[t] == 0){
            c[t]++;
            num /= prime[t];
        }
        t ++;
        if(prime[t] == 0){
            flag = true;
            break;
        }
    }
    int ans = 1;
    for(int i = 0 ; i < t ; i++){
        if(c[i]) ans *= c[i] + 1;
    }
    if(flag) ans *= 2;
    return  ans;
}
int main(){
    elur();
//    for(int i = 0 ;i < 20 ; i++) cout << prime[i] << endl;
    while(cin >> n){
        if(n == 0) break;
        int number;
        for(int i = 0 ; i < n ; i++){
            cin >> number;
            cout << solve(number) << endl;
        }
    }
    return 0;
}
