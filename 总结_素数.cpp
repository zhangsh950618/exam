#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
const int maxn = 10000;
bool is_prime[maxn];
int tot_prime;
int prime[maxn];
void print(){
  for(int i = 0 ; i  < 10 ; i++) cout << prime[i] << endl;
}
int solve(int num){
  int lim = sqrt(num);
  for(int i = 2 ; i <= lim ; i++){
    if(num % i == 0) return 0;
  }
  return 1;
}
void simple(){
  memset(is_prime,0,sizeof(is_prime));
  memset(prime,0,sizeof(prime));
  tot_prime = 0;
  for(int i = 2 ; i < maxn ; i++){
    if(solve(i)){
      prime[tot_prime++] = i;
    }
  }

}
void Era(){
  memset(is_prime, true,sizeof(is_prime));
  memset(prime,0,sizeof(prime));
  tot_prime = 0;
  for(int i = 2 ; i < maxn ; i++){
    if(is_prime[i]){
      prime[tot_prime++] = i;
      for(int j = i * i ; j < maxn ; j += i) is_prime[j] = false;
    }
  }
}
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
  simple();//朴素算法，时间复杂度为n^2
  print();
  Era();
  print();
  Elur();
  print();
  return 0;
}
