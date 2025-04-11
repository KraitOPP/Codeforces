#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

long long exp(long long x, long long n, long long m) {
	x %= m; 
	long long res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    vector<pair<int,int>> a(t);
    for(int i=0;i<t;i++) cin>>a[i].first;
    for(int i=0;i<t;i++) cin>>a[i].second;

    for(int i=0;i<t;i++){
        int n=a[i].first;
        int r=a[i].second;
        if(n==r || r==0){
            cout<<1<<endl;
        }
        else{
            cout<<exp(2,r,mod)<<endl;
        }
    }
    return 0;
}