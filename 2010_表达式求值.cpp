#include<iostream>
#include<map>
#include<stack>
#include<string.h>
using namespace std;
map<char,long long> m;
stack<char> flag;
stack<long long> num;
long long is_num(char c){
  if(c >= '0' && c <= '9')
  return 1;
  return 0;
}
long long cal(long long a,char f,long long b){
  long long sum;
  if(f == '+')sum = a +b;
  else if(f == '-')sum = a - b;
  else if(f == '*')sum = a * b;
  else if(f == '/')sum = b / a;
  return sum;
}
int main(){
  m['+'] = 1;
  m['-'] = 1;
  m['*'] = 2;
  m['/'] = 2;
  string str;
  while(cin >> str){

    long long sum = 0;//初始化部分和为0
    long long i , j;
    //清空栈
    while (!flag.empty()) {
      flag.pop();
    }
    while(!num.empty()){
      num.pop();
    }
    flag.push('+');
    num.push(0);
    long long len = str.length();
    long long a = 0;
    long long tem_a,tem_b,tem_sum;
    char f,tem_f;
    for(i = 0 ; i < len ; i++){//处理操作数
        if(is_num(str[i])){
          a = a * 10 + (str[i] - '0');
        }else{//处理操作符
          num.push(a);//将操作数压入num栈中
          a = 0;
          f = str[i];//f为当前的操作符
          while (! flag.empty() && m[f] <= m[flag.top()]) {
            tem_f = flag.top();
            flag.pop();
            tem_a = num.top();
            num.pop();
            tem_b = num.top();
            num.pop();
            tem_sum = cal(tem_a,tem_f,tem_b);
            cout << "计算" << tem_a << tem_f << tem_b << endl;
            num.push(tem_sum);
          }
          flag.push(f);
        }
    }
    num.push(a);
    while (!flag.empty()) {
      tem_f = flag.top();
      flag.pop();
      tem_a = num.top();
      num.pop();
      tem_b = num.top();
      num.pop();
      tem_sum = cal(tem_a,tem_f,tem_b);
      cout << "计算" << tem_a << tem_f << tem_b << endl;
      num.push(tem_sum);
    }
    cout << num.top() << endl;
  }
  return 0;
}
