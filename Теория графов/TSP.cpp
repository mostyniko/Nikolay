// Travelling salesman problem on directed weighted graph

#include <bits/stdc++.h>
#define int long long
using namespace std;

int cost[20][20];
int n, m;
int dp[1 << 20][20];

signed main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) cost[i][j] = 0; 
			else cost[i][j] = 1e18+7;
		}
	}
	
	for(int i = 0; i < m; i++) {
		int f, t, c;
		cin >> f >> t >> c;
		f--, t--;
		cost[f][t] = c;
		cost[t][f] = c;
	}
	
	for(int i = 0; i < (1 << n); i++) {
		for(int j = 0; j < n; j++) {
			dp[i][j] = 1e18+7;
		}
	}
	
	dp[1][0] = 0;
	for(int mask = 2; mask < (1 << n); mask++) {
		for(int i = 0; i < n; i++) {
			if(mask & (1 << i)) {
				int M = mask^(1 << i);
				for(int j = 0; j < n; j++) {
					if(j != i && (M & (1 << j))) {
						dp[mask][i] = min(dp[mask][i], dp[M][j] + cost[j][i]);
					}
				}
			}
		}
	}
	
	int ans = 1e18+7;
	for(int i = 0; i < n; i++) {
		ans = min(ans, dp[(1 << n) - 1][i] + cost[i][0]);
	}
	
	if(ans >= 1e18+7) {
		cout << "No gamilton cycle" << endl;
	} else {
		cout << "MinDist = " << ans << endl;
	}
}
