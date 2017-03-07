#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double p, t, g1, g2, g3, gj;
int main(){
    while(cin >> p >> t >> g1 >> g2 >> g3 >> gj){
        double ans = 0;
        if(abs(g1 - g2) <= t){
            ans  = (g1 + g2) / 2;
        }else{
            bool f1 = (abs(g1 - g3) <= t);
            bool f2 = (abs(g2 - g3) <= t);
            if(f1 && f2){
                ans = max(g1,max(g2, g3));
            }else if(f1 || f2){
                if(abs(g1 - g3) > abs(g2 - g3))
                swap(g1, g2);
                ans  = (g1 + g3) / 2;
            }else{
                ans = gj;
            }
        }
        cout << setiosflags(ios::fixed) << setprecision(1) << ans << endl;
    }
    return 0;
}
