// cycles in unoriented graph

#include <bits/stdc++.h>
using namespace std;

vector<int> g[200001];
int color[200001];
int n, m;
bool flag = false;
enum { WHITE, GREY, BLACK };

void dfs(int v) {
	color[v] = GREY;
	
	for(int u : g[v]) {
		if(color[u] == GREY) {
			flag = true;
			return;
		} else dfs(u);
	}
	
	color[v] = BLACK;
}

int main() {
	freopen("graph.txt", "r", stdin);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int f, t;
		cin >> f >> t;
		
		g[f].push_back(t);
	}
	
	for(int i = 1; i <= n; i++) {
		if(color[i] == WHITE) dfs(i);
	}
	
	if(flag) cout << "There is cycle" << endl;
	else cout << "No cycles";
}
