#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
int timer = 0;
int tin[200001], fup[200001];
bool used[200001];

void dfs(int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = ++timer;
	
	for(int u : g[v]) {
		if(u == p) continue;
		
		if(used[u]) {
			fup[v] = min(fup[v], fup[u]);
		} else {
			dfs(u, v);
			fup[v] = min(fup[v], fup[u]);
			if(tin[v] <= fup[u]) cout << "bridge = " << v+1 << "->" << u+1 << endl;
		}
	}
}

int main() {
	freopen("input1.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	g.resize(n);
	for(int i = 0; i < m; i++) {
		int f, t;
		cin >> f >> t, f--, t--;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	
	for(int i = 0; i < n; i++) {
		if(!used[i]) dfs(i);
	}
}
