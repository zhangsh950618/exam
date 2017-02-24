#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 500 + 10;
string map[maxn][maxn];
string str[maxn];
int t;
int main(){
    while(cin >> t && t){
      for(int i = 0 ; i < maxn ; i++)
      for(int j = 0 ; j < maxn ; j++)
      map[i][j] = " ";
      int row = 0;
      for(int i = 0 ; i < t ; i++){
        cin >> str[i];
        int col = 0;
        int str_len = str[i].length();
        int start = 0;
        int len = 0;
        for(int j = 0 ; j < str_len ; j++){
          // cout << str[i][j] << "," << row << "," << col << endl;
          if(str[i][j] != '\\') len++;
          if(j == str_len - 1 || str[i][j] == '\\'){
            // cout << "jingru" << str[i][j] << endl;
            if(len != 0 && start < str_len){
              string sub = str[i].substr(start,len);
              start = j+1;
              len = 0;
              int flag = 0;
              for(int k = 0 ; k < row ; k++){
                if(map[k][col] == sub){
                  flag = 1;
                  break;
                }
              }
              if(!flag){
                map[row++][col] = sub;
              }
              col++;
            }
            else
            break;
          }

        }

      }
      for(int i = 0 ; i < row ; i++){
        for(int j = 0 ; ; j++){
          cout << map[i][j];
          if(map[i][j]!= " ")break;
        }
        cout << endl;
      }
      cout << endl;

    }
    return 0;
}
