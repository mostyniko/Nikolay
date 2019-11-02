#include <bits/stdc++.h>
using namespace std;

//E - ð¸áðà, V - âåðøèíû
typedef long long ll;
const ll maxV = 1e5 + 5, maxE = maxV * 4;
const bool focus = true;
const bool weighted = false;
ll last[maxV], previous[maxE], EdgeStart[maxE], EdgeFinish[maxE], EdgeWeight[maxE];
ll dist[maxV], c;
ll V, E;

void add(ll from, ll to, ll weight)
{
	previous[++c] = last[from]; last[from] = c;         
	EdgeStart[c] = from; EdgeFinish[c] = to; EdgeWeight[c] = weight;
}

void add(ll from, ll to)
{
	previous[++c] = last[from]; last[from] = c;
	EdgeStart[c] = from; EdgeFinish[c] = to;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	std::ios_base::sync_with_stdio(false);
	
	cin >> V >> E;
	for(ll i = 0; i < E; i++)
	{
		ll start, finish;
		cin >> start >> finish;
		if(weighted)
		{
			ll weight;
			cin >> weight;
			add(start, finish, weight);
			if(!focus) add(finish, start, weight);
		} else
		{
			add(start, finish);
			if(!focus) add(finish, start);
		}
	}
	
	for(ll i = 1; i <= V; i++)
	{
		cout << "Ребрышки, выходящие из вершины " << i << ": " << endl;
		for(ll j = last[i]; j; j = previous[j])
		{
			cout << i << "->" << EdgeFinish[j];
			if(weighted) cout << " [" << EdgeWeight[j] << "]";
			cout << endl;	
		}	
	}	
}


