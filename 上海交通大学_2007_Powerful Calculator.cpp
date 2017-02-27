#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 1000;
int la, lb;
bool has_swap;
void add (string a, string b){
  int s = 0;
  for(int i = la -1,j = lb - 1  ; i >= 0 ; i--, j--){
    s += a[i] - '0';
    if(j >= 0) s+= b[j] - '0';
    a[i] = s % 10 + '0';
    s /= 10;
  }
  if(s) cout << s;
  cout << a << endl;
}
void sub(string a, string b){
  if(has_swap) cout << "-";
  for(int i = la -1 ,j = lb - 1 ; i >= 0 ; i--, j--){
    int s = a[i] - '0';
    if(j >= 0) s -= b[j] - '0';
    if(s < 0){
      a[i - 1]--;
      s += 10;
    }
    a[i] = s % 10 + '0';
  }
  int i = 0;
  while(a[i] == '0' && i < la - 1) i ++;
  a = a.substr(i);
  cout << a << endl;
}
void mul(string a, string b){
  int temp[maxn] = {0};
  for(int i = lb - 1 ; i >= 0 ; i--){
    for(int j = la - 1 , k = i + j + 1 ; j >= 0 ; j--, k--){
      int s = (b[i] - '0') * (a[j] - '0') + temp[k];
      temp[k] = s % 10;
      temp[k - 1] += s / 10;
  }
  }
  int i = 0;
  while(temp[i] == 0 && i < la + lb -1) i++;
  string ans = "";
  while(i < la + lb ){
    ans += temp[i++] + '0';
  }
  cout << ans << endl;
}
int main(){
  string a, b;
  while(cin >> a>> b){
    has_swap = false;
    if(a.length() < b.length() || (a.length() == b.length() && a < b)){
        swap(a , b);
        has_swap = true;
    }
    la = a.length();
    lb = b.length();
    add(a, b);
    sub(a, b);
    mul(a, b);
  }
  return 0;
}
