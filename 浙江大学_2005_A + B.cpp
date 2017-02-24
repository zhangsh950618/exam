#include<iostream>
#include<string.h>
#include<map>
using namespace std;
map<string,int> m;
string str;
int main(){
  m["one"] = 1;
  m["two"] = 2;
  m["three"] = 3;
  m["four"] = 4;
  m["five"] = 5;
  m["six"] = 6;
  m["seven"] = 7;
  m["eight"] = 8;
  m["nine"] = 9;
  m["zero"] = 0;
  m["+"] = 10;
  m["="] = 11;
  while(cin >> str){
    int sum = 0,a = 0,b = 0;
    int str2num = m[str];
    int flag = 1;
    if(str2num >= 0  && str2num < 10)//如果是数字
      a = a * 10 + str2num；


  }
  return 0;
}
