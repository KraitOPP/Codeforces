#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
#define pii pair<int,int>
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    vector<pair<int,int>> b(n);
    for(int i=0;i<n;i++){
        string s;
        int st;
        cin>>s>>st;
        if(s=="ATK") b[i] = {1,st};
        else b[i] = {0,st};
    }
    for(int i=0;i<m;i++) cin>>a[i];
    sort(a.begin(),a.end(), greater<int>());
    sort(b.begin(),b.end(), [&](pii a, pii b){
        if(a.first==b.first) return a.second < b.second;
        return a.first > b.first;
    });

    int ans=0;
    for(int i=0;i<min(n,m);i++){
        if(!b[i].first || a[i]<b[i].second) break;
        ans+=a[i]-b[i].second;
    }

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    vi done(m,0);
    int ans2=0;
    for(int i=0;i<n;i++){
        bool f=false;

        for(int j=0;j<m;j++){
            if(done[j]) continue;
            if((!b[i].first && a[j]>b[i].second) || (b[i].first && a[j]>=b[i].second)){
                done[j]=1;
                f=true;
                if(b[i].first){
                    ans2+=a[j]-b[i].second;
                }
                break;
            }
        }

        if(!f){
            cout<<ans<<endl;
            return 0;
        }
    }

    for(int i=0;i<m;i++){
        if(!done[i]) ans2+=a[i];
    }

    cout<<max(ans,ans2)<<endl;

    return 0;
}