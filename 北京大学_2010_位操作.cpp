#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 100;
int t,a,b;
int num_a[maxn],num_b[maxn];
int tot_a,tot_b;
string solve(int a,int b){
  memset(num_a,0,sizeof(num_a));
  memset(num_b,0,sizeof(num_b));
  tot_a = 0;
  tot_b = 0;
  while(a){
    num_a[tot_a++] = a % 2;
    a /= 2;
  }
  while(b){
    num_b[tot_b++] = b % 2;
    b /= 2;
  }
  int len = max(tot_a,tot_b);
  for(int i = 0 ; i < len ; i++){
    int flag = 1;
    for(int j = 0 ; j < len ; j++){
      if(num_b[j] != num_a[(i+j)%len]) flag = 0;
    }
    if(flag) return "YES";
  }
  return "NO";

}
int main(){
  while(cin >> t){
    for(int i = 0 ; i < t ; i++){
      cin >> a >> b;
      cout << solve(a,b) << endl;
    }
  }

  return 0;

}
