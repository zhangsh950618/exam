#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 1000 + 10;
int map[maxn][maxn];
int main(){
  int h;
  while(cin >> h){
    memset(map,0,sizeof(map));
    int len = h + (h - 1) * 2;
    for(int i = 1 ; i <= h ; i++){
      for(int j = len ; j > len - h - (i - 1) * 2; j--){
        map[i][j] = 1;
      }
    }
    for(int i = 1 ; i <= h ; i++){
      for(int j = 1; j <= len ; j++)
      if(map[i][j]) cout <<"*";
      else cout << " ";
      cout << endl;
    }

  }
  return 0;

}
