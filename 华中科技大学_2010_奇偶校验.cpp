#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
string str;
stack<int> s;
void trans(char c){
    int tot = 0;
    int len = 7;
    while(c){
      int t = c % 2;
      if(t) tot++;
      s.push(t);
      len--;
      c /= 2;
    }
    if(tot%2){
      cout << 0;
    }else{
      cout << 1;
    }
    while(len--) cout << 0;
    while(!s.empty()){
      cout << s.top();
      s.pop();
    }
    cout << endl;
}
int main(){
  while(cin >> str){
    for(int i = 0 ; i < str.length() ; i++){
      char c = str[i];
      trans(c);
    }
  }
  return 0;
}
