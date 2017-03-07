#include<iostream>
using namespace std;
//ifstream cin("1.in");
//ofstream cout("1.out");
const int size = 100 + 10;
bool is_number(char c){
    return c >= '0' && c <= '9';
}
struct record{
    int st ;
    int et ;
};
record rec[size];
int n;
char op;
string tim;
int str2int(string t){
    int len = t.length();
    int is_hour = true;
    int sum = 0;
    int i = 0;
    while(i < len){
        if(is_number(t[i])){
            int v = 0;
            while(is_number(t[i]))
            v = v * 10 + t[i++] - '0';
            if(is_hour){
                sum += 60 * v;
                is_hour = false;
            }else{
                sum += v;
            }
        }else{
            i++;
        }
    }

    return sum;
}
void operate(int n, char op, int t){
    switch(op){
        case 'S':{
            rec[n].st = t;
            break;
        }
        case 'E':{
            rec[n].et = t;
            break;
        }
    }
}
int main(){
    while(cin >> n){
        if(n == -1) break;


        for(int i = 0 ; i < size ; i++){
            rec[i].st = -1;
            rec[i].et = -1;
        }

        cin >> op;
        cin >> tim;
        if(n == 0){
            cout << 0 << " "<< 0 << endl;
            continue;
        }
        operate(n, op, str2int(tim));
        while(cin >> n >> op >> tim){
            if(n == 0) break;
            operate(n, op, str2int(tim));
        }
        int tot = 0;
        int tot_tim = 0;
        for(int i = 0 ; i < size ; i++){
            if(rec[i].st == -1 || rec[i].et == -1) continue;
            tot ++ ;
            tot_tim += rec[i].et - rec[i].st;
        }
        if(tot != 0){
            int flag = 0;
            if((tot_tim * 10 /tot) % 10 >= 5) flag = 1;

            cout << tot << " " << tot_tim / tot + flag << endl;


        }else{
            cout << 0 << " "<< 0 << endl;
        }

    }
    return 0;
}
