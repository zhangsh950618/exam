#include<iostream>
#include<stack>
#include<string.h>
#include<map>
using namespace std;
string st;
stack<char> op;
stack<int> dig;
map<char,int> m;
bool is_number(char c){
  return c >= '0' && c <= '9';
}
void cal(char c){
  int b = dig.top();
  dig.pop();
  int a = dig.top();
  dig.pop();
  switch(c){
    case '+':{
      dig.push(a + b);
        break;
    }
    case '-':{
      dig.push(a - b);
        break;
    }
    case '*':{
      dig.push(a * b);
        break;
    }
    case '/':{
      dig.push(a / b);
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

  while(cin >> st){

    st += '#';

    while(!op.empty()) op.pop();
    while(!dig.empty()) dig.pop();

    op.push('#');

    int l = st.length();
    int i = 0;
    while(i < l){
      if(is_number(st[i])){
        int v = 0;
        while(is_number(st[i]))
        v = v * 10 + st[i++] - '0';
        dig.push(v);
      // 处理 + - * /四则运算的符号
      }else if(m[st[i]]){
        char f = st[i];
        while(m[f] <= m[op.top()]){
          char c = op.top();
          if(f == '#' && c == '#') break;
          op.pop();
          cal(c);
        }
        op.push(f);
        i++;
      }else if(st[i] == '('){
        //遇到左括号压入stack
        op.push('(');
        i++;
      }else if(st[i] == ')'){
        while(op.top() != '('){
          char c = op.top();
          op.pop();
          cal(c);
        }
        op.pop();//弹出左括号
        i++;
      }
    }

    // if(!dig.empty())
    cout << dig.top() << endl;
  }
  return 0;
}
