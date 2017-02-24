#include<iostream>
using namespace std;
int n,d,k;
int main(){
  while( cin >> d >> k >> n ){
    int l = d + k;
    int num;
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
      cin >> num;
      if(num <= l) sum ++;
    }
    cout << sum << endl;
  }
  return 0;
}
