#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
const int maxn = sqrt(2147483647) + 1;
bool is_prime[maxn];
int prime[maxn], mark[maxn], t, n;
void Elur(){
  memset(is_prime , true , sizeof(is_prime));
  memset(prime , 0 , sizeof(prime));
  t = 0;
  for(int i = 2 ; i < maxn ; i++){
      if(is_prime[i]) prime[t++] = i;
      for(int j = 0 ; j < t ; j++){
        if(prime[j] * i >= maxn) break;
        is_prime[prime[j] * i] = false;
        if(i % prime[j] == 0) break;
      }
  }
}
int main(){
  //欧拉求素数
  Elur();
  while( cin >> n){
    cout << n << "=";
    memset(mark, 0 , sizeof(mark));
    int l = 0 ;
    while(n != 1 && l < t){
      while(n % prime[l] == 0){
        n /= prime[l];
        mark[l]++;
      }
      l++;
    }
    for(int i = 0 ; i < l ; i++){
      if(mark[i]){
        cout << prime[i] << "(" << mark[i] << ")";
      }
    }

    //如果是大素数
    if(n != 1){
      cout << n << "(1)";
    }


    cout << endl;
  }
  return 0;
}
