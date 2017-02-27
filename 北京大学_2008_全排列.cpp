#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int maxn = 256;
bool mark[maxn];
char p[maxn];
int t, l;
string st;
void dfs(int step, string ans){
  if(step == l){
    const char * p = ans.c_str();
    // cout << ans << endl;
    printf("%s\n",p);
  }
  for(int i = 0 ;i < t ; i++){
    //如果可以使用
    if(mark[p[i]]){
      mark[p[i]] = false;
      dfs(step + 1, ans + p[i]);
      mark[p[i]] = true;
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  while(cin >> st){
    memset(mark, false, sizeof(mark));
    memset(p , false, sizeof(p));
    t = 0 ;
    l = st.length();
    for(int i = 0 ; i < l;i++) mark[st[i]] = true;
    for(int i = 0 ; i < maxn ; i++)
      if(mark[i])
      p[t++] = i;
    dfs(0,"");
    cout << endl;
  }
  return 0;
}

/**************************************************************
    Problem: 1120
    User: zhangsh950618
    Language: C++
    Result: Time Limit Exceed
****************************************************************/
