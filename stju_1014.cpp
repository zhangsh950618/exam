#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
string a,b;
string add(string s1, string s2){
  if(s1.length() < s2.length()) swap(s1,s2);
  int l1 = s1.length();
  int l2 = s2.length();
  int s = 0;
  for(int i = l1 - 1, j = l2 - 1; i >= 0 ; i-- , j--){
    s += s1[i] - '0';
    if(j >= 0)
    s += s2[j] - '0';
    s1[i] = s % 10 + '0';
    s /= 10;
  }
  if(s) s1 = "1" + s1;
  return s1;
}
int main(){
  while(cin >> a >> b){
    cout << add(a,b) << endl;
  }







  return 0;
}
