#include<iostream>
#include<algorithm>
using namespace std;
//ifstream cin("1.in");
//ofstream cout("1.out");
const int size = 100000 + 10;
struct student{
    string number;
    string name;
    int score;
};
student s[size];
int n, op;
bool cmp1(student a, student b){
    return a.number < b.number;
}

bool cmp2(student a, student b){
    if(a.name != b.name)
    return a.name < b.name;
    return a.number < b.number;
}

bool cmp3(student a, student b){
    if(a.score != b.score)
    return a.score < b.score;
    return a.number < b.number;
}
void print_student(){
    for(int i = 0 ; i < n ; i++)
    cout << s[i].number << " " << s[i].name << " " << s[i].score << endl;
}
int main(){
    int c = 1;
    while(cin >> n >> op){
        if(n == 0 && op == 0) break;
        cout <<"Case "<< c << ":" << endl;
        for(int i = 0 ; i < n ; i++){
            cin >> s[i].number >> s[i].name >> s[i].score;
        }
        switch(op){
            case 1:{
                sort(s, s + n, cmp1);
                print_student();
                break;
            }
            case 2:{
                sort(s, s + n, cmp2);
                print_student();
                break;
            }
            case 3:{
                sort(s, s + n, cmp3);
                print_student();
                break;
            }
        }

        c++;

    }
    return 0;
}
