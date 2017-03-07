#include<iostream>
#include<cstring>
using namespace std;
const int size = 100 + 10;
const int INF = (1 << 30);
int m[size][size];
bool mark[size];
int dis[size];
int n;
int main(){
    while(cin >> n){
        memset(mark, false, sizeof(mark));
        memset(m, 0, sizeof(m));
        for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
        cin >> m[i][j];
        for(int i = 1 ; i <= n ; i++) dis[i] = m[1][i];
        mark[1] = true;
        int sum = 1;
        int c = 0;
        while(sum < n){
            int min_dis = INF;
            int min_pos = 0;
            for(int i = 1 ; i <= n ; i++){
                if(!mark[i] && dis[i] < min_dis){
                    min_dis = dis[i];
                    min_pos = i;
                }
            }

//            cout << "min_dis" << min_dis << endl;
            c += min_dis;
            mark[min_pos] = true;
            for(int i = 1 ; i <= n ; i++){
                if(!mark[i]){
                    dis[i] = min(dis[i], m[min_pos][i]);
                }
            }

            sum ++;
        }

        cout << c << endl;



    }





    return 0;
}
