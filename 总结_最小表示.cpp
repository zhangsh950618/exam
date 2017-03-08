#include<iostream>
using namespace std;
int n;
string st;
int parse(string s){
    int i = 0;
    int j = 1;
    int k = 0;
    int l = s.length();
    s += s;
    while(i < l && j < l && k < l){
        if(s[i + k] == s[j + k]) k++;
        else{
            if(s[i + k] > s[j + k])
            i = i + k + 1;
            else
            j = j + k + 1;
            k = 0;
            if(i == j)
            j = i + 1;
        }
    }

    return i < j ? i : j;

}
int main(){
    while(cin >> n){
        cin >> st;
        int k = parse(st);
        cout << k << endl;
    }
    return 0;
}
