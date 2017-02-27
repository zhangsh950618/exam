#include<iostream>
#include<string.h>
using namespace std;
string st;
const int maxn = 256;
char dict[maxn];
int num[maxn];
int temp[maxn];
int t, l;

void dfs(int step, string ans){
  if(step == l){
    cout << ans << endl;
    return ;
  }
  for(int i = 0 ; i < t ; i++){
    if(num[i]){
      num[i]--;
      dfs(step + 1, ans + dict[i]);
      num[i]++;
    }
  }
  return ;
}
int main(){
  while(cin >> st){
    //初始化
    memset(num, 0, sizeof(num));
    memset(temp, 0, sizeof(temp));
    t = 0;



    l = st.length();
    for(int i = 0 ; i < l ; i++){
      temp[st[i]]++;
    }

    for(int i = 0 ; i < maxn ; i++){
      if(temp[i]){
        dict[t] = i;
        num[t] = temp[i];
        t++;
      }
    }
    // for(int i = 0 ; i < t ; i++){
    //   cout << dict[i] << " " << num[i] << endl;
    // }


    dfs(0, "");

    cout << endl;
  }
  return 0;
}
