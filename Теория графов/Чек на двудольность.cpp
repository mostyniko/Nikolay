#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 2;
vector<vector<int> > g;
int color[maxN];
int n, m;

int main() {
	freopen("i.txt", "r", stdin);
	cin >> n >> m;
	memset(color, -1, sizeof(color));
	g.resize(n+2);
	for(int i = 0; i < m; i++) {
		int f, t;
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	
	bool bipartite = true;
	for(int i = 1; i <= n; i++) {
		if(color[i] == -1) {
			queue<int> q;
			q.push(i);
			while(!q.empty()) {
				int cur = q.front();
				q.pop();
				if(color[cur] == -1) color[cur] = 0;
				for(int j : g[cur]) {
					if(color[j] == -1) {
						color[j] = !color[cur];
						q.push(j);
					}
					else if(color[j] == color[cur]) bipartite = false;
				}
			}
		}
	}
	
	if(bipartite) cout << "YES" << endl;
	else cout << "NO" << endl;
}
