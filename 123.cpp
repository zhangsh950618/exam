#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
#define MAXN 100
#define MAXM 100
#define INF 1<<30
queue<int> q;
int first[MAXN], next[MAXM];
struct edge{
    int u, v, w;
}a[MAXM];
int dist[MAXN], inq[MAXN];
int n, m;
void spfa(int st){
    for(int i=0; i<n; i++) dist[i] = i==st? 0: INF;
    memset(inq, 0, sizeof(inq));
    q.push(st);
    inq[st] = 1;                    //反正马上就出队，这个inq可以不要
    while(!q.empty()){
        int u = q.front(); q.pop();
        inq[u] = 0;
        for(int e=first[u]; e!=-1; e=next[e]){
            int v = a[e].v;
            if(dist[v] > dist[u]+a[e].w){
                dist[v] = dist[u]+a[e].w;
                if(!inq[v]) { q.push(v); inq[v] = 1; }      //inq=1 !!!!
            }
        }
    }
}
void read_graph(){
    cin>>n>>m;
    memset(first, -1, sizeof(first));       //别忘了初始化 表头
    for(int e=0; e<m; e++){
        cin>>a[e].u>>a[e].v>>a[e].w;
        next[e] = first[a[e].u];
        first[a[e].u] = e;
    }
}
int main(){
    read_graph();
    int st;
    cin>>st;
    spfa(st);
    for(int i=0; i<n; i++){
        printf("[%d,%d]=%d\n", st, i, dist[i]);
    }
}
