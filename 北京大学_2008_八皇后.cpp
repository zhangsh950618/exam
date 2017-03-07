#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 10;
bool mark[maxn],col[maxn],even[2 * maxn],odd[2 * maxn];
int sum,k;
int ans[maxn];
void queue(int row){
  if(row == 9){
    sum ++;
    if(sum == k){
      for(int i = 1 ; i < row ; i++)
        cout << ans[i];
        cout << endl;
      }
    return ;
  }
      for(int j = 1 ; j <= 8 ; j++){//循环列
        if(!col[j] && !odd[row - j + 8] && !even[row + j]){
            col[j] = 1;
            odd[row - j + 8] = 1;
            even[row + j] = 1;
//            char c = '0' + j;
            ans[row] = j;
            queue(row + 1);
            col[j] = 0;
            odd[row - j + 8] = 0;
            even[row + j] = 0;
        }
  }
}

int main(){
  memset(col,false,sizeof(col));
  memset(even,false,sizeof(even));
  memset(odd,false,sizeof(odd));
  int t;
  cin >> t;
  while(t--){
    cin >> k;
    sum = 0;
    queue(1);
  }

  return 0;
}
