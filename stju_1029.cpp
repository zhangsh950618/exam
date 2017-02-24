#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
const int maxn = 100 + 10;
char temp[maxn];

int main(){
  int n;
  while(cin >> n){
    vector<int> vec[maxn];
  getchar();
  char c;
  for(int i = 1 ; i <= n ; i++){
    gets(temp);
    int j = 0;
    while(temp[j]){
      if(temp[j] >= '0' && temp[j] <= '9'){
        int v = 0;
        while(temp[j] >= '0' && temp[j] <= '9')
        v = v * 10 + temp[j++] - '0';
        vec[i].push_back(v);
      }
      else
        j++;
    }
    // for(vector<int>::iterator it = vec[i].begin() ; it != vec[i].end() ; it++)
    // cout << *it << endl;
  }
  int a, b;
  for(int i = 0 ; i < n - 1 ; i++){
    cin >> a >> b;
    for(vector<int> ::iterator it = vec[a].begin() ; it != vec[a].end() ; it++)
    vec[b].push_back(*it);
  }
  vector<int>::iterator it = vec[b].begin();
  cout << *it;
  it++;
    for(; it != vec[b].end() ; it++) cout << " " << *it;
    cout << endl;

  }

  return 0;
}
