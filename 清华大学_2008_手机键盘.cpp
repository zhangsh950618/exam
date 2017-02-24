#include<iostream>
#include<string.h>
using namespace std;
string str;
string map[9];
int sum;
int classify(char c){
  for(int i = 0 ; i < 8 ; i++){
    for(int j = 0 ; j < map[i].length() ; j++){
      if(map[i][j] == c){
       sum = sum + j + 1;
       return i;
      }
    }
  }
}
int main(){
  map[0] = "abc";
  map[1] = "def";
  map[2] = "ghi";
  map[3] = "jkl";
  map[4] = "mno";
  map[5] = "pqrs";
  map[6] = "tuv";
  map[7] = "wxyz";
  while(cin >> str){
    sum  = 0;
    int len = str.length();
    int pre = classify(str[0]);
    for(int i = 1 ; i < len ; i++){
      int now = classify(str[i]);
      if(pre == now) sum += 2;
      pre = now;
    }
    cout << sum << endl;
  }
  return 0;
}
