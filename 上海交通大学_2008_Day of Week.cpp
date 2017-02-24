#include<iostream>
using namespace std;
string mon_dict[] = {"","January", "February", "March", "April", "May",
"June", "July", "August", "September", "October", "November", "December"};
int mon_lim[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
string week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int is_leap(int year){
  return year % 400 == 0 ||year % 4 == 0 && year % 100 != 0;
}
int mon2int(string mon){
  for(int i = 1 ; i < 13 ; i++){
    if(mon_dict[i] == mon) return i;
  }
  return 0;
}
int mlim(int year,int mon){
  if(mon != 2) return mon_lim[mon];
  return mon_lim[mon] + is_leap(year);
}
struct date{
  int y;
  int m;
  int d;
};
int year,day;
string mon;
date pre,back;

bool operator != (date a,date b){
  return a.y != b.y || a.m != b.m || a.d != b.d;
}
bool operator < (date a,date b){
  if(a.y != b.y) return a.y < b.y;
  if(a.m != b.m) return a.m < b.m;
  if(a.d != b.d) return a.d < b.d;
}
int dif;
int main(){
  while(cin >> day >> mon >> year){
    dif = 0;
    date des = (date){year,mon2int(mon),day};
    date today = (date){2017,2,18};
    pre = min(des,today);
    back = max(des,today);
    // cout << " from " << pre.y << " " << pre.m << " " << pre.d;
    // cout << " to " << back.y << " " << back.m << " " << back.d << endl;
    while(pre != back){
      dif++;
      pre.d++;
      int l = mlim(pre.y,pre.m);
      if(pre.d > l){
        pre.d -= l;
        pre.m++;
        if(pre.m > 12){
          pre.m -= 12;
          pre.y++;
        }
      }
    }
    // cout << dif << endl;
    dif %= 7;
    if(des < today)
    cout << week[(6-dif+7)%7] << endl;
    else
    cout << week[(6+dif)%7] << endl;
  }
  return 0;
}
