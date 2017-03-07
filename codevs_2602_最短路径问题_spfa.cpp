#include<iostream>
#include<vector>
#include<iomanip>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
const int size = 10000 + 10;
const int inf = (1 << 30);
struct point{
    double x;
    double y;
};
struct edge{
    int to;
    double cost;
};
vector<point> p;
vector<edge> g[size];
bool inq[size];
double dis[size];
int n, m;
double get_dis(int a, int b){
    return sqrt((pow(p[a].x - p[b].x, 2)) + (pow(p[a].y - p[b].y, 2)));
}
void spfa(int st){
    for(int i = 1 ; i <= n ; i++){
        dis[i] = i == st ? 0 :inf;
    }
    memset(inq, false, sizeof(inq));
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(st);
    inq[st] = true;
    while(!q.empty()){
        int from = q.front();
        q.pop();
        inq[from] = 0;
        for(int i = 0 ; i < g[from].size() ; i++){
            int to = g[from][i].to;
            double cost = g[from][i].cost;
            if(dis[from] + cost < dis[to]){
                dis[to] = dis[from] + cost;
                if(!inq[to]){q.push(to); inq[to] = true;}
            }
        }

    }
}
int main(){
    while(cin >> n){
        p.clear();
        p.push_back((point){0, 0});
        int x, y;
        for(int i = 1 ; i <= n ; i++){
            cin >> x >> y;
            p.push_back((point){x, y});
        }
        int m;
        cin >> m;
        int from , to;
        double cost;
        for(int i = 0 ; i < m ; i++){
            cin >> from >> to;
            cost = get_dis(from, to);
            g[from].push_back((edge){to, cost});
            g[to].push_back((edge){from, cost});
        }

        cin >> from >> to;
        spfa(from);
        cout <<setiosflags(ios::fixed) << setprecision(2)<< dis[to] << endl;
    }
    return 0;
}
