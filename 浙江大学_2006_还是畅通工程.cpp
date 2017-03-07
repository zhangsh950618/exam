#include<iostream>
using namespace std;
const int size = 100 + 10;
const int INF = (1 << 30);
int matrix[size][size];
bool mark[size];
int n;
int main(){
    while(cin >> n){
        if(n == 0) break;
        for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
        matrix[i][j] = i == j ? 0 : INF;
        int s, e, l;
        for(int i  = 0 ; i < n * (n - 1) / 2 ; i++){
            cin >> s >> e >> l;
            matrix[s][e] = matrix[e][s] = l;
        }
        for(int i = 0 ; i < )



    }
    return 0;
}
