#include<iostream>
#include<string.h>
using namespace std;
string p,b;
int p_y,p_m,p_d,b_y,b_m,b_d;
int str2int(string date){
  int sum = 0;
  for(int i = 0 ; i < date.length() ; i++){
    sum  = sum * 10 + date[i] - '0';
  }
  return sum;
}
int reach(){
  if(p_y == b_y && p_m == b_m) return 1;
  return 0;
}
int mon[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int is_leap(int y){
  return y % 400 ==0 || y % 4 == 0 && y % 100 != 0;
}

int main(){
  while(cin >> p >> b){
     p_y = str2int(p.substr(0,4));
     p_m = str2int(p.substr(4,2));
     p_d = str2int(p.substr(6,2));
     b_y = str2int(b.substr(0,4));
     b_m = str2int(b.substr(4,2));
     b_d = str2int(b.substr(6,2));
    // cout << p_y << " " << p_m << " " << p_d << endl;
    // cout << b_y << " " << b_m << " " << b_d << endl;
    int dif = 1;
    while(!reach()){
      dif++;
      p_d++;
      //如果是二月份，需要特殊处理
      int lim = p_m == 2 ? mon[p_m]  + is_leap(p_y) : mon[p_m];
      // cout << "lim = " << lim << endl;
      if(p_d > lim){
        p_d -= lim;
        p_m++;
        if(p_m > 12){
          p_m -= 12;
          // cout << "pm" << p_m << endl;
          p_y++;
        }
      }
    }
    cout << dif << endl;
    // cout << is_leap(2012) << endl;
  }




  return 0;
}
