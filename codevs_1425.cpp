#include<fstream>
#include<iostream>
#include<cstdio>
#include<cstring>
#define rep(i,n) for(int i = 0;i < n; i++)
using namespace std;
ifstream fin("1.in");
const int size  = 200005,INF = 1<<30;
int rk[size],sa[size],height[size],w[size],wa[size],res[size];
void getSa (int len,int up) {
	int *k = rk,*id = height,*r = res, *cnt = wa;
	rep(i,up) cnt[i] = 0;
	rep(i,len) cnt[k[i] = w[i]]++;
	rep(i,up) cnt[i+1] += cnt[i];
	for(int i = len - 1; i >= 0; i--) {
		sa[--cnt[k[i]]] = i;
	}
	int d = 1,p = 0;
	while(p < len){
		for(int i = len - d; i < len; i++) id[p++] = i;
		rep(i,len)	if(sa[i] >= d) id[p++] = sa[i] - d;
		rep(i,len) r[i] = k[id[i]];
		rep(i,up) cnt[i] = 0;
		rep(i,len) cnt[r[i]]++;
		rep(i,up) cnt[i+1] += cnt[i];
		for(int i = len - 1; i >= 0; i--) {
			sa[--cnt[r[i]]] = id[i];
		}
		swap(k,r);
		p = 0;
		k[sa[0]] = p++;
		rep(i,len-1) {
			if(sa[i]+d < len && sa[i+1]+d <len &&r[sa[i]] == r[sa[i+1]]&& r[sa[i]+d] == r[sa[i+1]+d])
				k[sa[i+1]] = p - 1;
			else k[sa[i+1]] = p++;
		}
		if(p >= len) return ;
		d *= 2,up = p, p = 0;
	}
}
void getHeight(int len) {
	rep(i,len) rk[sa[i]] = i;
	height[0] =  0;
	for(int i = 0,p = 0; i < len - 1; i++) {
		int j = sa[rk[i]-1];
		while(i+p < len&& j+p < len&& w[i+p] == w[j+p]) {
			p++;
		}
		height[rk[i]] = p;
		p = max(0,p - 1);
	}
}
int getSuffix(string s) {
	int len = s.length(),up = 0;
	for(int i = 0; i < len; i++) {
		w[i] = s[i];
		up = max(up,w[i]);
	}
	w[len++] = 0;
	getSa(len,up+1);
	getHeight(len);
	return len;
}
string s,temp;
int n,t;
int len[size];
int sa_start = INF;
bool check(int k, int l){
    bool mark[size];
    memset(mark, false, sizeof(mark));
    int sum = 0;
    for(int i = 1 ; i <= l ; i++){
        if(height[i] < k){
            memset(mark, false, sizeof(mark));
            sum  = 0;
        }
        int j;
        for(j = 0 ; j < t ; j++){
            if(len[j] > sa[i]) break;
        }
        //not specail word

//        cout << "j = " << j << endl;
        if(j != t){
            if(!mark[j]){
                mark[j] = true;
                sum ++;
                if(sum == t){

                    sa_start = min(sa_start, sa[i]);
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    while(fin >> n){
        t = 0;
        fin >> s;
        len[t++] = s.length();
        int l = 0, h = s.length();
        for(int i = 1 ;i < n ;i++){
            fin >> temp;
            int n = temp.length();
            h = min(n, h);
            s += (char)(i + '0') + temp;
            len[t++] = temp.length();
        }
        getSuffix(s);

//        for(int i = 1 ; i < s.length() ; i++)
//        cout << s.substr(sa[i]) << " " << height[i] <<  endl;
        for(int i = 1 ; i < t ; i++) len[i] += len[i - 1] + 1;
//        for(int i = 0 ; i < t ; i++) cout << len[i] << endl;
//        cout << "h = " << h << "l = " << l << endl;
        int mid = (l + h) / 2;
        cout << "mid = " << mid << endl;
        cout << "h = " << h << endl;
        while(l < h){
            mid = (l + h) / 2;
//            cout << "mid = " << mid << endl;
            if(check(mid, s.length())){ l = mid;}
            else h = mid - 1;
        }
//        cout << "sa_start = " << sa_start << "  mid = " << mid << endl;
        if(mid) cout << s.substr(sa_start, l) << endl;
    }
}

