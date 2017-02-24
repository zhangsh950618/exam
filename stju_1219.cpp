#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 200000 + 10;
int num[maxn], n;
int merge_sort(int l, int h){
  int sum = 0;
  if(l < h){

    int mid = (l + h) / 2;
    sum += merge_sort(l , mid);
    sum += merge_sort(mid + 1, h);
    int i = l;
    int j = mid + 1;
    int k = 0;
    int temp[maxn] = {0};
    while(i <= mid && j <= h){
      if(num[i] <= num[j]) temp[k++] = num[i++];
      else {
        temp[k++] = num[j++];
        sum += mid + 1 - i;
      }
    }
    while(i <= mid) temp[k++] = num[i++];
    while(j <= h){
      temp[k++] = num[j++];
      sum += mid + 1 - i;
    }
    for(int i = 0 ; i < k ; ) num[l + i] = temp[i++];
  }
  return sum;
}
int main(){
  while(cin >> n){
    memset(num, 0, sizeof(num));
    for(int i = 0 ; i < n ; i++) cin >> num[i];
    cout << merge_sort(0, n-1) << endl;
  }

  return 0;
}
