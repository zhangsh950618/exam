#include<iostream>
using namespace std;
const int maxn = 100000;
int prime[maxn];
int tot_prime;
int is_prime(int num){
  for(int i = 2 ; i  < num ; i++){
    if(num % i == 0)
    return 0;
  }
  return 1;
}
int main(){
  int t;
  while (cin >> t) {
    tot_prime = 0;
    int k = 2;
    while (tot_prime < t) {
      if(is_prime(k))
      prime[tot_prime++] = k;
      k++;
    }
    cout << prime[tot_prime-1] << endl;
  }
  return 0;
}
