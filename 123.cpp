#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <algorithm>
#include<string.h>
using namespace std;

const int N = 110;

string s1,s2;
int f[N][N];

int main()
{
    while (cin >> s1 >> s2) {
        memset(f, 0x00, sizeof(f));
        int n = s1.length();
        int m = s2.length();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i] == s2[j]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }

        cout << f[n][m] << endl;
    }
    return 0;
}
/**************************************************************
    Problem: 1042
    User: zhangsh950618
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1568 kb
****************************************************************/
