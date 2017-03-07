#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
priority_queue<int> q;
priority_queue<int,vector<int>, greater<int> > r_q;
int main(){
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout << q.top() << endl;
        q.pop();
    }

    r_q.push(1);
    r_q.push(2);
    r_q.push(3);
    while(!r_q.empty()){
        cout << r_q.top() << endl;
        r_q.pop();
    }



}
