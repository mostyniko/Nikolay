#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > tree; 
vector<int> traverse;
vector<int> sz;
vector<int> pos;

void dfs(int v, int p = -1) {
	sz[v] = 1;
	traverse.push_back(v);
	pos[v] = traverse.size() - 1;
	
	for(int u : tree[v]) {
		if(u == p) continue;
		dfs(u, v);
		sz[v] += sz[u];
	}
}

int main() {
	freopen("tree.txt", "r", stdin);
	cin >> n;
	tree.resize(n);
	sz.resize(n);
	pos.resize(n);
	for(int i = 0; i < n-1; i++) {
		int f, t;
		cin >> f >> t;
		f--; t--;
		tree[f].push_back(t);
		tree[t].push_back(f);
	}
	
	
	Query to subtree with root x can be defined as query to subsegment pos[x]..pos[x]+sz[x]
}
