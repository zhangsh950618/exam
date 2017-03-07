#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int size = 100000 + 10;
bool is_prime[size];
int prime[size];
int tot_prime;
void elur(){
    memset(is_prime, true, sizeof(is_prime));
    for(int i = 2 ; i < size ; i++){
        if(is_prime[i]) prime[tot_prime++] = i;
        for(int j = 0 ; j < tot_prime ; j++){
            if(i * prime[j] >= size) break;
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0) break;

        }
    }
}
int main(){
    int l = 1680;
    int t = 1;
    elur();
    for(int i = 0 ; i < 100 ; i++)
    cout << prime[i] << endl;
    for(int i = 1 ; i <= 1680 ; i++)
    if(l % i == 0){
        cout << t << " " << i << endl;
        t++;
    }
    int i = 0;
    while(l != 1){
        while(l % prime[i] == 0){
        l /= prime[i];
        cout << prime[i] << endl;
        }
        i++;
    }

    return 0;
}
