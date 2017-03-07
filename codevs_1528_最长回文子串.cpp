#include<iostream>
#include<cstring>
using namespace std;
const int size = 2 * 200000 + 100;
string t;
string st;
int radius[size];

void bf(string st){
    int len = st.length();
    for(int i = 0 ; i < len ; i++){
        int r = 1;
        while(i + r < len && i - r >=0 && st[i - r] == st[i + r]) r++;
        radius[i] = r;
    }
}
int main(){
    while(cin >> t){
//        cout << t << endl;
        st = "";
        for(int i = 0 ; i < t.length() ; i++){
            st += '#';
            st += t[i];
        }
        st += '#';
//        cout << st << endl;

        memset(radius, 0, sizeof(radius));

        bf(st);

        int len = st.length();
        int max_radius = 0;
        for(int i = 0 ; i < len ; i++){
            max_radius = max(max_radius, radius[i]);
        }

        cout << max_radius - 1 << endl;

    }

    return 0;
}
