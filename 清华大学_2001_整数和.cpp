#include<iostream>
using namespace std;
int main(){
  int n;
  while(cin >> n){
    long long sum = 0;
    if(n >= 0) for(int i = n ; i <= 2 * n ; i++) sum += i;
    else for(int i = n ; i >= 2 * n ; i--) sum += i;
    cout << sum << endl;
  }
  return 0;
}
