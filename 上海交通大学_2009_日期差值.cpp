#include<iostream>
#include<string.h>
using namespace std;
string pre,back;
int str2num(string date){
  int sum = 0;
  for(int i = 0 ; i < date.length() ; i++){
    sum = sum * 10 + date[i] - '0';
  }
  return sum;
}
int is_leap(int year){
  return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}
int m[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
  while(cin >> pre >> back){
    int pre_year = str2num(pre.substr(0,4));
    int pre_mon = str2num(pre.substr(4,2));
    int pre_day = str2num(pre.substr(6,2));
    // cout << pre_year << " " << pre_mon << " " << pre_day << endl;
    int back_year = str2num(back.substr(0,4));
    int back_mon = str2num(back.substr(4,2));
    int back_day = str2num(back.substr(6,2));
    // cout << back_year << " " << back_mon << " " << back_day << endl;
    int dif = 0;
    int year,mon,day;
    // 计算年份差值
    for(year = pre_year ; year < back_year ; year++) dif += 365 + is_leap(year);
    //计算月份差值
    for(mon = pre_mon ; mon < back_mon ; mon++){
      dif += m[mon];
      if(mon == 2) dif += is_leap(year);
    }
    // 计算日期差值
    dif += back_day - pre_day + 1;
    cout << dif << endl;
  }
  return 0;
}
