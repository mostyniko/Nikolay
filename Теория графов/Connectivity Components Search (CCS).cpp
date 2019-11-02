

#include <bits/stdc++.h>
#define inf 1e18 + 5
using namespace std;

typedef long long ll;
const ll maxV = 1e5 + 5, maxE = maxV * 4;
ll V, E, c;
ll dist[maxV], last[maxV], previous[maxE], EdgeStart[maxE], EdgeFinish[maxE];
ll path[maxV];
queue<ll> q;
ll cnt;

void add(ll from, ll to)
{
	previous[++c] = last[from]; last[from] = c;
	EdgeStart[c] = from; EdgeFinish[c] = to;
}

void BFS(ll start)
{
	dist[start] = 0;
	q.push(start);
	while(!q.empty())
	{
		ll current = q.front();
		q.pop();
		for(ll i = last[current]; i; i = previous[i])
		{
			if(dist[current] + 1 < dist[EdgeFinish[i]])
			{
				dist[EdgeFinish[i]] = dist[current] + 1;
				q.push(EdgeFinish[i]);
			}
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	setlocale(LC_ALL, "Rus");
	cin >> V >> E;
	for(ll i = 1; i <= V; i++) dist[i] = inf;
	for(ll i = 0; i < E; i++)
	{
		ll from, to;
		cin >> from >> to;
		add(from, to);
		add(to, from);
	}
	for(ll i = 1; i <= V; i++)
	{
		if(dist[i] == inf)
		{
			BFS(i);
			cnt++;
		}
	}
	cout << cnt;
}
