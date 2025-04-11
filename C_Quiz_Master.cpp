#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;
int maxM = 1e5+10;
vector<vector<int>> fac(maxM);

void fact(){
    for(int i=1;i<=maxM;i++){
        for(int j=i;j<=maxM;j+=i){
            fac[j].push_back(i);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int res=inf;
    int curr=0;
    int i=0;
    map<int,int> freq;

    for(int j=0;j<n;j++){
        for(auto factor: fac[a[j]]){
            if(factor>m) break;
            if(freq[factor]==0) curr++;
            freq[factor]++;
        }
        while(curr==m){
            int nw = a[j]-a[i];
            res=min(res,nw);
            for(auto factor: fac[a[i]]){
                if(factor>m) break;
                freq[factor]--;
                if(freq[factor]==0) curr--;
            }
            i++;
        }
    }

    if(res==inf) cout<<-1<<endl;
    else cout<<res<<endl;

}


signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact();
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        solve();

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}