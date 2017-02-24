#include<iostream>
using namespace std;
int is_flag(char c){
  return c == '+' || c == '-';
}
int is_number(char c){
  return c >= '0' || c <= '9';
}
void cal(int &num,char f,int &temp){
  if(temp == 0) temp = 1;
  if(f == '+') num += temp;
  else if(f == '-') num -= temp;
  //刷新temp
  temp = 0;
}
void solve(string str,int &a,int &b,int &c){
  char f = '+';
  int temp = 0;
  for(int i = 0 ; i < str.length() ; i++){
    if(str[i] == 'x'){ //存在两种可能,一次方前面的系数，也可能是二次方前面的系数
      if(str.substr(i,3) == "x^2"){//如果是二次方前面的系数
        cout << "f = " << f << endl;
        cal(a,f,temp);
      }else{//如果是一次方前面的系数
        cal(b,f,temp);
      }
    }else if(is_number(str[i])){//如果是数字
      temp = temp * 10 + str[i] - '0';
    }else if(is_flag(str[i])){
      cal(c,f,temp);
      f = str[i];
    }
  }
}
int main(){
  string str = "x^2+x";
  int a = 0,b = 0,c = 0;
  solve(str,a,b,c);
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;
  return 0;
}
