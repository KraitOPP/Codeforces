#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("shuffle.in", "r", stdin);
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> vis(n+1,-1);
    int res=0;
    for(int i=1;i<=n;i++){
        if(vis[i]!=-1) continue;
        int curr=i;
        while(vis[curr]==-1){
            vis[curr]=i;
            curr=a[curr];
        }

        if(vis[curr]==i){
            int tmp=curr;
            do{
                res++;
                tmp=a[tmp];
            } while(tmp!=curr);
        }
    }
    freopen("shuffle.out", "w", stdout);

    cout<<res<<endl;

    return 0;
}