#include<iostream>
#include<cstring>
using namespace std;
const int size = 5000 + 10;
int m[size][size];
int n, c1, c2;
int w;
int main(){
    while(cin >> n >> c1 >> c2){
        memset(m, -1, sizeof(m));
        m[c1][c2] = 0;
        for(int i = 1 ; i <= n ; i++){
            cin >> w;
            for(int j1 = c1 ; j1 >= 0 ; j1--)
            for(int j2 = c2 ; j2 >= 0 ; j2--){
                if(m[j1][j2] == i - 1){
                    if(j1 - w >= 0)
                    m[j1 - w][j2] = i;
                    if(j2 - w >= 0)
                    m[j1][j2 - w] = i;
                }

            }

        }
        bool flag = false;
        for(int j1 = 0 ; j1 <= c1 ; j1++)
        for(int j2 = 0 ; j2 <= c2 ; j2++)
        if(m[j1][j2] == n){flag = true; break;}

        if(flag)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
