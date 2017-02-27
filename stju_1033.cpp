#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stack>
#include<iostream>
#include<map>
using namespace std;
const long long maxn = 100 + 10;
char st[maxn];
stack<char> op;
stack<long long> dig;
bool valid(char st[]){
  stack<char> s;
  long long l = strlen(st);
  for(long long i = 0 ; i < l ; i++){
    if(st[i] == '(') s.push('(');
    else if(st[i] == ')'){
      if(!s.empty()) s.pop();
      else return false;
    //除以0错误
    }else if(st[i] == '0' && st[i - 1] == '/')
      return false;
  }
  if(!s.empty()) return false;
  return true;
}
bool is_number(char c){
  return c >= '0' && c <= '9';
}
bool cal(char c){
  long long b = dig.top();
  dig.pop();
  long long a = dig.top();
  dig.pop();
  switch(c){
    case '+':{
      dig.push(a + b);
      return true;
    }
    case '-':{
      dig.push(a - b);
      return true;
    }
    case '*':{
      dig.push(a * b);
      return true;
    }
    case '/':{
      if(b == 0) return false;
       dig.push(a / b);
       return true;
    }
    case '^':{
      dig.push(pow(a,b));
      return true;
    }
  }
  return true;
}
map<char,long long> im, om;
int main(){
  im['+'] = 4;
  im['-'] = 4;
  im['*'] = 6;
  im['/'] = 6;
  im['^'] = 7;
  im['#'] = 1;

  om['+'] = 3;
  om['-'] = 3;
  om['*'] = 5;
  om['/'] = 5;
  om['^'] = 8;
  om['#'] = 1;

  while(gets(st)){
    bool flag = true;
    bool ok = true;
    if(!valid(st)){
      cout << "Error" << endl;
      continue;
    }
    while(!op.empty()) op.pop();
    while(!dig.empty()) dig.pop();
    op.push('#');
    strcat(st,"#");
    long long i = 0;
    long long l = strlen(st);
    while(i < l){
      if(!ok) break;
      if(is_number(st[i])){
        long long v = 0;
        while(is_number(st[i]))
        v = v * 10 + st[i++] - '0';
        if(flag){
          dig.push(v);
          // cout << v << endl;
        }
        else{
          dig.push(-v);
          // cout << -v << endl;
          flag = true;
        }
      }else if(im[st[i]]){
        char f =  st[i];
        if(f == '-'){
          int j = i - 1;
          while( j >= 0 && st[j] == ' ')j --;
          if(im[st[j]] || j < 0 || st[j] == '(')
          flag = false;//特殊情况
        }
        if(f != '-' || flag){
        while(im[op.top()] > om[f]){
          char c = op.top();
          op.pop();
          if(!cal(c)){ ok = false;cout << "Error" << endl; break; }
        }
        op.push(f);
      }
        i++;
      }else if(st[i] == '('){
        op.push('(');
        i++;
      }else if(st[i] == ')'){
        while(op.top() != '('){
          char c = op.top();
          if(!cal(c)){ ok = false;cout << "Error" << endl; break;}
          op.pop();
        }
        op.pop();//弹出（
        i++;
      }else{
        i++;
      }
    }

    if(!dig.empty() && ok)
    cout << dig.top() << endl;

  }
  return 0;
}
