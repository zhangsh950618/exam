#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
const int maxn = 100 + 10;
stack<int> s;
string str;
int judge[maxn];
int main(){
  while(cin >> str){
    memset(judge,0,sizeof(judge));
    while(!s.empty()) s.pop();
    for(int i = 0 ; i < str.length() ; i++){
        if(str[i] == '('){
          s.push(i);
        }else if(str[i] == ')'){
          if(s.size()) s.pop();
          else judge[i] = 1;
        }
    }
    cout << str << endl;
    while(!s.empty()){
      judge[s.top()] = 1;
      s.pop();
    }
    for(int i = 0  ; i < str.length() ; i++){
      if(judge[i]){
        if(str[i] =='(') cout << '$';
        if(str[i] == ')') cout << '?';
      }else cout << " ";
    }
    cout << endl;

  }
  return 0;
}
