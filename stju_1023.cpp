#include<iostream>
using namespace std;
const int maxn = 600 + 10;
int T;
int map[maxn][maxn];
int main(){
  cin >> T;
  while(T--){
    int n, op;
    cin >> n >> op;

    for(int i = 0 ; i < n ; i++)
    for(int j = 0 ; j < n ; j++)
    cin >> map[i][j];

    switch(op){
        //水平翻转
        case 0:{
          for(int i = 0 ; i < n ; i++)
            for(int j = 0 ;j < n / 2 ; j++)
              swap(map[i][j], map[i][n - 1 - j]);
          break;
        }
        //竖直翻转
        case 1:{
          for(int j = 0 ; j < n ; j++)
            for(int i = 0 ;i < n / 2 ; i++)
              swap(map[i][j], map[n - 1 - i][j]);
          break;
        }
        //对角线翻转
        case 2:{
          for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < i ; j++)
              swap(map[i][j],map[j][i]);
          break;
        }
    }


    int i , j;
    for(i = 0 ; i < n ; i++){
      for(j = 0 ; j < n- 1 ; j++)
      cout << map[i][j] << " ";
      cout << map[i][j] << endl;
    }




  }
  return 0;
}
