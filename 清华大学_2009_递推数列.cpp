#include<iostream>
using namespace std;
const int maxn = 10000;
int a0,a1,p,q,k;
int main(){
  while(cin >> a0 >> a1 >> p >> q >> k){
    for(int i = 2 ; i <= k ; i++){
      int temp = a1;
      a1 = (p * a1 + q * a0) % maxn;
      a0 = temp;
    }
    cout << a1 << endl;
  }
  return 0;
}
