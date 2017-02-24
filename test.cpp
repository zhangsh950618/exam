#include<iostream>
using namespace std;
struct date{
  int y;
  int m;
  int d;
};
bool operator != (date a,date b){
  return a.y != b.y || a.m != b.m || a.d != b.d;
}
bool operator < (date a,date b){
  if(a.y != b.y) return a.y < b.y;
  if(a.m != b.m) return a.m < b.m;
  if(a.d != b.d) return a.d < b.d;
}
bool operator > (date a,date b){
  if(a.y != b.y) return a.y > b.y;
  if(a.m != b.m) return a.m > b.m;
  if(a.d != b.d) return a.d > b.d;
}
int main(){
  date today = (date){2017,2,19};
  date tomorrow = (date){2017,2,18};
  date pre = min(today,tomorrow);
  date back = max(today,tomorrow);
  cout << back.d << endl;
  cout << pre.d << endl;
  int ans = (today != tomorrow);
  ans = (today > tomorrow);
  cout << ans << endl;
  return 0;
}
