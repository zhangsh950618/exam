#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 1000000 + 10;
bool is_prime[maxn];
int prime[maxn];
int tot_prime;
int main(){
  int k;
  memset(is_prime, true , sizeof(is_prime));
  for(int i = 2 ; i < maxn ; i++){
    if(is_prime[i]) prime[tot_prime++] = i;
    for(int j = 0 ; j < tot_prime ; j++){
      if(prime[j] * i > maxn) break;
      is_prime[prime[j] * i] = false;
      if(i % prime[j] == 0) break;
    }
  }
  while(cin >> k){
    cout << prime[k-1] << endl;
  }
  return 0;
}
