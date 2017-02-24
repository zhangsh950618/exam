#include<iostream>
#include<queue>
using namespace std;
int solve(int num){
  queue<int> s;
  int temp = num;
  int sum = 0;
  while(temp){
    s.push(temp % 10);
    temp /= 10;
  }
  while(!s.empty()){
    sum = sum * 10 + s.front();
    s.pop();
  }
  return num * 9 == sum ? 1 : 0;
}
int main(){
  for(int i = 1000 ; i < 10000 ; i++) if(solve(i)) cout << i << endl;
  return 0;
}
