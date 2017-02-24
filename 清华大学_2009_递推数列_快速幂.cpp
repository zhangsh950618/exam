`#include<iostream>
using namespace std;
const long long maxn = 2;
const long long mod = 10000;
long long p[maxn][maxn],res[maxn][maxn];
void power(){
  long long c[maxn][maxn] = {0};
  for(long long i = 0 ;i < maxn ; i++){
    for(long long j = 0 ; j < maxn ; j++){
      long long sum = 0;
      for(long long k = 0 ; k < maxn ; k++){
        sum += p[i][k] * p[k][j];
        sum %= mod;
      }
      c[i][j] = sum;    }
  }
  for(long long i = 0 ; i < maxn ; i++)
  for(long long j = 0 ; j < maxn ; j++)
  p[i][j] = c[i][j];
}
void mul(){
  long long c[maxn][maxn] = {0};
  for(long long i = 0 ;i < maxn ; i++){
    for(long long j = 0 ; j < 1 ; j++){
      long long sum = 0;
      for(long long k = 0 ; k < maxn ; k++){
        sum += p[i][k] * res[k][j];
        sum %= mod;
      }
      c[i][j] = sum;
    }
  }
  for(long long i = 0 ; i < maxn ; i++)
  for(long long j = 0 ; j < 1 ; j++)
  res[i][j] = c[i][j];
}
// void prlong long(long long a[maxn][maxn]){
//   for(long long i = 0 ; i < maxn ; i++){
//     for(long long j = 0 ; j < maxn ; j++)
//     cout << a[i][j] << " ";
//     cout << endl;
//   }
// }
long long a0,a1,pp,q,k;
int main(){
  while(cin >> a0>> a1 >> pp >>q >>k){
    res[0][0] = a1;
    res[1][0] = a0;
    p[0][0] = pp % mod;
    p[0][1] = q % mod;
    p[1][0] = 1;
    p[1][1] = 0;
    if(k == 0){ cout << a0 << endl; continue;}
    k -= 1;
    while(k){
      if(k & 1) mul();
      power();
      k = (k >> 1);
    }
    cout << res[0][0] << endl;
  }
  return 0;
}
`
