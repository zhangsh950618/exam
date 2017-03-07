#include<iostream>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;
const long long size = 1000000;
const long long inf = (LLONG_MAX);
long long l1, l2, l3, c1, c2, c3;
long long a, b , n;
long long dis[size], f[size];
int main(){
    while(cin >> l1 >> l2 >> l3){
    memset(dis, 0, sizeof(dis));
    memset(f, 0, sizeof(f));
    cin >> c1 >> c2 >> c3;
    cin >> a >> b;
    if(a > b) swap(a, b);
    cin >> n;
    for(long long i = 2 ; i <= n ; i++) cin >> dis[i];
    for(long long i = b ; i > a ; i--) dis[i] -= dis[i - 1];

    for(long long i = 1 ; i <= b ; i++) f[i] = inf;
    f[a] = 0;

    for(long long i = a + 1 ; i <= b ; i++){
        long long d = 0;
        for(long long j = i - 1 ; j >= a ; j--){
            d += dis[j + 1];
            if(d <= l1) f[i] = min(f[i], f[j] + c1);
            else if(d <= l2) f[i] = min(f[i], f[j] + c2);
            else if(d <= l3) f[i] = min(f[i], f[j] + c3);
            else break;
        }
    }

    cout << f[b] << endl;





    }



}
