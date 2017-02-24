#include<iostream>
#include<string.h>
#include<list>
using namespace std;
const int maxn = 500;
struct Dir{
  string dir;
  list<Dir *> sub;
};
int n;
Dir root = (Dir){"root"};
void add(string path){
  int p_len = path.length();
  int start = 0;
  int len = 0;
  string dir="";
  Dir cur_root = root;
  for(int i = 0 ; i < p_len ; i++){
    if(path[i] =='\\'){
      string dir = path.substr(start,len);
    }else{
      len++;
    }
  }
}
int main(){
  while(cin >> n && n){
    root.sub.clear();
    for(int i = 0 ; i < n ; i++){
      string path;
      cin >> path;
      add(path);
    }
  }
  return 0;
}
