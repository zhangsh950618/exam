#include<iostream>
#include<string.h>
using namespace std;
string t,p;
int match(int n){
  for(int i=n,j=0; j < p.length() ; i++,j++){
      if(n >= t.length()) return 0;
      if(t[i] != p[j]) return 0;
  }
  return 1;
}
int main(){
  while(cin >> t >>p){
    int sum = 0;
    for(int i = 0 ; i < t.length() ; i++) sum += match(i);
    cout << sum << endl;
  }
  return 0;
}
