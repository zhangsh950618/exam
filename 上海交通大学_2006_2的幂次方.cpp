#include<iostream>
#include<stack>
using namespace std;

int solve(int num){
  stack<int> s;
  while(num){
    s.push(num%2);
    num /= 2;
  }
  int is_first = 1;
  while(!s.empty()){
    if(s.top()){
    int p = s.size() -1;
    if(is_first){
      is_first = 0;
    }else{
      cout << "+";
    }
    cout << "2";
    if(p > 2){
      cout<< "(";
      solve(p);
      cout << ")";
    }
    else if(p != 1){
      cout << "(" << p << ")";
    }
  }
  s.pop();
  }
}
int main(){
  int num;
  while(cin >> num){
    solve(num);
    cout << endl;
  }
  return 0;
}
