#include<iostream>
#include<algorithm>
#include<cstring>
const int size = 1000 + 10;
struct country{
    int b;
    int g;
    int j;
    int r;
    double pg;
    double pj;
};
int n, m;
country c[size];
bool cmpg(country a, country b){
    return a.g > b.g;
}
bool cmpj(country a, country b){
    return a.j > b.j;
}
bool cmppg(country a, country b){
    return a.pg > b.pg;
}
bool cmppj(country a, country b){
    return a.pj > b.pj;
}
int main(){
    while(cin >> n >> m){
        int g, j, r;
        for(int i = 0 ; i < n ; i++){
            cin >> g >> j >> r;
            c[i] = (country){i, g, j, r, (double)g /r, (double)j / r};
        }
        sort(c, c + n, cmpg);
        int p = 1;
        for(int i = 0 ; i < n ; i++){
            if(p!= 0 && c[i].g != c[i - 1].g)p++;
            if(c[i].b == )
        }

    }
    return 0;
}
