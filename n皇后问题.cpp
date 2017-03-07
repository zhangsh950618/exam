#include<iostream>
using namespace std;
const int size = 100;
int n, sum;
bool row[size], odd[size], even[size];
void dfs(int step){
    if(step == n){
        sum ++;
        return ;
    }
    for(int i = 0 ; i < n ; i++){
        if(!row[i] && !odd[i + step] && !even[i - step + n]){
            row[i] = true;
            odd[i + step] = true;
            even[i - step + n] = true;
            dfs(step + 1);
            row[i] = false;
            odd[i + step] = false;
            even[i - step + n] = false;
        }


    }

}
int main(){
    while(cin >> n){
        sum = 0;
        dfs(0);
        cout << sum << endl;
    }
    return 0;

}
