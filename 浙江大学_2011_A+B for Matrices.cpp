#include<iostream>
using namespace std;
//ifstream cin("1.in");
//ofstream cout("1.out");
const int size = 100;
int a[size][size], b[size][size];
int m, n;
int main(){
    while(cin >> m){
    if(m == 0) break;
        cin >> n;
    for(int i = 0 ; i < m ; i++)
    for(int j = 0 ; j < n ; j++)
    cin >> a[i][j];


    for(int i = 0 ; i < m ; i++)
    for(int j = 0 ; j < n ; j++){
        cin >> b[i][j];
        a[i][j] += b[i][j];
    }
    int sum = 0;
    for(int i  = 0 ; i < m ; i++){
        int flag = true;
        for(int j = 0  ; j < n ; j++)
        if(a[i][j]) flag = false;
        if(flag) sum ++;
    }

    for(int j  = 0 ; j < n ; j++){
        int flag = true;
        for(int i = 0  ; i < m ; i++)
        if(a[i][j]) flag = false;
        if(flag) sum ++;
    }

    cout << sum << endl;
    }
    return 0;
}
