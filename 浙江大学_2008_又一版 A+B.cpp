#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
long long m, a, b;
int main(){
    while(cin >> m){
        if(m == 0) break;
        cin >> a >> b;
        long long t = a + b;
        stack<long long> s;
        while(!s.empty()) s.pop();
        while(t){
            s.push(t % m);
            t /= m;
        }
        if(s.empty()) cout << 0;
        while(!s.empty()){
            cout << s.top();
            s.pop();
        }
        cout << endl;

    }
    return 0;
}
