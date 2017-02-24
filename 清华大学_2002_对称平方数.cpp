#include<iostream>
#include<deque>
using namespace std;
int solve(int num){
  deque<int> q;
  while(num){
    q.push_back(num % 10);
    num /= 10;
  }
  while(!q.empty()){
    if(q.front() != q.back())
    return 0;
    q.pop_front();
    if(q.empty()) break;
    q.pop_back();
  }
  return 1;
}
int main(){
  for(int i = 0 ;  i < 256 ; i++)
    if(solve(i * i)) cout << i << endl;
  return 0;
}
