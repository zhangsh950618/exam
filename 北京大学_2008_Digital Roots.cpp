#include<iostream>
#include<string.h>
using namespace std;
string str;
int main(){
  while(cin >> str && str != "0"){
    int sum = 0;
    for(int i = 0 ;i < str.length() ; i++) sum += str[i] - '0';
    cout << sum % 9 << endl;
  }
  return 0;
}
