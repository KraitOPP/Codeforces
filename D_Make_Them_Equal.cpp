#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned int ull;
typedef long double lld;
 
/*---------------------------------------------------------------------------------------------------------------------------------------------*/
#ifdef ONLINE_JUDGE
#define debug(x)
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#else
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#endif
#define maxim(l) *max_element(l.begin(),l.end())
#define minim(l) *min_element(l.begin(),l.end())
#define sum(l) accumulate(l.begin(),l.end(),0ll)
#define vsort(l) sort(l.begin(),l.end())
#define revs(l) sort(l.rbegin(),l.rend())
#define pb push_back
#define int long long
#define mk make_pair
#define in(a) for(int i=0;i<a.size();i++) cin>>a[i];
#define out(a) for(int i=0;i<a.size();i++) cout<<a[i]<<" "
#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<ll>
#define vvi vector<vi>
#define pll pair<ll, ll>
#define vp vector<pll>
#define INF 1e18
#define endl "\n"
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define all(x) (x).begin(), (x).end()
 
const ll MOD = 1e9 + 7;

int solveRec(vi &b, vi &pri, vi &cost, int i, int k, vector<vi> &dp){
    if(i<0) return 0;
    if(dp[i][k]!=-1) return dp[i][k];

    //not take
    int ans = solveRec(b, pri, cost, i-1, k, dp);
    //take
    if(cost[b[i]]<=k) ans = max(ans,pri[i] + solveRec(b, pri, cost, i-1, k-cost[b[i]], dp));

    return dp[i][k] = ans;
}

int solveTab(vi &b, vi &pri, vi &cost, int n, int k){
    vector<vi> dp(n+1, vi(k+1));
    //Base Case
    for(int i=0;i<=k;i++) dp[0][i]=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j] = dp[i-1][j];
            if((j-cost[b[i]])>=0) dp[i][j] = max(dp[i][j], pri[i] + dp[i-1][j-cost[b[i]]]);
        }
    }

    return dp[n][k];
}


signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vi costs(1001,INT_MAX);
    costs[1]=0;
    int N=1001;
    for (int i=1; i<N; i++){
        for (int x=1; x<=i; x++){
            int j=i+i/x;
            if (j<N) costs[j] = min(costs[j], costs[i] + 1);
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> b(n+1),c(n+1);
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++) cin>>c[i];
        k=min(k,12*n);

        cout<<solveTab(b, c, costs, n, k)<<endl;
    }
    return 0;
}