#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
//ifstream cin("1.in");
//ofstream cout("1.out");
const long long mod = 100000;
const long long size = 1000;
const long long inf = LLONG_MAX;
struct edge{
    long long v;
    long long c;
};
long long n, m;
vector<edge> g[size];
long long dis[size];
bool inq[size];
void spfa(long long st){
    for(long long i =  0 ; i < n ; i++){
        dis[i] = i == st ? 0 :inf;
    }
    queue<long long> q;
    while(!q.empty()) q.pop();
    memset(inq, false, sizeof(inq));

    q.push(st);
    inq[st] = true;
    while(!q.empty()){
        long long u = q.front();
        q.pop();
        inq[u] = false;
        for(long long i = 0 ;i < g[u].size() ; i++){
            long long v = g[u][i].v;
            long long c = g[u][i].c;
            if(dis[u] + c < dis[v]){
                dis[v] = dis[u] + c;
                if(!inq[v]){
                    q.push(v);
                    inq[v] = true;
                }
            }
        }

    }
}
int main(){
    while(cin >> n >> m){
        long long u, v ;
        long long c = 1;
        for(long long i = 0 ; i < m ; i++){
            cin >> u >> v;
            g[u].push_back((edge){v, c});
            g[v].push_back((edge){u, c});
            c  = c * 2 % mod;
        }
        spfa(0);
        for(long long i = 1 ; i < n; i++){
            if(dis[i] != inf)
                cout << dis[i] % mod << endl;
            else
                cout << -1 << endl;

        }


    }


    return 0;
}
