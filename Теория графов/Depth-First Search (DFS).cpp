#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;
const ll maxV = 1e5 + 1, maxE = maxV * 4;
ll last[maxV], previous[maxE], used[maxV];
ll EdgeStart[maxE], EdgeFinish[maxE];
ll V, E, startV, c;

void add(ll from, ll to)
{
	previous[++c] = last[from]; last[from] = c;
	EdgeStart[c] = from; EdgeFinish[c] = to;
}

void DFS(ll currentPos)
{
	used[currentPos] = true;
	for(ll i = last[currentPos]; i; i = previous[i]) {
	if(!used[EdgeFinish[i]]) DFS(EdgeFinish[i]);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	std::ios_base::sync_with_stdio(false);
	setlocale(LC_ALL, "Rus");
	cin >> V >> E >> startV;
	for(ll i = 0; i < E; i++)
	{
		ll from, to;
		cin >> from >> to;
		add(from, to);
		add(to, from);
	}
	DFS(startV);
	for(ll i = 1; i <= V; i++)
	{
		if(used[i]) cout << "There is way to vertex " << i << endl;
		else cout << "No way to vertex " << i << endl;
	}
}
