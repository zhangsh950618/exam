#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
const int mod = 100000;
const int maxn = 100 + 10;
const int inf = (1 << 30);
int map[maxn][maxn];
int dis[maxn];
bool mark[maxn];
int n, m;
int main(){

  while(cin >> n >> m){
    memset(mark,false , sizeof(mark));
    for(int i = 0 ; i < n ; i++){
      dis[i] = inf;
      for(int j = 0 ; j < n ; j++){
        if(i == j) map[i][j] = 0;
        else map[i][j] = inf;
      }
    }
    for(int i = 0 ; i < m ; i++){
      int s,t;
      cin >> s >> t;
      map[s][t] = map[t][s]= pow(2,i);
    }
    for(int i = 0 ; i < n ; i++) dis[i] = map[0][i];
    int t = n -1;
    mark[0] = true;
    while(t--){
      int min_dis = inf;
      int min_pos = 0;
      for(int i = 0 ; i < n ; i++){
          if(!mark[i] && dis[i] < min_dis){
            min_pos = i;
            min_dis = dis[i];
          }
      }
      mark[min_pos] = true;
      for(int i = 0 ; i < n ; i++){
        if(!mark[i] && dis[min_pos] + map[min_pos][i] < dis[i]){
          dis[i] = dis[min_pos] + map[min_pos][i];
        }
      }
    }
    // for(int i = 0 ; i < n ; i++){
    //   for(int j = 0 ; j < n ; j++){
    //     cout << map[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    // for(int i = 0 ; i < n ; i++)
    // cout << dis[i] << " ";
    // cout << endl;
    //
    // }
    for(int i = 1 ; i < n ; i++)
    if(dis[i] != inf) cout << dis[i] % mod << endl;
    else cout << -1 << endl;

  }
  return 0;

}
