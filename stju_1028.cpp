#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
stack<string> s;
int n;
int main(){
  while(cin >> n){
    string st;
    int flag  = true;
    int is_if = false;
    while(!s.empty()) s.pop();
    for(int i = 0 ; i < n ; i++) {
      cin >> st;

      //如果需要判定
      if(flag){
        if(is_if){
          if(st == "then") is_if = false;
          else flag = false;
        }
        if(st == "if"){
          is_if = true;
          s.push("if");
        }else if(st == "begin")
        s.push("begin");
        else if(st == "end"){
          while(!s.empty() && s.top() != "begin") s.pop();
          if(s.empty()) flag = false;
          else s.pop();
        }else if(st == "else"){
          // cout << "else" << endl;
          if(!s.empty() && s.top() == "if") s.pop();
          else flag = false;
        }
      }
    }

    while(!s.empty()){
      if(s.top() == "if") s.pop();
      else {
        flag = false;
        break;
      }
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
