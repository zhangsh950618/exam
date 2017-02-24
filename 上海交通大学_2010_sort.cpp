#include<iostream>
#include<set>
using namespace std;
set<int> s;
int main(){
  int t;
  while(cin >> t){
    s.clear();
    int temp;
    for(int i = 0 ; i < t ; i++){
      cin >> temp;
      s.insert(temp);
    }
    set<int>::iterator it = s.begin();
    cout << *it ;
    it++;
    for( ; it != s.end() ; it++){
      cout << " " << *it;
    }
    cout << endl;
  }

}
