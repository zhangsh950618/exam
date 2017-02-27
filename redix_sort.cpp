#include<iostream>
#include<math.h>
#include<string.h>
#include<fstream>
using namespace std;
#define rep(i, n) for(int i = 0 ; i < n ; i++)
ifstream fin("1.in");
const int maxn = 1000 + 10;
int number[maxn];
int n;
int getdigit(int num, int d){
    int k = pow(10, d - 1);
    return num / k % 10;
}

void radix_sort(){
    int c[10] = {0};
    int bucket[maxn] = {0};
    for(int k = 1 ; k <= 3 ; k++){

        for(int i = 0 ; i < n ; i++){
            c[getdigit(number[i], k)]++;
        }
        for(int i = 1 ; i < 10 ; i++) c[i] += c[i - 1];

        for(int i = n - 1 ; i >= 0  ; i--){
            bucket[--c[getdigit(number[i], k)]] = number[i];
        }

        for(int i = 0; i < n ; i++)
        number[i] = bucket[i];

    }
}


void p(int arr[]){
    rep(i, n) cout << arr[i] << " ";
    cout << endl;
}
int main(){
    while(fin >> n){
        cout << ("a" < "ab") << endl;
        rep(i, n) fin >> number[i];
        // before sort
        p(number);
        radix_sort();
        // after sort
        p(number);
    }

    return 0;
}
