#include<iostream>
#include<string.h>
using namespace std;
int main(){
  string str = "0123456789";
  cout << str.find('3') << endl;
  cout << str.substr(3) << endl;
  return 0;
}
