#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
string str;
int t;
stack<char> s;
int main(){
  while(cin >> t){

    for(int i = 0 ; i < t ; i++){
      while(!s.empty()) s.pop();
      cin >> str;
      int flag = 1;
      for(int j = 0 ; j < str.length() ; j++){
        if(str[j] == '(') s.push('(');
        else{
          if(s.empty() || s.top() != '(') flag = 0;
          else s.pop();
        }
      }
    if(!s.empty()) flag = 0;
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
  return 0;
}
