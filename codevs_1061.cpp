#include<iostream>
#include<cstdio>
#define rep(i,n) for(int i = 0;i < n; i++)
using namespace std;
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
int sa_start = INF;
bool check(int k,int len){
    int sa_min = sa[1], sa_max = sa[1];
    int flag = false;
    for(int i = 2 ; i <= len ; i++){
        if(height[i] >= k){

           sa_min = min(sa[i], sa_min);
           sa_max = max(sa[i], sa_max);
           if(sa_max - sa_min > k){
                flag = true;
                sa_start = min(sa_start, sa_min);
           }
        }else{


            sa_min = sa[i];
            sa_max = sa[i];
        }



    }
    if(flag) return true;
    return false;
}
string s1, s2, s;
int main(){
    while(cin >>s){
        int len = s.length();
        getSuffix(s);
        int l = 0, h = s.length() / 2, mid = (l + h) / 2;
        while(l <= h){
            mid = (l + h) / 2;
            if(check(mid, len)) l = mid + 1;
            else h = mid - 1;
        }
        if(mid == 0) cout << "NO" << endl;
        else cout << s.substr(sa_start, mid) << endl;
    }
    return 0;
}
