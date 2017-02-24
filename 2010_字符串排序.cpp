#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 1000;
string str[maxn];
int tot_str = 0;
int len = 0;
int main(){
  string s;
  while(cin >> s){
    tot_str = 0;
    len = s.length();
    for(int i = 0 ; i < len ; i++){
      str[tot_str++] = s.substr(i,len-i);
    }
    sort(str,str+tot_str);
    for(int i = 0 ; i < tot_str ; i++){
      cout << str[i] << endl;
    }
  }
  return 0;
}
