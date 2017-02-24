#include<iostream>
using namespace std;
int n;
int main(){
  while(cin >> n){
    int maxn = -1000000;
    int minn = 1000000;
    for(int i = 0 ;i < n ; i++){
      int temp;
      cin >> temp;
      if(temp > maxn) maxn = temp;
      if(temp < minn) minn = temp;
    }
    cout << maxn << " " << minn << endl;
  }
  return 0;
}
