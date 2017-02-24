#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
const int maxn = 1000 + 10;
char str[maxn];
int main(){
  string map = "1234567890-=`QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
  while(gets(str)){
    for(int i = 0 ; i < strlen(str) ; i++){
      // cout << str[i] << endl;
      if(str[i] != ' '){
      for(int j = 0 ; j < map.length() ; j++){
          if(str[i] == map[j]){
            str[i] = map[j - 1];
            // cout << "Has break";
            break;
          }
      }
      }
    }
    cout << str << endl;
  }
  return 0;
}
