#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>
using namespace std;
string str;
int is_num(char c){
  return c >= '0' && c <= '9';
}
struct Xi{
  int a;
  int b;
  int c;
};
Xi get_xi(string str){
  Xi x;
  x.a = 0;
  x.b = 0;
  x.c = 0;
  int l = str.length();
  int v = 0;
  char f = '+';
  for(int i = 0 ; i < l ; ){
    if(is_num(str[i])){
      v = 0;
      while(is_num(str[i]))
      v = v * 10 + str[i++] - '0';

      // cout << v << endl;

      if(i == l){//如果到了末尾
        if(f == '+') x.c += v;
        else if(f == '-') x.c -= v;
        v = 0;
      }


    }else if(str[i] == 'x'){
      if(v == 0) v = 1;//x前面可以神略
      if(i + 2 < l && str[i + 1] == '^'){//可以判定二次钱的系数
        if(f == '+') x.a += v;
        else if(f == '-') x.a -= v;
        v = 0;
        i += 3;
      }
      else{//一次方前面的系数
        if(f == '+') x.b += v;
        else if(f == '-') x.b -= v;
        v = 0;
        i ++;
      }
    }else if(str[i] == '+' || str[i] == '-'){
      if(f == '+') x.c += v;
      else if(f == '-') x.c -= v;
      v = 0;
      f = str[i++];
    }
  }
  return x;
}
int main(){
  while(cin >> str){
    int p = str.find("=");
    string l = str.substr(0,p);
    string r = str.substr(p + 1);
    // cout << "l = " << l << endl;
    // cout << "r = " << r << endl;
    Xi left = get_xi(l);
    Xi right = get_xi(r);
    int a = left.a - right.a;
    int b = left.b - right.b;
    int c = left.c - right.c;
    // cout << "a = " << a << endl;
    // cout << "b = " << b << endl;
    // cout << "c = " << c << endl;
    int d = pow(b,2) - 4 * a * c;
    if(d < 0) cout << "No Solution" << endl;
    else{ // 有解
      double x1 = (-b + sqrt(d)) / 2 * a;
      double x2 = (-b - sqrt(d)) / 2 * a;

      if(x1 > x2) swap(x1 ,x2);
      printf("%.2f %.2f\n",x1,x2);
    }
  }
  return 0;
}
