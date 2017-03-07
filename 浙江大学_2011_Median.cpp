#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const long long size = 1000000 + 10;
long long la, lb;
long long a[size], b[size];
int main(){
    while(cin >> la){
    for(long long i = 0 ; i < la ; i++) cin >> a[i];
    cin >> lb;
    for(long long i = 0 ; i < lb ; i++) cin >> b[i];
    long long i = 0;
    long long j = 0;
    long long k = 0;
    long long ans = 0;
    long long l = (la + lb + 1) / 2;
    while(k != l && i < la && j < lb){
        if(a[i] < b[j])
            ans = a[i++];
        else
            ans = b[j++];
        k++;
    }
    while(k != l && i < la){ans = a[i++] ; k++;}
    while(k != l && j < lb){ans = b[j++] ; k++;}
    cout << ans << endl;
    }

    return 0;
}
