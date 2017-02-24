/*
ID: zhangsh35
PROG: friday
LANG: C++
*/
#include<fstream>
#include<string.h>
using namespace std;
ifstream cin("friday.in");
ofstream cout("friday.out");
int mon_lim[] = { 0, 31, 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
int n,dif;
int week[7];
int is_leap(int year){
  return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}
int get_mon_lim(int year,int mon){
  if(mon != 2) return mon_lim[mon];
  else return mon_lim[mon] + is_leap(year);
}
struct date{
  int y;
  int m;
  int d;
};
bool operator == (date d1 , date d2){
  return d1.y == d2.y && d1.m == d2.m && d1.d == d2.d;
}

int main(){
  while(cin >> n){
    memset(week, 0, sizeof(week));
    dif = 0;
    date pre = (date){1900,1,1};
    date back = (date){1900 + n,1,1};
    while( !(pre == back)){ // 如果日期不同
      pre.d++;
      dif++;
      if(pre.d == 13){
        week[(dif % 7 + 2) % 7]++;
      }
      int l = get_mon_lim(pre.y,pre.m);
      if(pre.d > l){
        pre.d -= l;
        pre.m ++;
        if(pre.m > 12){
          pre.m -= 12;
          pre.y++;
        }
      }
    }
    cout << week[0];
    for(int i = 1 ; i < 7 ; i++) cout << " " << week[i];
    cout << endl;
  }
  return 0;
}
