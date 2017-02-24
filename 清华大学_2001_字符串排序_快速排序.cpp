#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
string str;
void qsort(int low,int high){
  char index = str[low];
  int i = low + 1;
  int j = high;
  while(i < j){
    while(j-- && str[j] > index)
  }

}

int main(){
  while(cin >> str){
    int len = str.length();
    qsort(0,len -1);
    cout << str << endl;
  }
  return 0;
}
