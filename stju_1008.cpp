#include<iostream>
using namespace std;
int m_d[] =  {0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
int is_leap(int year){
  return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}
//计算每个月的极限
int get_lim(int year,int mon){
  if(mon != 2) return m_d[mon];
  else return m_d[2] + is_leap(year);
}
struct date{
  int y;
  int m;
  int d;
};
int str2int(string num){
  int n = 0;
  for(int i = 0 ; i < num.length() ; i++)
    n = n * 10 + num[i] - '0';
  return n;
}
date get_date(string d_s){
  int y = str2int(d_s.substr(0, 4));
  int m = str2int(d_s.substr(5, 2));
  int d = str2int(d_s.substr(8, 2));
  return (date){y, m, d};
}
bool operator != (date a,date b){
  return a.y != b.y || a.m != b.m || a.d != b.d;
}
int is_weekend(int y,int m,int d){
  if(m < 3){
    m += 12;
    y --;
  }
  int w = (y + y / 4 + y / 400 - y / 100 + 2 * m + 3 * (m + 1) / 5 + d) % 7;
  //周末
  if(w >= 5) return 1;
  return 0;

}
//判断一个日期是否是交易日
int valid(date tim){
  int y = tim.y;
  int m = tim.m;
  int d = tim.d;
  //元旦；
  if(m == 1 && d == 1) return 0;
  if(m == 5 && d >= 1 && d <= 3) return 0;
  if(m == 10 && d >= 1 && d <= 7) return 0;
  if(is_weekend(y, m, d)) return 0;
  return 1;
}
date pre,back;
int main(){
  string sdp,sdb;
  int t;
  while(cin >> t){
    for(int i = 0 ; i < t ; i++){
    cin >> sdp >> sdb;
    pre = get_date(sdp);
    back = get_date(sdb);
    int sum = 0;
    while(pre != back){
      sum += valid(pre);
      pre.d++;
      int lim = get_lim(pre.y,pre.m);
      if(pre.d > lim){
        pre.d -= lim;
        pre.m ++;
        if(pre.m > 12){
          pre.m -= 12;
          pre.y ++;
        }
      }
    }
    sum += valid(back);
    cout << sum << endl;
    }
  }
  return 0;
}
