#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 80 + 10;
int map[maxn][maxn];
string str;
int main(){
  while(cin >> str){
    memset(map,0,sizeof(map));
    int len = str.length();
    len += 2;
    int n1,n2,n3;// n2 >= n1 = n3;
    for(n1 = n3 = len ; ; n1--,n3--){
      n2 = len - n1 - n3;
      if(n2 >= n1) break;
    }
    // cout << n1 <<"," << n2 << "," << n3 << endl;
    int i = 0, j = 0 , k = 0;
    while(i < n1) map[i++][j] = str[k++];
    i--;j++;//转向右侧
    while(j < n2) map[i][j++] = str[k++];
    j--;i--;
    while(i >= 0) map[i--][j] = str[k++];
    for(int i = 0 ; i < n1 ; i++){
      for(int j = 0 ; j < n2 ; j++){
        if(map[i][j]) cout << (char)map[i][j];
        else cout << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
