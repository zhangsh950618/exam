#include<iostream>
#include<algorithm>
using namespace std;
const int size = 100000 + 10;
int n, m;
int num[size];
bool cmp(int a, int b){
    return  a > b;
}
int main(){
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        for(int i = 0 ;i < n ;i++)
        cin >> num[i];
        sort(num, num + n, cmp);
        cout << num[0];
        for(int i = 1 ; i < m ; i++)
        cout << " " << num[i];
        cout << endl;
    }
    return 0;
}
