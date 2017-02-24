#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
string a, b;
const int maxn = 1000 + 10;
string mul(string a, string b){
  int la = a.length();
  int lb = b.length();
  int num[2 * maxn] = {0};
  for(int i = lb - 1 ; i >= 0 ; i--)
  for(int j = la - 1, k = i + j +1 ; j >= 0 ; j--, k--){
    int sum = (b[i] - '0') * (a[j] - '0') + num[k];
    num[k] = sum % 10;
    num[k - 1] += sum / 10;
  }
  int i = 0;
  while(num[i] == 0 && i < la + lb - 1) i++;
  string ans = "";
  while(i < la + lb){
    ans += num[i++] + '0';
  }
  return ans;
}
int main(){
  while(cin >> a >> b){
    cout << mul(a, b) << endl;
  }
  return 0;
}
