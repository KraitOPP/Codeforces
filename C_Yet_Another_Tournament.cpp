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
        auto begin = chrono::high_resolution_clock::now();
        int n,k;
        cin>>n>>k;
        vpii a(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i].first=x;
            a[i].second=i;
        }
        sort(a.begin(),a.end());
        int i=0, sum=0;
        while(i<n && sum+a[i].first<=k){
            sum+=a[i].first;
            i++;
        }
        if(i==0){
            cout<<n+1<<endl;
            continue;
        }
        else if(i==n){
            cout<<1<<endl;
            continue;
        }
        int idx=-1;
        for(int j=0;j<n;j++){
            if(a[j].second==i){
                idx=j;
                break;
            }
        }
        if((sum+a[idx].first-a[i-1].first)<=k) cout<<n-i<<endl;
        else cout<<n-i+1<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}