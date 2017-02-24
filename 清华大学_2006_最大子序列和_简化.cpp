#include<iostream>
using namespace std;
long long n;
int main(){
  while(cin >> n){
    long long sum;
    cin >> sum;
    long long maxn = sum;
    for(long long i = 1 ; i < n ; i++){
      long long temp;
      cin >> temp;
      if(sum >= 0) sum += temp;
      else sum = temp;
      if(sum > maxn) maxn = sum;
    }
    cout << maxn << endl;
  }
  return 0;

}
