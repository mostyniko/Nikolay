#include <bits/stdc++.h>
using namespace std;

// kruskal using DSU.

int p[200001];
int rk[200001];

void init_dsu(int n) {
	for(int i = 0; i < n; i++) {
		p[i] = i;
		rk[i] = 1;
	}
}

int find_set(int a) {
	if(p[a] == a) return a;
	else return p[a] = find_set(p[a]);
}

void union_sets(int a, int b) {
	a = find_set(a); b = find_set(b);
	if(a == b) return;
	
	if(rk[a] > rk[b]) swap(a, b);
	p[a] = b;
	rk[b] += rk[a];
}

vector<pair<int, pair<int, int> > > edge;
long long totalWeight = 0;

int main() {
	freopen("input1.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	init_dsu(n);
	
	
	for(int i = 0; i < m; i++) {
		int f, t, c;
		cin >> f >> t >> c;
		f--; t--;
		edge.push_back({c, {f, t}});		
	}
	
	cout << "ok da" << endl;
	
	sort(edge.begin(), edge.end());
	for(int i = 0; i < m; i++) {
		int a = edge[i].second.first, b = edge[i].second.second, l = edge[i].first;
		if(find_set(a) != find_set(b)) {
			union_sets(a, b);
			totalWeight += l;
		}
	}
	
	cout << totalWeight << endl;
}
