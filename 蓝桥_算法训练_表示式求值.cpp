#include<iostream>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
string s;
bool is_number(char c){
    return c >= '0' &&  c <= '9';
}
map<char, int> m;
stack<char> op;
stack<int> dig;
void cal(char c){
    int a = dig.top();
    dig.pop();
    int b = dig.top();
    swap(a, b);
    dig.pop();
    switch(c){
        case '+':{
            dig.push(a + b);
            return ;
        }
        case '-':{
            dig.push(a - b);
            return ;
        }
        case '*':{
            dig.push(a * b);
            return ;
        }
        case '/':{
            dig.push(a / b);
            return ;
        }
    }
}
int main(){
    m['#'] = 1;
    m['+'] = 2;
    m['-'] = 2;
    m['*'] = 3;
    m['/'] = 3;
    while(cin >> s){
        //clear the stack
        s += '#';
        while(!op.empty()) op.pop();
        while(!dig.empty()) dig.pop();

        op.push('#');
        int l = s.length();
        for(int i = 0 ; i < l ; ){

            if(is_number(s[i])){
                int v = 0;
                while(is_number(s[i]))
                v = v * 10 + s[i++] - '0';
                dig.push(v);
            }else if(s[i] == '('){
                op.push('(');
                i++;
            }else if(s[i] == ')'){
                while(!op.empty() && op.top() != '('){
                    char c = op.top();
                    op.pop();
                    cal(c);
                }
                op.pop();
                i++;
            }else{
                while(m[s[i]] <= m[op.top()]){
                    char c = op.top();
                    op.pop();
                    //has finish the cal;
                    if(c == '#' && s[i] == '#'){
                        break;
                    }
                    cal(c);
                }
                op.push(s[i]);
                i++;
            }
        }

        cout << dig.top() << endl;
    }
    return 0;
}
