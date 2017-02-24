#include<iostream>
#include<string.h>
using namespace std;
int len;
string str;
void qsort(int l,int h){
  if(l < h){
    char k = str[l];
    int i = l;
    int j = h;
    while(i < j){
      while(i < j && str[j] >= k) j--;
      str[i] = str[j];
      while(i < j && str[i] <= k) i++;
      str[j] = str[i];
    }
    str[i] = k;
    qsort(l , i - 1);
    qsort(i + 1 , h );
  }
}
int main(){
  while(cin >> str){
    len = str.length();
    // qsort(0,len-1);
    for(int i = 0 ; i < len ; i++){
      for(int j = 0 ; j < len - i - 1 ; j++){
        if(str[j] > str[j + 1]){
          char c = str[j];
          str[j] = str[j + 1];
          str[j + 1] = c;
        }
      }
    }
    cout << str << endl;
  }
  return 0;
}
