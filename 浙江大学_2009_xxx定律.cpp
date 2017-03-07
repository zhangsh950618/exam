#include<iostream>
using namespace std;
int n;
int main(){
    while(cin >> n){
        if(n == 0) break;
        int sum = 0;
        while(n != 1){
            if(n % 2 == 0) n /= 2;
            else n = (3 * n + 1) / 2;
            sum ++;
        }
        cout << sum << endl;
    }
    return 0;
}
