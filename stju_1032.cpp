#include<iostream>
using namespace std;
int A(int m, int n){
  if(m == 0) return n + 1;
  if(m != 0 && n == 0) return A(m - 1, 1);
  A(m - 1, A(m, n - 1));
}
int main(){
  int m ,n ;
  while(cin >> m >> n){
    cout << A(m , n) << endl;
  }
  return 0;
}
