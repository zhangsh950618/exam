#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 1000;
int prime[maxn];
int cnt[maxn];
int form[maxn];
int tot_form;
int tot_prime;
int ans[maxn];
int is_prime(){
  int i,j;
  for(i = 2 ; i <= maxn ; i++){
    int flag = 1;
    for(j = 2 ; j < i ; j++){
      if(i % j == 0){
        flag = 0;
        break;
      }
    }
    if(flag != 0){
      prime[tot_prime++] = i;
    }
  }
}
int main() {
  int n,a;
  is_prime();
  while(cin >> n >> a){
    int i,j;
    memset(cnt,0,sizeof(cnt));
    memset(form,0,sizeof(form));
    memset(ans,0,sizeof(ans));
    tot_form = 0;
    // for(i = 0 ; i < tot_prime ; i++){
    //   cout << prime[i] << endl;
    // }
    for(i = 0 ; i < tot_prime && a != 1; i++){
      int flag = 0;
      if(a % prime[i] == 0){
        form[tot_form] = prime[i];
        flag = 1;
      }
      while (a % prime[i] == 0) {
        a /= prime[i];
        cnt[tot_form]++;
      }
      if(flag)
        tot_form++;
    }
    // for(i = 0 ; i < tot_form ; i++){
    //   cout << form[i] << "," << cnt[i] << endl;
    // }
    for(i = 2 ; i <= n ; i++){
      for(j = 0 ; j < tot_form ; j++){
        int temp = i;
        while(temp % form[j] == 0){
          temp /= form[j];
          ans[j]++;
        }
      }
    }
    // for(i = 0 ;  i < tot_form ; i++){
    //   cout << form[i] << "^" << ans[i] << endl;
    // }
    int min = maxn;
    for(i = 0; i < tot_form ; i++){
      if(ans[i]/cnt[i] < min){
        min = ans[i]/cnt[i];
      }
    }
    cout << min << endl;

  }
  return 0;
}
