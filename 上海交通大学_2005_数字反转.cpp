#include<iostream>
#include<queue>
using namespace std;
int a,b;
int reverse(int num){
  queue<int> q;
  while(num){
    q.push(num % 10);
    num /= 10;
  }
  int val = 0;
  while (!q.empty()) {
    val *= 10;
    val += q.front();
    q.pop();
  }
  return val;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    // cout << reverse(100) << endl;
    cin >> a >> b;
    if(reverse(a+b) == (reverse(a) + reverse(b))) cout << a + b << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
