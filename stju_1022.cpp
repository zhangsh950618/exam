#include<iostream>
using namespace std;
const long long maxn = 10;
const long long mod = 2010;
struct mat{
  long long r , c;
  long long d[maxn][maxn];
};
mat operator *(mat a, mat b){
  //判断是否可以计算
  mat c;
  if(a.c == b.r){
  for(long long i = 0 ; i < a.r ; i++)
  for(long long j = 0 ; j < b.c ; j++){
    long long s = 0;
    for(long long k = 0 ; k < a.c ; k++){
      s += (a.d[i][k] * b.d[k][j]) % mod;
      s %= mod;
    }
    // cout << "s = " << s << endl;
    c.d[i][j] = s;
  }
  c.r = a.r;
  c.c = b.c;
  // for(long long i = 0 ; i < c.r ; i++){
  //   for(long long j = 0 ; j < c.c ; j++)
  //   cout << c.d[i][j] << " ";
  //   cout << endl;
  // }
  return c;
  }
}
int main(){
  long long n;
  while(cin >> n){
    mat p;
    p.r = 2;
    p.c = 2;
    p.d[0][0] = 1;
    p.d[0][1] = 1;
    p.d[1][0] = 1;
    p.d[1][1] = 0;
    mat a;
    a.r = 2;
    a.c = 1;
    a.d[0][0] = 1;
    a.d[1][0] = 1;
    //如果要计算a[n]，那么需要迭代n - 2次
    n -= 2;
    if(n <= 0){
      cout << 1 << endl;
      continue;
    }
    while(n){
      if(n & 1){
        a = p * a;
      }
      n = (n >> 1);
      p = p * p;
    }
    cout << a.d[0][0] << endl;

  }
  return 0;
}
