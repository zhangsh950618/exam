#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 1000;
int ans[maxn];
int main(){
  string str;
  while(cin >> str){
    memset(ans,0,sizeof(ans));
    for(int i = 0 ; i < str.length() ; i++){
      char c = str[i];
      if(c >= 'A' && c <= 'Z'){
        ans[c]++;
      }
    }
    for(char i = 'A' ; i <= 'Z' ; i++){
      cout << i << ":" << ans[i]<< endl;
    }
  }
  return 0;
}
