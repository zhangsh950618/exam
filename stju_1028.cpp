#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
//ifstream cin("1.in");
//ofstream cout("1.out");
int n;
string st;
int main(){
    while(cin >> n){
        bool is_if = false;
        bool ok = true;
        stack<string> s;
        while(!s.empty()) s.pop();
        for(int i = 0 ; i < n ; i++){
            cin >> st;
            if(!ok) continue;
            if(is_if && st != "then"){ok = false; continue;}
            if(st == "if") is_if = true;
            else if(st == "then"){
                if(is_if = false) {ok = false;}
                else {is_if = false; s.push("if");}
            }else if(st == "begin"){
                s.push("begin");
            }else if(st == "end"){
                //弹去栈顶所有的if
                while(!s.empty() && s.top() != "begin") s.pop();
                if(s.empty()){ok = false; break;}
                else s.pop();//弹出与其匹配的begin
            }else if(st == "else"){
                if(!s.empty() && s.top() == "if") s.pop();
                else{ok = false; break;}
            }
        }

        while(!s.empty()){
            if(s.top() == "begin"){ok = false; break;}
            else s.pop();
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}
