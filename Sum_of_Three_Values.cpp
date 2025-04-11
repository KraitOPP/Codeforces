#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

void solve(){
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        int rq = x-a[i].first;
        int s=i+1,e=n-1;
        while(s<e){
            int sum=a[s].first+a[e].first;
            if(sum==rq){
                cout<<a[i].second+1<<" "<<a[s].second+1<<" "<<a[e].second+1<<endl;
                return;
            }
            else if(sum<rq) s++;
            else e--;
        }
    }

    cout<<"IMPOSSIBLE"<<endl;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}