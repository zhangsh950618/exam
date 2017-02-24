#include<iostream>
#include<string.h>
#include<map>
#include<stack>
using namespace std;
string str;
stack<char> op;
stack<int> dig;
map<char, int> m;
bool is_num(char c){
  return c >= '0' && c <= '9';
}
void cal(char c){
  int a = dig.top();
  dig.pop();
  int b = dig.top();
  dig.pop();
  // cout << a << " " << c << " " << b << endl;
  switch(c){
    case '+':{
      dig.push(a + b);
      break;;
    }
    case '-':{
      dig.push(b - a);
      break;
    }
    case '*':{
      dig.push(a * b);
      break;
    }
    case '/':{
      dig.push(b / a);
      break;
    }
  }
}
int main(){
  m['#'] = 1;
  m['+'] = 2;
  m['-'] = 2;
  m['*'] = 3;
  m['/'] = 3;
  while(cin >> str){
    while(!op.empty()) op.pop();
    while(!dig.empty()) dig.pop();
    op.push('#');
    str = str + "#";
    int l =str.length();
    int i = 0;
    while(i < l){
        if(is_num(str[i])){
          int v = 0;
          while(is_num(str[i]))
          v = v * 10 + str[i++] - '0';
          dig.push(v);
        }else{
          char f = str[i++];
          if(f == '(') {
            op.push('(');
          }
          else if(f == ')'){
            while(op.top() != '('){
              char c = op.top();
              op.pop();
              cal(c);
            }
            op.pop();
          }else{//其他符号
              while(m[f] <= m[op.top()]){
                if(f == '#' && op.top() == '#') break;
                char c = op.top();
                op.pop();
                cal(c);
              }
              op.push(f);
          }
        }
      }
      cout << dig.top() << endl;
    }
return 0;
  }
