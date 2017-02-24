#include<iostream>
using namespace std;
const int maxn = 100;
int t;
int index[maxn];
void qsort(int l,int h){
  if(l < h){
  int i = l;
  int j = h;
  int d = index[i];
  while(i < j){
    while(index[j] >= d && i < j) j--;
    index[i] = index[j];
    while(index[i] <= d && i < j) i++;
    index[j] = index[i];
  }
  index[i] = d;
  qsort(l,i-1);
  qsort(i+1,h);
  }
}
void merge_sort(int l,int h){
  if(l < h){
    int mid = (l + h) / 2;
    merge_sort(l,mid);
    merge_sort(mid + 1,h);
    int temp[maxn];
    int t = 0;
    int i , j;
    for(i = l,j = mid + 1 ; i <= mid  && j <= h ; )
    if(index[i] < index[j]) temp[t++] = index[i++];
    else temp[t++] = index[j++];
    while(i <= mid) temp[t++] = index[i++];
    while(j <= h) temp[t++] = index[j++];
    for(i = 0 ; i < t ; i++) index[l + i] = temp[i];
    }
}
void bubble(){
  for(int i = 0 ; i < t ; i++){
    for(int j = 0 ; j < t - i - 1 ; j++){
      if(index[j] > index[j + 1]){
        int temp = index[j];
        index[j] = index[j + 1];
        index[j + 1] = temp;
      }
    }
  }
}
int main(){
  while(cin >> t){
    for(int i = 0 ; i < t ; i++) cin >> index[i];
    // qsort(0,t-1);
    // merge_sort(0,t-1);
    bubble();
    for(int i = 0 ; i < t ; i++) cout << index[i] << " ";
    cout << endl;
  }
  return 0;
}
