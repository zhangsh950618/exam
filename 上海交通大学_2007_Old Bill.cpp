#include<iostream>
using namespace std;
int n,a,b,c;
int main(){
  while (cin >> n) {
    int flag = 0;
    cin >> a >> b >> c;
    if(n == 0){
      cout << 0 <<endl;
      continue;
    }
    for(int i =9 ; i >= 0 ; i--){
      for(int j = 9 ; j >= 0 ; j--){
        int tot = i * 10000 + a * 1000 + b * 100 + c * 10 + j;
        if(tot % n == 0){
          cout << i << " " <<  j << " " << tot / n << endl;
          flag = 1;
          break;
        }
      }
      if(flag) break;
    }
    if(!flag) cout << 0 << endl;
  }
  return 0;
}
