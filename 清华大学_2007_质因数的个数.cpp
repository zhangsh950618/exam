#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
long long n;
const long long maxn = 1000000;
bool is_prime[maxn];
long long prime[maxn];
long long tot_prime;
void Elur(){
  memset(is_prime, true,sizeof(is_prime));
  memset(prime,0,sizeof(prime));
  tot_prime = 0;
  for(int i = 2 ; i < maxn ; i++){
    if(is_prime) prime[tot_prime++] = i;
    for(int j = 0 ; j < tot_prime ; j++){
      if(prime[j] * i >= maxn) break;
      is_prime[prime[j] * i] = false;
      if(i % prime[j] == 0) break;
    }
  }

}
int main(){
  Elur();
  while(cin >> n){
    long long sum = 0;
    for(long long i = 0 ; i < tot_prime ; i++){
      while(n % prime[i] == 0){
      n /= prime[i];
      if(n == 1) break;
      sum ++;
      }
    }
    if(sum == 0 && n != 1) sum =1;
    cout << sum << endl;
  }
  return 0;
}
