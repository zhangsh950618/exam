#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int l2, l1, l0, r2, r1, r0, a, b, c;
char st[1000];

void cal(char *st, int &p2, int &p1, int &p0) {
	p2 = p1 = p0 =0;
	int l = 0, r, flag=1;
	if (st[0] == '-') {
		l = 1; flag = -1;
	}
	while (1) {
		r = l+1;
		while (st[r]!='+' && st[r]!='-' && st[r]!=0) r++;

		int x = l;
		while (x<r && st[x] != 'x') x++;

		int p = 0;
		for (int i=l; i<x; i++) p = p*10+st[i]-'0';
		if (l == x) p = 1;

		if (x == r) p0 += flag*p;
		else if (st[x+1] == '^') p2 += flag*p;
		else p1 += flag*p;

		l = r+1;

		if (st[r] == 0) break;
		else if (st[r] == '+') flag = 1;
		else flag = -1;
	}
}

int main() {

	cout << fixed << setprecision(2);

	while (cin >> st) {

		int mid = 0;
		while (st[mid] != '=') mid++;
		st[mid] = 0;

		cal(st, l2, l1, l0);
		cal(st+mid+1, r2, r1, r0);

		a = l2-r2;
		b = l1-r1;
		c = l0-r0;

		if (a == 0) {
			if (b==0) cout << "No Solution" << endl;
			else cout << -c/b << ' ' << -c/b << endl;
		} else  {
			if (b*b < 4*a*c) cout << "No Solution" << endl;
			else {
				double t = sqrt(b*b-4*a*c);
				double a1 = (-b-t)/(2*a), a2 = (-b+t)/(2*a);
				if (a1 > a2) {
					double a3 = a1; a1 = a2; a2 = a3;
				}
				if (a1 == 0) a1 = 0.0;
				if (a2 == 0) a2 = 0.0;
				cout << a1 << ' ' << a2 << endl;
			}
		}
	}
}
