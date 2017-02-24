#include<iostream>
using namespace std;
int fib(int n){
  if(n <= 1){
    return n;
    cout << n << endl;;
  }else{
    int ans = fib(n -2) + fib(n - 1);
    cout << ans << endl;
    return ans;
  }

}
int main(){
  int n;
  while(cin >> n) fib(n);
  return 0;

}
