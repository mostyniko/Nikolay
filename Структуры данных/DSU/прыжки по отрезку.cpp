#include <bits/stdc++.h>
using namespace std;

const int sz = 1e7 + 2;
int e[sz], r[sz], p[sz], ans[sz], n, q;

void init() {
	for(int i = 1; i <= n; i++) {
		r[i] = 1;
		p[i] = e[i] = i;
	}
}

int find_set(int x) {
	if(x == p[x]) return x;
	else return p[x] = find_set(p[x]);
}

void union_sets(int a, int b) {
	a = find_set(a); b = find_set(b);
	if(a == b) return;
	
	if(r[a] > r[b]) swap(a, b);
	p[a] = b;
	r[b] += r[a];
}



void process(int l, int r, int c) {
	int START = l;
	while(true) {
		int& END = e[find_set(START)];
		if(END > r) return;
		ans[END] = c;
		union_sets(START, END);
		END = e[find_set(END + 1)];
		// END+1 is closest uncolored idx after processing END, but information is situated in find_set(END+1).
	}
}

struct query {
	int l, r, c;
};

vector<query> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> q;
	init();
	v.resize(q);
	for(int i = 0; i < q; i++) {
		cin >> v[i].l >> v[i].r >> v[i].c;
	}
	reverse(v.begin(), v.end());
	
	for(int i = 0; i < q; i++) {
		process(v[i].l, v[i].r, v[i].c);
	}
	
	for(int i = 1; i <= n; i++) cout << ans[i];
}
