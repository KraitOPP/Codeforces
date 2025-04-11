#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define ff first
#define ss second
#define MOD 1000000007

void magin() {
	int dd , mm , yy;
	cin >> dd >> mm >> yy;
	yy -= 18;
	int n; cin >> n;
	vector<pair<pair<int , int> , int>> child(n);
	for(int i = 0 ; i < n; i++)
		cin >> child[i].ff.ff >> child[i].ff.ss >> child[i].ss;

	vector<pair<pair<int , int> , int>> child2 = child;
	sort(child.begin() , child.end() , [&](pair<pair<int,int>, int> a, pair<pair<int,int>,int> b){
		if(a.second==b.second){
			if(a.first.second==b.first.second) return a.first.first > b.first.first;

			return a.first.second > b.first.second;
		}
		return a.second > b.second;
	});

	vector<pair<pair<int , int> , int>> ans;
	for(int i = 0; i < n; i++)
	{
		int d = child[i].ff.ff; int m = child[i].ff.ss;
		int y = child[i].ss;

		if(y < yy || (y == yy && (m < mm || (m == mm && d <= dd))))
		{
			ans.push_back({{d , m} , y});
			break;
		}
	}

	if(ans.size() == 0)
		cout << -1 << endl;
	else
	{
		for(int i = 0; i < n; i++)
		{
			if(ans[0].ff.ff == child2[i].ff.ff && ans[0].ff.ss == child2[i].ff.ss && ans[0].ss == child2[i].ss)
			{
				cout << i + 1 << endl;
				break;
			}
		}
	}
}

signed main() {
    freopen("king.in", "r", stdin);
    freopen("king.out", "w", stdout);

	// int t;
	// cin >> t;
	// while(t--) {
		magin();
	// }
	return 0;
}