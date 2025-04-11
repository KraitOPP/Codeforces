#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        vector<set<int>> st(n);
        for(int i=0;i<n;i++){
            st[i].insert((i-1+n)%n);
            st[i].insert((i+1)%n);
        }

        vi res(n,-1);
        if(y!=(x+1)%n){
            st[x-1].insert(y-1);
            st[y-1].insert(x-1);
        }

        for(int i=0;i<n;i++){
            if(res[i]!=-1) continue;
            set<int> s;
            for(auto x:st[i]){
                if(res[x]!=-1) s.insert(res[x]);
            }
            int curr=0;
            for(auto x:s){
                if(x==curr) curr++;
                else break;
            }
            res[i]=curr;
        }
        for(int i=0;i<n;i++) cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}