#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
  string a = "123";
  for(int i = 0 ; i < a.length() ; i++)
  cout << a[i] << endl;
  a += "456";
  cout << a << endl;
  reverse(a.begin(), a.end());
  cout << a << endl;
  return 0;
}
