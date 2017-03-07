#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int min_x, min_y, max_x, max_y;
bool has_point;
int x, y;
int main(){
    has_point = false;
    while(cin >> min_x >> min_y){
        if(min_x == 0 && min_y == 0) break;
        max_x = min_x;
        max_y = min_y;
        while(cin >> x >> y){
            if(x == 0 && y == 0) break;
            min_x = min(min_x, x);
            min_y = min(min_y, y);
            max_x = max(max_x, x);
            max_y = max(max_y, y);
        }
        cout << min_x << " " << min_y;
        cout << " " << max_x << " " << max_y << endl;
    }
    return 0;
}
