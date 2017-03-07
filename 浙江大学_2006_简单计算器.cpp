#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<stack>
#include<iomanip>
using namespace std;
string st;
stack<double> dig;
stack<char> flag;
map<char, int> m;
bool is_number(char c){
    return c >= '0' && c <= '9';
}
void cal(char c){
    double b = dig.top();
    dig.pop();
    double a = dig.top();
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
    while(getline(cin, st)){
        if(st == "0") break;
        while(!dig.empty()) dig.pop();
        while(!flag.empty()) flag.pop();
        flag.push('#');
        st += '#';
//        cout << st << endl;
        int len = st.length();
        int i = 0;
        while(i < len){
            if(is_number(st[i])){
                double v = 0;
                while(is_number(st[i]))
                v = v * 10 + st[i++] - '0';
                dig.push(v);
            }else if(m[st[i]] != 0){
                while(m[st[i]] <= m[flag.top()]){
                    char c = flag.top();
                    if(c == '#' && st[i] == '#') break;
                    flag.pop();
                    cal(c);
                }
                flag.push(st[i]);
                i++;
            }else{
                i++;
            }
        }
        cout <<setiosflags(ios::fixed) << setprecision(2) << dig.top() << endl;

    }
    return 0;
}
