#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <queue>

using namespace std;

typedef long long LL;
typedef vector<int> vi;

const int MaxN = 100000;
vi g[MaxN+5];
int dist[MaxN+5];
int prv[MaxN+5];

int getMaxDepth(queue<int> &q)
{
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		int d = dist[v] + 1;
		for (int u : g[v])
			if (u != prv[v])
				if (dist[u]!=-1)
				{
					return d - 1;
				}
				else
				{
					dist[u] = d;
					q.push(u);
					prv[u] = v;
				}
	}
	
	return MaxN;
}

int main() {
	
	int n,m,k;
	cin >> n >> m >> k;
	
	for (int i = 0; i <= n; i++)
	{
		dist[i] = -1;
		prv[i] = -1;
	}
	
	int u,v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	queue<int> q;
	for (int i = 0; i < k; i++)
	{
		cin >> v;
		q.push(v);
		dist[v] = 0;
	}
	
	
	int maxD = getMaxDepth(q);
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (dist[i] >= 0 && dist[i] <= maxD)
			ans++;
	
	cout << ans << endl;
	
	return 0;
}