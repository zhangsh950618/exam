#include<iostream>
#include<string.h>
#include<string>
using namespace std;
string w_d[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int y, m, d;
struct date{
  int y;
  int m;
  int d;
};pre,back;
int str2int(string num){
  int n = 0;
  for(int i = 0 ; i < num ; i++)
    n = n * 10 + num[i] - '0';
  return n;
}
date get_date(string d_s){
  int y = str2int(d_s.substr(0, 4));
  int m = str2int(d_s.substr(5, 2));
  int d = str2int(d_s.substr(8, 2));
  return (date){y, m, d};
}
int main(){
  while(cin >> y >> m >> d){
    if(m < 3){
      m += 12;
      y --;
    }
    int w =  (y + y / 4 + y / 400 - y / 100 + 2 * m + 3 * (m + 1) / 5 + d) % 7;
    cout << w_d[w] << endl;
  }
  return 0 ;
}
