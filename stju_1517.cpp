#include<iostream>
using namespace std;
string a,b;
string sub(string a, string b){
  if(a.length() < b.length() ||(a.length() == b.length() && a < b)){
    cout << "-";
    swap(a, b);
  }

  int la = a.length();
  int lb = b.length();


  for(int i = la - 1 , j = lb - 1; i >= 0 ; i--, j--){
    int s = 0;
    s += a[i] - '0';
    if(j >= 0)
    s -= b[j] - '0';
    if(s < 0){
      s += 10;
      a[i-1]--;
    }
    a[i] = s + '0';
  }
  int i = 0;
  while(a[i] == '0' && i < la - 1) i++;
  // cout << i << endl;
  a = a.substr(i);
  return a ;
}
int main(){
  while(cin >> a >> b)
  cout << sub(a, b) << endl;
  return 0;
}
