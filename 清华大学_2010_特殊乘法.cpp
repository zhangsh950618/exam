#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 100;
long long a ,b;
int num_a[maxn],num_b[maxn];
int tot_a,tot_b;
long long solve(long long a,long long b){
  while(a){
    num_a[tot_a++] = a % 10;
    a /= 10;
  }
  while (b) {
    num_b[tot_b++] = b % 10;
    b /= 10;
  }
  long long sum = 0;
  for(int i = 0 ; i < tot_a ; i++)
  for(int j = 0 ; j < tot_b ; j++){
    sum += num_a[i] * num_b[j];
  }
  return sum;
}
int main(){
  while(cin >> a >>b){
    memset(num_a,0,sizeof(num_a));
    memset(num_b,0,sizeof(num_b));
    tot_a = 0;
    tot_b = 0;
    cout << solve(a,b) << endl;
  }
  return 0;
}
