#include<iostream>
using namespace std;
const int maxn = 10;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int main(){
  for(int i = 0 ; i < maxn ; i++)
  for(int j = 0 ; j < maxn ; j++){
    a[i][j] = i * j;
  }
  int (*p)[maxn];
  p = a;
  for(int i = 0 ; i < maxn ; i++){
  for(int j = 0;  j < maxn ; j++)
  cout << p[i][j] << " ";
  cout << endl;
  }
  return 0;





}
