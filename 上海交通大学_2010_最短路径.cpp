#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const long long size = 500 + 10;
const long long INF = (1 << 30);
const int mod = 100000;
long long matrix[size][size];
long long dis[size];
bool mark[size];
long long n, m;
int main(){
    while(cin >> n){


        for(long long i = 0 ; i < n ; i++)
        for(long long j = 0 ; j < n ; j++)
        matrix[i][j] = i == j ? 0 : INF;


        memset(mark, false, sizeof(mark));
        for(long long i = 0 ; i < n ; i++) dis[i] = INF;

        long long s, e;
        cin >> m;

        for(long long i = 0 ; i < m ; i++){
            cin >> s >> e;
            long long k = pow(2, i);
            k %= 100000;
//            cout << k << endl;
            matrix[s][e] = matrix[e][s] = k;
        }

        long long sum = 0;
        for(long long i = 0 ; i < n ; i++){
            dis[i] = matrix[0][i];
//            cout << "dis[i] = " << dis[i] << endl;
        }
        while(sum < n){
            long long min_len = INF;
            long long min_pos = 0;
            for(long long i = 0 ; i < n ; i++){
                if(!mark[i] && dis[i] < min_len){
                    min_len = dis[i];
                    min_pos = i;
                }
            }
//            cout << "min_pos = " << min_pos << endl;
            mark[min_pos] = true;
            sum++;
            for(long long i = 0 ; i < n ; i++){
                if(!mark[i] && matrix[min_pos][i] != INF){
                if((dis[min_pos] + matrix[min_pos][i]) % 100000 < dis[i])
                    dis[i] = dis[min_pos] + matrix[min_pos][i];
                }
            }
        }

        for(long long i = 1 ; i < n ; i++){
            if(dis[i] == INF) cout << -1 << endl;
            else cout << dis[i] % mod << endl;
        }


    }


    return 0;
}
