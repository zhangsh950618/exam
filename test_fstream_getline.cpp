#include<fstream>
#include<cstdio>
using namespace std;
ifstream cin("1.in");
ofstream cout("1.out");
const int size = 1000;
string st;
char dis[size];
int main(){
//    while(getline(cin, st))
//    cout << st << endl;

//    while(cin.getline(dis, 500))
//    cout << dis << endl;
    freopen("1.in","r", stdin);
    freopen("1.out","w",stdout);
    while(scanf("%s", dis)!= EOF)
    printf("%s\n", dis);
    return 0;
}
