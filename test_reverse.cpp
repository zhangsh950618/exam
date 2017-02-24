#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int main(){
  int n;
  while(cin >> n){
    for(int i = 0 ; i < n ; i++)
    v.push_back(i);
    vector<int>::iterator it;
    for(it = v.begin() ; it != v.end() ; it++)
    cout << *it << endl;

    reverse(v.begin(), v.end());

    for(it = v.begin() ; it != v.end() ; it++)
    cout << *it << endl;
  }






  return 0;
}
