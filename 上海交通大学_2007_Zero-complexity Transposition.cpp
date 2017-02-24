#include<iostream>
#include<stack>
using namespace std;
stack<long long> s;
int main(){
  long long t;
  while(cin >> t){
    long long temp;
    for(long long i = 0 ; i < t; i++){
      cin >> temp;
      s.push(temp);
    }
    long long is_first = 1;
    while(!s.empty()){
      if(is_first){
        cout << s.top();
        is_first = 0;
      }else{
        cout << " " << s.top();
      }
      s.pop();
    }
    cout << endl;
  }
  return 0;
}
