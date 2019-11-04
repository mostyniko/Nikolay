#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxV = 1e5 + 5, maxE = maxV * 4;
ll V, E, c;
ll last[maxV], previous[maxE], EdgeStart[maxE], EdgeFinish[maxE];
bool used[maxV], cycles;

void add(ll from, ll to)
{
	previous[++c] = last[from]; last[from] = c;
	EdgeStart[c] = from; EdgeFinish[c] = to;
}

void DFS(ll currentV, ll predok)
{
	used[currentV] = true;
	for(ll i = last[currentV]; i; i = previous[i]) {
		if(!used[EdgeFinish[i]]) DFS(EdgeFinish[i], currentV);
		else if(EdgeFinish[i] != predok) cycles = true;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	std::ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	
	cin >> V >> E;
	for(ll i = 0; i < E; i++)
	{
		ll from, to;
		cin >> from >> to;
		add(from, to);
		add(to, from);
	}
	
	DFS(1, -1);
	if(cycles) cout << "There is minimum one cycle!";
	else cout << "No cycles";
}
