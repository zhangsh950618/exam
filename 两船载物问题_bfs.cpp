#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace  std;
const int size =100 + 10;
int n, c1, c2;
int item[size];
bool cmp(int a, int b){
    return a > b;
}
struct pack{
    int step;
    int c1;
    int c2;
};
int w;
int main(){
    while(cin >> n >> c1 >> c2){
    queue<pack> q;
    while(!q.empty()) q.pop();
    for(int i = 0 ; i < n ; i++) cin >> item[i];
    sort(item, item + n, cmp);
    pack init = (pack){0, c1, c2};
    q.push(init);


    for(int i = 0 ; i < n ; i++){
        int w = item[i];
//        cout << "w = " << w << endl;
        while(!q.empty() && q.front().step == i){
            pack p = q.front();
//            cout << "step : " << p.step << " c1 " << p.c1 << " c2 " << p.c2 << endl;
            q.pop();
            if(p.c1 >= w){
                q.push((pack){i + 1,p.c1 - w, p.c2});
            }
            if(p.c2 >= w){
                q.push((pack){i + 1,p.c1, p.c2 - w});
            }
        }
        if(q.empty()) break;
    }
    if(q.empty()) cout << "NO" << endl;
    else cout << "YES" << endl;


    }

    return 0;
}
