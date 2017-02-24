#include<iostream>
using namespace std;
const int maxn = 1000;
int f[maxn];
int main(){
  f[1] = 1;
  f[2] = 1;
  for(int i = 3 ; i < maxn ; i++){
    f[i] = f[i - 1] + f[i - 2];
  }
  int num;
  while(cin >> num){
    cout << f[num] << endl;
  }
  return 0;

}
