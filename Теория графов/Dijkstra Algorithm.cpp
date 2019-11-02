#include <bits/stdc++.h>
#define inf 1e18 + 1
using namespace std;

typedef long long ll;
const ll maxV = 1e5 + 1, maxE = maxV * 2;
typedef pair<ll, ll> p;
ll last[maxV], previous[maxE], dist[maxV], EdgeStart[maxE], EdgeFinish[maxE], EdgeValue[maxE], c;
priority_queue<p, vector<p>, greater<p> > q;
ll V, E, startV;

void add(ll start, ll finish, ll value)
{
	previous[++c] = last[start]; last[start] = c;
	EdgeStart[c] = start; EdgeFinish[c] = finish; EdgeValue[c] = value;
}

int main()
{
	freopen("input.txt", "r", stdin);
	std::ios_base::sync_with_stdio(false);
	setlocale(LC_ALL, "Rus");
	
	cin >> V >> E >> startV;
	for(int i = 1; i <= V; i++) dist[i] = inf;
	dist[startV] = 0;
	q.push(make_pair(0, startV));
	for(int i = 0; i < E; i++)
	{
		ll from, to, value;
		cin >> from >> to >> value;
		add(from, to, value);
	}
	
	
	while(!q.empty())
	{
		ll currentDist = q.top().first, currentV = q.top().second;
		q.pop();
		
		if(currentDist > dist[currentV]) continue;
		for(ll i = last[currentV]; i; i = previous[i])
		{
			if(currentDist + EdgeValue[i] < dist[EdgeFinish[i]])
			{
				dist[EdgeFinish[i]] = currentDist + EdgeValue[i];
				q.push(make_pair(dist[EdgeFinish[i]], EdgeFinish[i]));
			}
		}
	}
	
	for(int i = 1; i <= V; i++) cout << "Расстояние до вершины " << i << " равно " << dist[i] << endl;
}

