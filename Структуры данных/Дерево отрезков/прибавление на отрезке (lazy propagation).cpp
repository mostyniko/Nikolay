#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxN = 1e5 + 1;
int a[maxN];
ll t[maxN*4], temp[maxN*4];

void push(int v, int tl, int tr) {
	if(temp[v]) {
		t[v] += temp[v] * (tr - tl + 1);
		int TEMP = temp[v]; temp[v] = 0;
		if(v*2+1 >= maxN * 4) return;
		temp[v*2] += TEMP; temp[v*2+1] += TEMP;
	}
}

void build(int v, int tl, int tr) {
	if(tl == tr) {
		t[v] = a[tl];
		return;
	}
	
	int m = (tl + tr) / 2;
	build(v*2, tl, m); build(v*2+1, m+1, tr);
	t[v] = t[v*2] + t[v*2+1];
}

void update(int v, int tl, int tr, int l, int r, int val) {
	push(v, tl, tr);
	if(l > r) return;
	if(l == tl && r == tr) {
		temp[v] += val;
		push(v, tl, tr);
		return;
	}
	
	int m = (tl + tr) / 2;
	update(v*2, tl, m, l, min(r, m), val);
	update(v*2+1, m+1, tr, max(l, m+1), r, val);
	t[v] = t[v*2] + t[v*2+1];
}

ll get_sum(int v, int tl, int tr, int l, int r) {
	push(v, tl, tr);
	if(l > r) return 0;
	if(l == tl && r == tr) return t[v];
	
	int m = (tl + tr) / 2;
	return get_sum(v*2, tl, m, l, min(r,m)) + get_sum(v*2+1, m+1, tr, max(l, m+1), r);
}

int main() {
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
	build(1, 0, n-1);
	
	while(q--) {
		int type;
		cin >> type;
		
		if(type == 1) {
			// Modify
			int l, r, val;
			cin >> l >> r >> val;
			l--; r--;
			update(1, 0, n-1, l, r, val);
		}
		
		if(type == 2) {
			int l, r;
			cin >> l >> r;
			l--; r--;
			cout << get_sum(1, 0, n-1, l, r) << endl;
		}
	}
}
