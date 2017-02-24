#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn = 10000 + 10;
int n,num[maxn];
int main(){
  while(cin >> n){
    for(int i = 0 ; i < n ; i++) cin >> num[i];
    sort(num, num + n);
    cout << num[0];
    for(int i = 1 ; i < n ; i++){
      cout << " " << num[i];
    }
    cout << endl;
  }
  return 0;
}
