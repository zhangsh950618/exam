#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
    int m;
    string scn, st, et, ecn;
    string cn, s, e;
    cin >> m;
    cin >> scn >> st >> et;
    ecn = scn;
    for(int i = 1 ; i < m ; i++){
        cin >> cn >> s >> e;
        if(s < st){
           st = s;
           scn = cn;
        }
        if(e > et){
            et = e;
            ecn = cn;
        }

    }

    cout << scn << " " << ecn << endl;
    }
    return 0;
}
