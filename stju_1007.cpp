#include<iostream>
#include<string.h>
using namespace std;
string s1, s2;
int main(){
  while(cin >> s1 >> s2){
  s1.erase(s1.find('.'),1);
  s2.erase(s2.find('.'),1);
  // cout << s1 << endl;

  if(s1.length() < s2.length()) swap(s1 ,s2);
  int s = 0;
  int l1 = s1.length();
  int l2 = s2.length();
  for(int i = l1 -1 , j = l2 - 1 ; i >= 0 ; i--, j--){
    s += s1[i] - '0';
    if(j >= 0)
    s += s2[j] - '0';
    s1[i] = s % 10 + '0';
    s /= 10;
  }
  if(s) s1 = "1" + s1;
  s1.insert(s1.end() - 2, '.');
  cout << s1 << endl;
  }
  return 0;
}
