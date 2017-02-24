#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1000000;
int a[maxn],b[maxn],ans[2*maxn];
int tot,len_a,len_b,a_start,a_end,b_start,b_end;
int t;
int main(){
  cin >> t;
  while(t--){
    tot = 1;
    cin >> len_a >> len_b;
    for(int i = 0 ; i < len_a ; i++){
      cin >> a[i];
    }
    for(int i = 0 ; i < len_b ; i++){
      cin >> b[i];
    }
    cin >> a_start >> a_end;
    cin >> b_start >> b_end;
    for(int i = a_start - 1 ; i <= a_end - 1 ; i++)
    ans[tot++] = a[i];
    for(int i = b_start - 1 ; i <= b_end - 1 ; i++)
    ans[tot++] = b[i];
    // sort(ans,ans+tot);
    cout << ans[tot/2] << endl;
  }
return 0;
}
