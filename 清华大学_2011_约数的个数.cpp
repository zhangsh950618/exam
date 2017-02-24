#include<iostream>
#include<math.h>
using namespace std;
int n;
int solve(int num){
  int sum = 0;
  int lim = sqrt(num);
  for(int i = 1 ; i <= lim ; i++){
    if(num % i == 0){
       sum ++;
       if(num / i != i)
       sum ++;
    }
  }
  return sum;
}
int main(){
  while(cin >> n && n){
    for(int i = 0 ; i < n ; i++){
      int temp;
      cin >> temp;
      cout << solve(temp) << endl;
    }
  }
  return 0;
}
