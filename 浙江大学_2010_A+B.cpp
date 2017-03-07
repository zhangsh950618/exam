#include<iostream>
#include<cstring>
using namespace std;
string sa, sb;
bool is_number(char c){
    return c >= '0' && c <= '9';
}
int solve(string s){
    int len = s.length();
    if(len > 0){
        int flag = 1;
        if(s[0] == '-'){
            flag = -1;
            s.erase(0, 1);
        }
//        cout << " s = " << s << endl;
        int v = 0;
        for(int i = 0 ;i < s.length() ; i++){
            if(is_number(s[i]))
            v = v * 10 + s[i] - '0';
        }
        return v * flag;
    }
    return 0;
}
int main(){
    while(cin >> sa >> sb){
        int a = solve(sa);
        int b = solve(sb);
        cout << a + b << endl;
    }
    return 0;
}
