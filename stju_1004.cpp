#include<iostream>
using namespace std;
int m , n , u , d , f;
int main(){
  while(cin >> m >> n >> u >> f >> d){
    int ans = 0;
    int tim = 0;
    bool flag = true;
    char l;
    for(int i = 0 ; i < n ; i++){
      cin >> l;
      if(flag){
      if(l == 'u'){
        if(tim + u + d <= m) {
          ans ++;
          tim += u + d;
        }else{flag = false;}
      }else if(l == 'd'){
        if(tim + u + d <= m) {
          ans ++;
          tim += u + d;
        }else{flag = false;}
      }else if(l == 'f'){
        if(tim + 2 * f <= m){
          ans ++;
          tim += 2 * f;
        }else{flag = false;}
      }
      }

    }
    cout << ans << endl;
  }
  return 0;
}
