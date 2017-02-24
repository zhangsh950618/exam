#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int maxn = 10;
bool mark[maxn];
int map[maxn][maxn];
int main(){
  int t;
  cin >> t;
  while(t --){

    //输入
    for(int i = 1 ; i <= 9 ; i++)
    for(int j = 1 ; j <= 9 ; j++)
    scanf("%d", &map[i][j]);



    bool flag = true;

    for(int i = 1 ; i <= 9 ; i++){
      memset(mark,false,sizeof(mark));
      for(int j = 1 ; j <= 9 ; j++)
      if(!mark[map[i][j]]) mark[map[i][j]] = true;
      else{
        flag = false;
        // cout << "row: " << i << endl;
      }
    }

    for(int i = 1 ; i <= 9 ; i++){
      memset(mark,false,sizeof(mark));
      for(int j = 1 ; j <= 9 ; j++)
      if(!mark[map[j][i]]) mark[map[j][i]] = true;
      else {
        flag = false;
        // cout << "col: " << i << endl;
      }
    }

    for(int i = 0 ; i < 3 ; i++)
    for(int j = 0 ; j < 3 ; j++){
      memset(mark,false,sizeof(mark));
      for(int k = i * 3 + 1 ; k < i * 3 + 4 ; k++)
      for(int l = j * 3 + 1; l < j * 3 + 4 ; l++){
        // cout << "k = " << k << "l = " << l << " ";
        // cout << map[k][l] << endl;
      if(!mark[map[k][l]]) mark[map[k][l]] = true;
      else{
        flag = false;

      }
      }
    }

    if(flag) cout << "Right" << endl;
    else cout << "Wrong" << endl;

  }
  return 0;
}
