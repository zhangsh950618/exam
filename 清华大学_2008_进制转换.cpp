#include<iostream>
#include<stack>
using namespace std;
long long m, n, x;
long long char2int(char c){
    if(c >= '0' && c <= '9') return c - '0';
    if(c >= 'A' && c <='Z') return c - 'A' + 10;
}
string st;
int main(){
    string mp = "0123456789abcdefghijklmnopqrstuvwxyz";
    while(cin >> m >> n){
        stack<long long> s;
        while(!s.empty()) s.pop();
        cin >> st;
        long long v = 0;
        for(long long i = 0 ; i < st.length() ; i++){
            v = v * m + char2int(st[i]);
        }
//        cout << "v = " << v << endl;

        while(v){
            s.push(v % n);
            v /= n;
        }
        while(!s.empty()){
            cout << mp[s.top()];
            s.pop();
        }
        cout << endl;
    }
    return 0;
}
