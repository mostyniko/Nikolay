// LCA (binary ups). Log for query + N log N for preprocessing.

#include <bits/stdc++.h>
using namespace std;

vector<int> tin, tout;
vector<vector<int> > g;
int timer, l;
vector<vector<int> > up;
int n;

bool upper(int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

void dfs(int v, int p = 0) {
	tin[v] = ++timer;
	up[v][0] = p;
	for(int i = 1; i < l; i++) {
		up[v][i] = up[up[v][i-1]][i-1];
	}
	
	for(int u : g[v]) {
		if(u == p) continue;
		dfs(u, v);
	}
	
	tout[v] = ++timer;
}

int lca(int a, int b) {
	if(upper(a, b)) return a;
	if(upper(b, a)) return b;
	
	for(int i = l-1; i >= 0; i--) {
		if(!upper(up[a][i], b))
			a = up[a][i];
	}
	return up[a][0];
}

int main() {
	freopen("tree.txt", "r", stdin);
	cin >> n;
	g.resize(n);
	up.resize(n);
	tin.resize(n);
	tout.resize(n);
	while((1 << l) <= 4*n) l++;
	for(int i = 0; i < n; i++) {
		up[i].resize(l);
	}
	
	for(int i = 0; i < n-1; i++) {
		int f, t;
		cin >> f >> t;
		f--; t--;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	
	dfs(0);
	
	int q;
	cin >> q;
	while(q--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		cout << lca(a, b)+1 << endl;
	}
}
