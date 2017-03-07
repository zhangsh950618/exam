#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int size = 1000;
bool is_prime[size];
int tot_prime;
int prime[size];
void elur(){
    memset(is_prime, true, sizeof(is_prime));
    memset(prime, 0, sizeof(prime));
    for(int i = 2 ; i < size ; i++){
        if(is_prime[i]) prime[tot_prime++] = i;
        for(int j = 0 ; j < tot_prime ; j++){
            if(prime[j] * i >= size) break;
            is_prime[prime[j] * i] = false;
            if(i % prime[j] == 0) break;
        }
    }
}
string a, b;
bool is_number(char c){
    return c >= '0' && c <= '9';
}
int main(){
    elur();
    while(cin >> a >> b){
        if(a == "0" && b == "0") break;
        int la = a.length();
        int lb = b.length();
        stack<int> ta;
        stack<int> tb;
        stack<int> ans;
        while(!ta.empty()) ta.pop();
        while(!tb.empty()) tb.pop();
        while(!ans.empty()) ans.pop();
        int i = 0;
        while(i < la){
            if(is_number(a[i])){
                int v = 0;
                while(is_number(a[i]))
                v = v * 10 + a[i++] - '0';
                ta.push(v);
            }else{
                i++;
            }
        }
        i = 0;
        while(i < lb){
            if(is_number(b[i])){
                int v = 0;
                while(is_number(b[i]))
                v = v * 10 + b[i++] - '0';
                tb.push(v);
            }else{
                i++ ;
            }
        }
        int s = 0;
        if(ta.size() < tb.size()) swap(ta, tb);
        int t = 0;
        while(!ta.empty()){
            s += ta.top();
            ta.pop();
            if(!tb.empty()){
                s += tb.top();
                tb.pop();
            }
            ans.push(s % prime[t]);
            s /= prime[t];
            t++;
        }
        while(s){
            ans.push(s % prime[t]);
            s /= prime[t];
            t++;
        }

        if(!ans.empty()){
            cout << ans.top();
            ans.pop();
        }else{
            cout << 0 << endl;
            continue;
        }
        while(!ans.empty()){
            cout << "," << ans.top();
            ans.pop();
        }
        cout << endl;


    }
    return 0;
}
