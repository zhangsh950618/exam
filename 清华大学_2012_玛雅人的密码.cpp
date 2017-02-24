#include<iostream>
#include<set>
#include<string.h>
#include<queue>
using namespace std;
int len;
string str;
struct node{
  string str;
  int step;
};
queue<node> q;
set<string> s;
int find(string str){
  int len = str.length();
  for(int i = 0 ; i < len - 1 ; i++){
    if(str.substr(i,4) == "2012")
    return 1;
  }
  return 0;
}
string swp(string str,int i,int j){
  char c;
  c = str[i];
  str[i] = str[j];
  str[j] = c;
  return str;
}
int main(){
  while(cin >> len){
    cin >> str;
    while(!q.empty()) q.pop();
    s.clear();
    q.push((node){str,0});
    int is_find = 0;
    while(!q.empty()){
      node n = q.front();
      q.pop();
      string str = n.str;
      int step = n.step;
      if(find(str)){
        is_find = 1;
        cout << step << endl;
        break;
      }
      for(int i = 0 ; i < len - 1 ; i++){
        string tem_str = swp(str,i,i+1);
        pair<set<string>::iterator,bool> p = s.insert(tem_str);
        if(p.second) q.push((node){tem_str,step+1});
      }
    }
    if(!is_find)cout << -1 << endl;;
  }

}
