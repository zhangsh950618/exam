#include<iostream>
using namespace std;
const int maxn = 1000 + 10;
int t;
int index[maxn];
// int merge_sort(int l,int h){
//   int sum = 0;
//   if(l < h){
//     int mid = (l + h) / 2;
//     sum += merge_sort(l , mid);
//     sum += merge_sort(mid + 1 , h);
//     int temp[maxn];
//     int i = l;
//     int j = mid + 1;
//     int t = 0;
//     for( ; i <= mid && j <= h ; ){
//       if(index[i] <= index[j]) temp[t++] = index[i++];
//       else{
//         temp[t++] = index[j++];
//         sum += mid + 1 - i;
//       }
//
//     }
//     while(i <= mid) temp[t++] = index[i++];
//     while(j <= h){
//       temp[t++] = index[j++];
//       sum += mid + 1 - i;
//     }
//   }
//   return sum;
//
// }
int main(){
  while(cin >> t){
    for(int i = 0 ; i < t ; i++) cin >> index[i];
    // cout << merge_sort(0,t - 1) << endl;
  }
  return 0;
}
