#include<iostream>
#include<cstring>
#include<map>
using namespace std;
string st;
map<string, int> m;
int str2int(string s){
    int v = 0;
    int pre = 0;
    int p = s.find(' ');
    while(p != -1){
        string sub = s.substr(pre, p - pre);
//        cout << sub << endl;
        v = v * 10 + m[sub];
        pre = p + 1;
//        cout << "p + 1 = " << (p + 1) << endl;
        p = s.find(' ', p + 1);
//        cout << "p = " << p << endl;
    }

    return v;
}
int main(){
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;
    while(getline(cin, st)){
        int ans = 0;
//        cout << st << endl;
        int len = st.length();
        int pos = st.find('+');
        string left = st.substr(0, pos);
        string right = st.substr(pos + 2, len - pos - 3);
//        cout << "left : " << left  << " " <<left.length()<< endl;
//        cout << "right : " << right << " " << right.length() << endl;
        int a = str2int(left);
        int b = str2int(right);
        ans = a + b;
        if(ans  == 0) break;
        else cout << ans << endl;

    }
    return 0;
}
