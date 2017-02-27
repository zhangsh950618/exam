#include<iostream>
using namespace std;
const int maxn = 10;
struct Mat{
  int r;
  int c;
  int d[maxn][maxn];
};
Mat mul(Mat a, Mat b){
  Mat c;
  if(a.c == b.r){
    c.r = a.r;
    c.c = b.c;
    for(int i = 0 ; i < a.r ; i++)
    for(int j = 0 ; j < b.c ; j++){
      int v = 0;
      for(int k = 0 ; k < a.c ; k++)
      v += a.d[i][k] * b.d[k][j];
      c.d[i][j] = v;
    }
  }
  return c;
}
int main(){

  Mat a, b;

  a.r = 2;
  a.c = 3;

  b.r = 3;
  b.c = 2;
  while(cin >> a.d[0][0]){


  cin >> a.d[0][1] >> a.d[0][2];

  for(int i = 1 ; i < a.r ; i++)
  for(int j = 0 ; j < a.c ; j++)
  cin >> a.d[i][j];




  for(int i = 0 ; i < b.r ; i++)
  for(int j = 0 ; j < b.c ; j++)
  cin >> b.d[i][j];


  Mat c = mul(a, b);
  int i = 0, j = 0;
  for(i = 0 ; i < c.r ; i++){
    for(j = 0 ; j < c.c ; j++)
    cout << c.d[i][j] << " ";
    cout << endl;
  }
  }

  return 0;
}
