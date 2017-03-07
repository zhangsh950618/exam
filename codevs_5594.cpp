#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
string st;
struct Node{
    double a;
    double b;
    double c;
};

Node solve(string s){



}
int main(){

    while(cin >> st){
        int found = st.find("=");
        cout << "has found" << found << endl;
        string left = st.substr(0, found);
        string right = st.substr(found + 1);
        cout << left << " " << right << endl;

        Node l = solve(left);
        Node r = solve(right);
        double a = l.a - r.a;
        double b = l.b - r.b;
        double c = l.c - r.c;
        double d = pow(b, 2) - 4 * a * c;
        if(a == 0) cout << "MATH ERROR" << endl;
        else if(d < 0) cout << "No Answer" << endl;
        else{
            double x1 = (-b + sqrt(d))/ 2 * a;
            double x2 = (-b - sqrt(d)) / 2 * a;


        }
    }
    return 0;
}
