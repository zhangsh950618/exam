#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 1000 + 10;
int a[maxn],b[maxn],ans[maxn];
string str_a,str_b;
int main(){
  while(cin >> str_a >> str_b){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(ans,0,sizeof(ans));
    int len_a = str_a.length();
    int len_b = str_b.length();
    for(int i = 0 ; i < len_a ; i++){
        a[i] = str_a[len_a -1 - i] - '0';
    }
    for(int i = 0 ; i < len_b ; i++){
      b[i] = str_b[len_b - 1 - i] - '0';
    }
    int len = max(len_a,len_b);
    int f = 0;//标志进位
    for(int i = 0 ; i <= len ; i++){
      int sum = a[i] + b[i] + f;
      ans[i] = sum % 10;
      f = sum / 10;
    }
    if(ans[len])
    cout << ans[len];
    for(int i = len - 1 ; i >= 0 ; i--){
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}
