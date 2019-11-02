#include <bits/stdc++.h>
#define inf 1e18 + 5
using namespace std;

typedef long long ll;
const ll maxV = 1e5 + 5, maxE = maxV * 4;
ll V, E, start, c;
ll dist[maxV], last[maxV], previous[maxE], EdgeStart[maxE], EdgeFinish[maxE];
ll path[maxV];
queue<ll> q;

void add(ll from, ll to)
{
	previous[++c] = last[from]; last[from] = c;
	EdgeStart[c] = from; EdgeFinish[c] = to;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	setlocale(LC_ALL, "Rus");
	freopen("input.txt", "r", stdin);
	cin >> V >> E >> start;
	for(int i = 1; i <= V; i++) dist[i] = inf;
	dist[start] = 0;
	for(int i = 0; i < E; i++)
	{
		ll from, to;
		cin >> from >> to;
		add(from, to);
		add(to, from);
	}
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
			path[EdgeFinish[i]] = current;
			q.push(EdgeFinish[i]);
		}
	}
	}
	
	for(ll i = 1; i <= V; i++)
	{
		if(dist[i] != inf)
		{
			cout << "Растояние до вершины  " << i << " равно " << dist[i] << endl;
			string way = to_string(i);
			for(ll j = path[i]; j; j = path[j]) way = to_string(j) + "->" + way;
			cout << "Путь: " << way << endl;
		} else cout << "До вершины " << i << " невозможно добраться" << endl;
	}
}
