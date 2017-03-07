#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool has_swap = false;
struct BigInt{
    string data;
};
bool operator < (BigInt a, BigInt b){
    int la = a.data.length();
    int lb = b.data.length();
    return la < lb || la == lb && a.data < b.data;
}

bool operator <= (BigInt a, BigInt b){
    int la = a.data.length();
    int lb = b.data.length();
    return la < lb || la == lb && a.data <= b.data;
}

BigInt operator + (BigInt a, BigInt b){
    string sa = a.data;
    string sb = b.data;
    int la = sa.length();
    int lb = sb.length();
    int s = 0;
    for(int i = la - 1, j = lb - 1 ; i >= 0; i--, j--){
        s += sa[i] - '0';
        if(j >=0 )
        s += sb[j] - '0';
        sa[i] = s % 10 + '0';
        s /= 10;
    }
    if(s) sa = (char)(s + '0') + sa;
    return (BigInt){sa};

}
BigInt operator -(BigInt a ,BigInt b){
    string sa = a.data;
    string sb = b.data;
    int la = sa.length();
    int lb = sb.length();
    for(int i = la - 1, j = lb - 1 ; i >= 0 ; i--, j--){
        int s = sa[i] - '0';
        if(j >= 0)
        s -= sb[j] - '0';
        if(s < 0){
            sa[i - 1]--;
            s += 10;
        }
        sa[i] = s % 10 + '0';
    }
    int i = 0;
    while(sa[i] == '0' && i < la) i++;
    sa = sa.substr(i);
    if(has_swap) sa = "-" + sa;
    return (BigInt){sa};
}
BigInt operator *(BigInt a, BigInt b){
    string sa = a.data;
    string sb = b.data;
    int la = sa.length();
    int lb = sb.length();
    int temp[1000000] = {0};
    for(int j = lb - 1 ; j >= 0 ; j--){
        for(int i = la - 1 ,k = i + j + 1; i >= 0 ; i--, k--){
            int s = temp[k] + (sa[i] - '0') * (sb[j] - '0');
            temp[k] = s % 10;
            temp[k - 1] += s / 10;
        }
    }
    int i = 0;
    while(temp[i] == 0 && i < la + lb - 1) i++;
    string ans = "";
    for( ; i < la + lb; i++){
        ans += (char)(temp[i] + '0');
    }
    return (BigInt){ans};
}
bool operator == (BigInt a, BigInt b){
    return a.data == b.data;
}
BigInt operator /(BigInt a, BigInt b){
    string ans = "";
    BigInt sub;
    while(a.data.length()){
        sub.data += a.data.substr(0, 1);
        a.data = a.data.substr(1);
        int i = 1;
        string temp = "";
        BigInt t;
        for(i = 1 ; i < 10 ; i++){
            temp = "";
            temp += '0' + i;
            t.data = temp;
            if(sub < t * b) break;
        }
        if(i != 9) i--;
        temp = "";
        temp += '0' + i;
        t.data = temp;
        sub = sub - t * b;
        ans += '0' + i;
    }
    int j = 0;
    while(ans[j] == '0' && j < ans.length() - 1) j++;
    ans = ans.substr(j);
    return (BigInt){ans};
}
string s1, s2;
int main(){
    while(cin >> s1 >> s2){

        has_swap = false;
        BigInt a = (BigInt){s1};
        BigInt b = (BigInt){s2};
        if(a < b){
            has_swap = true;
            swap(a, b);
        }
        if(has_swap){cout << "0" << endl;}
        else cout << (a / b).data << endl;
    }
    return 0;
}
