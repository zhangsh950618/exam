#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, m ,c;
priority_queue<int , vector<int>, less<int> > q;
int main(){
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        while(!q.empty()) q.pop();
        for(int i = 0 ;i < n ; i++){
            cin >> c;
            q.push(c);
        }
        if(!q.empty()){
            cout << q.top();
            q.pop();
        }
        for(int i = 1 ; i < m ; i++){
            if(!q.empty()){
                cout << " " << q.top();
                q.pop();
            }
        }
        cout << endl;
    }

    return 0;
}
