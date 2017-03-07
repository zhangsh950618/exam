#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const int size = 100 + 10;
const int INF = (1 << 30);
double matrix[size][size];
struct point{
    int x;
    int y;
};
point p[size];
int  n, m;
double get_dis(int a, int b){
    int ax = p[a].x;
    int ay = p[a].y;
    int bx = p[b].x;
    int by = p[b].y;
    return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}
int main(){
    while(cin >> n){
        for(int i = 1 ; i <= n ; i++)
        cin >> p[i].x >> p[i].y;

        cin >> m;

        int s, e;

        for(int i = 1 ; i <= n; i++)
        for(int j = 1 ; j <= n; j++)
        matrix[i][j] = matrix[j][i] = i == j ? 0 : INF;
        for(int i = 0 ; i < m ; i++){
            cin >> s >> e;
            matrix[s][e] = matrix[e][s] = get_dis(s, e);
//            cout << "matrix[s][e] : " << matrix[s][e] << endl;
        }
        for(int k = 1 ; k <= n ; k++)
        for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++){
            if(matrix[i][k] != INF && matrix[k][j] != INF && matrix[i][k] + matrix[k][j] < matrix[i][j]){
                matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }


        cin >> s >> e;

        cout <<setiosflags(ios::fixed) << setprecision(2) << matrix[s][e] << endl;


    }




    return 0;
}
