#include <bits/stdc++.h>
using namespace std;

int query(int u, int v)
{
	cout << "? " << u << " " << v << endl;
	cout.flush();
	int ans;
	cin >> ans;
	return ans;
}

void dfs(int u, int v, vector<bool> &vis, vector<int> &parent)
{
	int x = query(u, v);
	if (x == u || x == v)
	{
		parent[v] = u;
		vis[v] = true;
		return;
	}

	if (!vis[x])
	{
		dfs(u, x, vis, parent);
	}

	dfs(x, v, vis, parent);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<bool> vis(n + 1, false);
		vector<int> parent(n + 1);
		vis[1] = true;

		for (int i = 2; i <= n; i++)
		{
			if (!vis[i]){
				dfs(1, i, vis, parent);
			}
		}

		cout << "! ";
		for (int i = 2; i <= n; i++)
		{
			cout << i << " " << parent[i] << " ";
		}
		cout << endl;
	}
}

