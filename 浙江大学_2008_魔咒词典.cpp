#include<fstream>
#include<cstring>
#include<map>
using namespace std;
ifstream cin("1.in");
ofstream cout("1.out");
string st;
map<string, string> mp;
map<string, string> mt;
int main(){

    while(getline(cin, st)){
        if(st == "@END@") break;
        int pos = st.find(' ');
        mp.clear();
        mt.clear();
        string p = st.substr(0, pos);
        string t = st.substr(pos + 1);
//        cout << "p=" << p << endl;
//        cout << "t=" << t << endl;
        mp[p] = t;
        mt[t] = p;


    }
    int m;
    cin >> m;
        string s;
        for(int i = 0 ; i < m  ; i++){
            getline(cin, s);
            if(s[0] == '['){
                if(mp.find(s) != mp.end())
                    cout << mp[s];
                else
                    cout << "what?" << endl;
            }else{
                if(mt.find(s) != mt.end())
                    cout << mt[s];
                else
                    cout << "what?" << endl;
            }
        }
    return 0;
}
