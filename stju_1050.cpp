#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int maxn = 30000 + 10;
int num[maxn * 2], s[maxn * 2];
int n, m;
int main(){
  while( cin >> n >> m){

    memset(num, 0, sizeof(num));
    memset(s, -1, sizeof(s));

    for(int i = 0 ; i < n ; i++){
      scanf("%d", &num[i]);
      s[i] = i;//每个组都是自己的主人
    }
    //操作
    int op, a ,b;
    for(int i = 0 ; i < m ; i++){
      cin >> op;
      switch(op){
        case 0:{
          //将b合并进入a
          scanf("%d%d",&a,&b);
          for(int j = 0 ; j < n ; j++)
          if(s[j] == b) s[j] = a;
          break;

        }
        case 1:{
          cin >> a;
          int pos = -1;
          int m = maxn;
          for(int j = 0 ; j < n ; j++){
            if(s[j] == a && num[j] < m){
              m = num[j];
              pos = j;
            }
          }
          //没有找到
          if(pos == -1) cout << -1 << endl;
          else{
            s[pos] = -1;
            cout << num[pos] << endl;
          }
          break;

        }
        case 2:{
          scanf("%d%d",&a,&b);
          num[n] = b;
          s[n++] = a;
          break;
        }
      }
    }

  }
  return 0;
}
