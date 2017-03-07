#include<iostream>
#include<cstring>
using namespace std;
int a, b, k;
bool decide(){
    for(int i = 0 ; i < k ; i++){
        if(a % 10 != b % 10) return false;
        a /= 10;
        b /= 10;
    }
    return true;
}
int main(){
    while(cin >> a >> b >> k){
        if(a == 0 && b == 0) break;
        if(decide()) cout << -1 << endl;
        else cout << a + b << endl;
    }
    return 0;
}
