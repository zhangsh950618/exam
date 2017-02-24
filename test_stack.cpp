#include<iostream>
#include<stack>
using namespace std;
stack<char> s;
int main(){
  s.push('1');
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  return 0;
}
