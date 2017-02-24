#include<iostream>
using namespace std;
string pre , in;
void bt_from_order(string pre,string in){
  int l = pre.length();
  if(l > 0){
    char c = pre[0];
    int i = 0;
    while(i < l){
      if(in[i] == c) break;
      else i++;
    }
    bt_from_order(pre.substr(1, i), in.substr(0, i));
    cout << c;
    bt_from_order(pre.substr(i + 1), in.substr(i + 1));
  }
}
int main(){
  pre = "GDAFEMHZ";
  in = "ADEFGHMZ";
  bt_from_order(pre, in);
  cout << endl;
  return 0;
}
