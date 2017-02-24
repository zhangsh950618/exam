#include<iostream>
#include<string.h>
using namespace std;
string str;
int main(){
  while(cin >> str){
    int len = str.length();
    for(int i = 0 ; i < len ; i++)
    for(int j = 0 ; j < len - i - 1 ; j++){
      if(str[j] > str[j+1]){
        char c = str[j];
        str[j] = str[j+1];
        str[j+1] = c;
      }
    }
    cout << str << endl;
  }
  return 0;
}
