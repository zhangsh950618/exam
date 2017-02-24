#include<iostream>
#include<string.h>
using namespace std;
string t,p;
const int maxn = 256;
int next[maxn];
int sunday(string t,string p){
  int sum = 0;
  int lt = t.length();
  int lp = p.length();
  for(int i = 0 ; i < maxn ; i++)
    next[i] = lp + 1;
  for(int i = 0 ; i < lp ; i++){
    next[p[i]] = lp - i;
  }

  int s = 0;
  while(s <= (lt - lp)){
    int i = s;
    int j = 0;
    for(  ; j < lp ; i++,j++){
      if(t[i] != p[j]){
        s += next[t[s + lp]];
        break;
      }
    }
    if(j == lp){
      sum++;
      s++;
    }
  }
  return sum;

}
int main(){
  while(cin >> t >> p){
    cout << sunday(t,p) << endl;
  }
  return 0;
}
