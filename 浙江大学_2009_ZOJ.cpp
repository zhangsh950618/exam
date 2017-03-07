#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int size = 3;
int m[size];
string st;
int main(){
    while(cin >> st){
        if(st == "E") break;
        memset(m, 0, sizeof(m));
        int len = st.length();
        for(int i = 0 ; i < len ; i++){
            char c = st[i];
            if(c == 'Z')m[0]++;
            else if(c == 'O') m[1]++;
            else if(c == 'J') m[2]++;
        }
//        for(int i = 0 ; i < 3 ; i++)
//        cout << m[i] << endl;
//        cout << "len = " << len << endl;
        for(int i = 0 ;m[0] + m[1] + m[2]; i = (++i) % 3){
//        cout << "i = " << i << endl;
            if(m[i]){
                m[i]--;
                if(i == 0) cout << 'Z';
                else if(i == 1) cout << 'O';
                else if(i == 2) cout << 'J';
            }
        }
//        for(int i = 0 ; i < 3 ; i++)
//        cout << m[i] << endl;
        cout << endl;
    }
    return 0;
}
