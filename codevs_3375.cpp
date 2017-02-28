#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 20000;
string st;
set<string> s;
struct Node{
    string sub;
    int sum;
};
Node node[maxn];
bool cmp(Node a, Node b){
    return a.sub < b.sub;
}
int main(){
    while(cin >> st){
        int len = st.length();
        int t = 0;
        s.clear();
        //遍历下标
        for(int i = 0 ; i < len ; i++){
            for(int l = 1 ; l <=  len - i ; l++){
            string sub = st.substr(i, l);
            pair<set<string>::iterator,bool> p;
            p = s.insert(sub);
            //如果重复,不统计
            if(!p.second) continue;
            int sum = 0;
            for(int pos = st.find(sub); pos < len && pos != string::npos ; pos = st.find(sub, pos + 1)) sum ++;
            node[t++] = (Node){sub, sum};
            }
        }

        sort(node, node + t, cmp);

        for(int i = 0 ; i < t ; i++){
            cout << node[i].sub << " " << node[i].sum << endl;
        }

    }
    return 0;
}
