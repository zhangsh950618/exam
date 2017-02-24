#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 1000 + 10;
int tot_s,tot_q;
struct S{
  string s_number;
  string s_name;
  string s_sex;
  string s_age;
};
S s[maxn];
int main(){
  string number,name,sex,age;
  while(cin >> tot_s){
    for(int i = 0 ; i < tot_s ; i++) cin >> s[i].s_number >> s[i].s_name >> s[i].s_sex >> s[i].s_age;

    cin >> tot_q;
    for(int i = 0 ; i < tot_q ; i++){
      string q_number;
      cin >> q_number;
      for(int j = 0 ; j < tot_s ; j++){
        if(s[j].s_number == q_number){
          cout << s[j].s_number << " " << s[j].s_name << " " << s[j].s_sex << " " << s[j].s_age << endl;
          break;
        }
      }
    }
  }
  return 0;
}
