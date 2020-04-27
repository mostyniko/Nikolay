// negative cycle
/* We can find negative cycle using Floyd-Warshall
   just relaxing N times our edges. So algorithm says that we will have valid distances after N-1 relaxations,
   so if N relaxation can make result better, we have negative cycle.
*/

#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9+7;
int es[200001], ef[200001];
int c = -1;
int cost[200001];
int n, m;
int dist[200001];
int p[200001];


int main() {
	freopen("graph.txt", "r", stdin);
	for(int i = 0; i < 200001; i++) dist[i] = inf;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> es[i] >> ef[i] >> cost[i];
	}
	
	dist[1] = 0;
	for(int i = 0; i < n-1; i++) {
		bool flag = false;
		for(int j = 0; j < m; j++) {
			if(dist[ef[j]] > dist[es[j]] + cost[j]) {
				flag = true;
				dist[ef[j]] = dist[es[j]] + cost[j];
				p[ef[j]] = es[j];
			}
		}
		if(!flag) {
			cout << "bad " << i << endl;
			break;
		}
	}
	
	int x = -1;
	for(int j = 0; j < m; j++) {
		if(dist[ef[j]] > dist[es[j]] + cost[j]) {
				p[ef[j]] = es[j];
				x = ef[j];
				break;
			}
	}
	
	if(x == -1) cout << "No negative cycle";
	else {
		vector<int> path;
		
		path.push_back(x);
		int start = x;
		x = p[x];
		while(x != start) {
			path.push_back(x);
			x = p[x];
		}
		cout << "Cycle: ";
		reverse(path.begin(), path.end());
		for(int i = 0; i < path.size(); i++) cout << path[i] << " ";
	}
}
