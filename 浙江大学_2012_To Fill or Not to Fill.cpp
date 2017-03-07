#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("1.in");
ofstream cout("1.out");
int dis, cap, run, n;
const int size = 500 + 10;
struct station{
    double  price;
    int far;
};
station s[size];
bool cmp(station a, station b){
    return a.far < b.far;
}
int main(){
    while(cin >> dis >> cap >> run >> n){
        for(int i = 0 ; i < n ; i++) cin >> s[i].price >> s[i].far;
        sort(s, s + n, cmp);

        for(int i = 0 ; i < n ; i++)
        cout << s[i].far << " " << s[i].price << endl;


    }


    return 0;
}
