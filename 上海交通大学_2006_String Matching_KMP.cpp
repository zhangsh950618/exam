#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 1000000 + 10;
string t,p;
int next[maxn];
void make_next(string p){
  int len = p.length();
  memset(next,0,sizeof(next));
  for(int i = 1,k = 0 ; i < len ; i++){
    while(k > 0 && p[k] != p[i]) k = next[k -1];
    if(p[k] == p[i]) k++;
    next[i] = k;
  }
}
int main(){
  while(cin >> t >> p){
    make_next(p);
    int len = p.length();
    for(int i = 0,j = 0 ; i < t.length() ; i++){
      while(j > 0 && )
    }






  }

  return 0;
}
