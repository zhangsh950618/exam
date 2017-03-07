#include<iostream>
#include<cstring>
using namespace std;
const int size =1000 + 10;
const int INF = (1 << 30);
int cost[size][size];
int matrix[size][size];
int d[size], c[size];
bool mark[size];
int n, m;
int main(){
    while(cin >> n >> m){
        if(n == 0 && m ==0) break;
        memset(cost, 0, sizeof(cost));
        memset(matrix, 0, sizeof(matrix));
        memset(d, 0, sizeof(d));
        memset(c, 0, sizeof(c));
        memset(mark, false, sizeof(mark));
        int s, e;

        for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
        matrix[i][j] = i == j ? 0 : INF;

        for(int i = 0 ;i < m ; i++){
            cin >> s >> e;
            cin >> matrix[s][e] >> cost[s][e];
            matrix[e][s] = matrix[s][e];
            cost[e][s] = cost[s][e];
        }

        for(int i = 1 ; i <= n ; i++){
            c[i] = cost[s][i];
            d[i] = matrix[s][i];
        }
        cin >> s >> e;
        int sum = 0;
        while(sum < n){
            int min_d = INF;
            int min_p = 1;
            for(int i = 1 ; i <= n ; i++){
                if(!mark[i] && d[i] < min_d){
                    min_d = d[i];
                    min_p = i;
                }
            }
            mark[min_p] = true;
            for(int i = 1 ; i <= n ; i++){
                if(!mark[i] && matrix[min_p][i] != INF){
                    int k = d[min_p] + matrix[min_p][i];
                    int l = c[min_p] + cost[min_p][i];
                    if(k < d[i] || k == d[i] && l < c[i]){
                        d[i] = k;
                        c[i] = l;
                    }
                }
            }
            sum++;
        }

        cout << d[e] << " " << c[e] << endl;
    }
    return 0;
}
