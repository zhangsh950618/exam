#include<iostream>
using namespace std;
const int maxn = 1000000+10;
int f[maxn],map[maxn];
int main(){
  map[1] = 1;
  f[0] = 1;
  for(int i = 1 ; i < maxn ; i++){
    f[i] = f[i -1] * i;
    // cout << i << " ," << f[i] << endl;
    for(int j = maxn - 1 ; j>=0 ; j--){
      if(j-f[i] >= 0 && map[j - f[i]] == 1){
        map[j] = 1;
      }

    }
    if(f[i] > maxn) break;
  }
  int t;
  while (cin >> t) {

    if(map[t]){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
  return 0;

}
