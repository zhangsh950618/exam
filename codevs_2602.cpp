#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
const int size = 100 + 10;
const int INF = (1 << 20);
struct P{
    int x;
    int y;
};
P point[size];
double m[size][size];
bool mark[size];
double dis[size];
int n;
double get_dis(int a, int b){
    int ax = point[a].x;
    int bx = point[b].x;
    int ay = point[a].y;
    int by = point[b].y;
    return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}
int main(){
    while(cin >> n){
        memset(m, 0, sizeof(m));
        memset(mark, false, sizeof(mark));

        for(int i = 1 ; i <= n ; i++)
            cin >> point[i].x >> point[i].y;
        int k;
         cin >> k;
         int s, e;

         for(int i = 1 ; i <= n ; i++)
         for(int j = 1 ; j <= n ; j++){
            if(i == j) m[i][j] = 0;
            else m[i][j] = m[j][i] = INF;
         }

         for(int i = 0 ;i < k ; i++){
            cin >> s >> e;
            m[s][e] = m[e][s] = get_dis(s, e);
         }
         cin >> s >> e;
         for(int i = 1 ; i <= n; i++){
            dis[i] = m[s][i];
        }
        int sum = 0;
        while(sum <= n){
            double min_dis = INF;
            int min_pos = 0;

            //find the min_dis
            for(int i = 1 ; i <= n; i++){
                if(!mark[i] && dis[i] < min_dis){
                    min_pos = i;
                    min_dis = dis[i];
                }
            }
            mark[min_pos] = true;
            for(int j = 1;  j <= n; j++){
                if(!mark[j] && m[min_pos][j] != INF){
                    dis[j] = min(dis[j], dis[min_pos] +m[min_pos][j]);
                }
            }
            sum++;
        }

        cout << setiosflags(ios::fixed) << setprecision(2)<< dis[e] << endl;

    }


    return 0;
}
