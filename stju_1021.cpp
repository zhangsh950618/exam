#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
const int maxn = 150 + 10;
int map[maxn][maxn];
int main(){
  int n;
  while(cin >> n){
    memset(map,0,sizeof(map));
    int k = 1;
    int i = 0 , j = 0;
    while(k <= n * n){
      //右侧
      while(k <= n * n){
        map[i][j] = k++;
        if(j + 1 < n && !map[i][j + 1]) j++;
        else break;
      }
      if(i + 1 < n && !map[i + 1][j]) i++;
      //下
      while(k <= n * n){
        map[i][j] = k++;
        if(i + 1 < n && !map[i + 1][j]) i++;
        else break;
      }
      if(j - 1 >= 0 && !map[i][j - 1]) j--;
      //左侧
      while(k <= n * n){
        map[i][j] = k++;
        if(j - 1 >= 0 && !map[i][j - 1]) j--;
        else break;
      }
      if(i - 1 >= 0 && !map[i - 1][j]) i--;
      //上
      while(k <= n * n){
        map[i][j] = k++;
        if(i - 1 >= 0 && !map[i - 1][j]) i--;
        else break;
      }
      if(j + 1 < n && !map[i][j + 1]) j++;
    }


    for(int i = 0 ; i < n; i++){
      for(int j = 0 ; j < n; j++)
      cout << setw(6) << map[i][j];
      cout << endl;
    }
  }
  return 0;
}
