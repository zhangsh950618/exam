#include <iostream>
#include  <string.h>
using namespace std;

char st[1000], stack[1000], ls;
int a[1000], la;

void init() {
    int len = strlen(st);
    if (st[0]<'0' || st[0]>'9') {
        for (int i=len; i>=1; i--) st[i] = st[i-1];
        st[0] = '0';
    }
    la = ls = 0;
    st[len++] = '#';
    st[len] = 0;
}

int prior() {
    if (ls <= 1) return 0;
    if (stack[ls-1] == '#') return 1;
    if ((stack[ls-1] == '+' || stack[ls-1] == '-') && (stack[ls-2] == '+' || stack[ls-2] == '-')) return 1;
    if ((stack[ls-1] == '*' || stack[ls-1] == '/') && (stack[ls-2] == '*' || stack[ls-2] == '/')) return 1;
    if ((stack[ls-1] == '+' || stack[ls-1] == '-') && (stack[ls-2] == '*' || stack[ls-2] == '/')) return 1;
    return 0;
}

void calculate() {
    switch (stack[ls - 2]) {
        case '+' : a[la-2] = a[la-2] + a[la-1]; break;
        case '-' : a[la-2] = a[la-2] - a[la-1]; break;
        case '*' : a[la-2] = a[la-2] * a[la-1]; break;
        case '/' : a[la-2] = a[la-2] / a[la-1]; break;
    }
    stack[ls - 2] = stack[ls - 1];
    ls--;
    la--;
}

int main() {
    while (cin >> st) {
        init();

        int i = 0;
        while (st[i]) {
            if (st[i]>='0' && st[i]<='9') {
                int j = 0;
                while (st[i]>='0' && st[i]<='9') j = j*10+st[i++]-'0';
                //操作数栈
                a[la++] = j;
            } else {
                //操作符栈
                stack[ls++] = st[i++];
                while (prior()) calculate();
            }
        }
        while (prior()) calculate();

        cout << a[0] << endl;
    }
}
