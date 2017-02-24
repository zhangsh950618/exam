#include<iostream>
using namespace std;
const int maxn = 1000 + 10;
int t;
int index[maxn];
int merge_sort(int l ,int h){
  int sum = 0;
  if(l < h){
    int mid = (l + h) / 2;
    sum += merge_sort(l , mid);
    sum += merge_sort(mid + 1 , h);
    int i = l;
    int j = mid + 1;
    int temp[maxn];
    int t = 0;
    for( ; i <= mid && j <= h; ){
      if(index[i] <= index[j]) temp[t++] = index[i++];
      if(index[j] < index[i]){
        temp[t++] = index[j++];
        sum += mid + 1 - i;
      }
    }
    while(i <= mid) temp[t++] = index[i++];
    while(j <= h){
       sum += mid + 1 - i;
       temp[t++] = index[j++];
      }
    for(i = 0 ; i < t ; ) index[l + i] = temp[i++];
  }
  return sum;
}
int main(){
  cin >> t;
  for(int k = 1 ; k <= t ; k++){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> index[i];
    cout << "Scenario #" << k << ":" << endl;
    cout << merge_sort(0 , n - 1) << endl;
    cout << endl;
    // for(int i = 0 ; i < n ; i++) cout << index[i] << " ";
    // cout << endl;
  }
  return 0;
}
