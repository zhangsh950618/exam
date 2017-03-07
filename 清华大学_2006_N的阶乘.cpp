#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
const int size = 1000000 + 10;
struct big_int{
    string data;
};
big_int operator * (big_int a, big_int b){
    string sa = a.data;
    string sb = b.data;
    int la = sa.length();
    int lb = sb.length();
    string ans = "";
    int temp[size] = {0};
    for(int j = lb - 1 ; j >= 0 ; j--)
    for(int i = la - 1 , k = i + j + 1; i >= 0 ; i--,k--){
        temp[k] += (sb[j] - '0') * (sa[i] - '0');

        temp[k - 1] += temp[k] / 10;
        temp[k] %= 10;
//        cout << "temp = " << temp[k] << endl;
    }
    int i = 0;
    while(temp[i] == 0 && i < la + lb - 1) i++;
    for( ; i < la + lb ; i++){
        ans += '0' + temp[i];
    }
//    cout << "ans = " << ans << endl;

    return (big_int){ans};

}
big_int big[size];
string int2str(int n){
    string ans = "";
    stack<int> s;
    while(n){
        s.push(n % 10);
        n /= 10;
    }
    while(!s.empty()){
        ans += '0' + s.top();
        s.pop();
    }
//    cout << "ans = " << ans << endl;
    return ans;
}
int main(){


    int n;
    while(cin >> n){
        if(n == 0) {cout << 1 << endl; continue;}
        big_int a = (big_int){"1"};
        big_int b;
        for(int i = 1 ; i <= n ; i++){
            b.data = int2str(i);
            a = a * b;
            big[i] = a;
        }
        cout << a.data << endl;
    }

    return 0;
}
