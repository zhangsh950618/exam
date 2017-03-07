#include<iostream>
using namespace std;
int y, m, d;
int m_dict[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31 ,30, 31};
bool is_leap(int year){
    return year % 400 == 0 ||  y % 4 == 0 && y% 100 != 0;
}
int get_m_lim(int year, int mon){
    if(mon == 2) return is_leap(year) + m_dict[mon];
    return m_dict[mon];
}
int solve(int y, int m, int d){
    int sum = 0;
    int cy = y, cm = 1, cd = 1;
    while(cy != y || cm != m || cd != d){
            sum ++;
//            cout << "sum = " << sum << endl;
            cd++;
            int lim = get_m_lim(cy, cm);
            if(cd > lim){
                cd -= lim;
                cm++;
            }
    }
    return sum + 1;
}
int main(){
    while(cin >> y >> m >> d){
        cout << solve(y, m , d) << endl;
    }

    return 0;
}
