#include<iostream>
using namespace std;
long long n;
int main(){
    while(cin >> n){
        long long ans = 1;
        for(long long i = 1 ; i <= n ; i++) ans *= i;
        cout << ans << endl;
    }
    return 0;
}
