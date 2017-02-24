#include<iostream>
#include<string.h>
using namespace std;
const int maxn = 1000;
int a[maxn];
char f;
int temp;
int main(){
  while(cin >> temp){
    int t = 0;
    memset(a,0,sizeof(a));
    a[t] = temp;
    while((f = cin.get()) && (f != '\n')){
      cout << "f = " << f << endl;
      cin >> temp;

      if(f == '+') a[++t] = temp;
      else if(f == '-') a[++t] = -temp;
      else if(f == '*') a[t] *= temp;
      else if(f == '/') a[t] /= temp;
    }
    int s = 0;
    cout << "t = " << t << endl;
    for(int i = 0 ; i <= t ; i++){
       s += a[i];
       cout << "a[i]: " << a[i] << endl;
    }
    cout << s << endl;
  }
  return 0;

}
