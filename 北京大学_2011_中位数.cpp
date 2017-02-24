#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn = 10000 +10;
int num[maxn];
int n;
int main(){
  while(cin >> n && n){
    for(int i = 0 ; i < n ; i++) cin >> num[i];
    sort(num,num + n);
    if(n % 2) cout << num[n/2] << endl;
    else cout << (num[n/2-1]+num[n/2])/2 << endl;
  }
  return 0;
}
